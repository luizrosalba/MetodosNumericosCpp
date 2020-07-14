
//
// Interpolação Splines Cúbicos com condições Naturais (M[0] = M[N] = 0 )
// Entrada : pontos x e y
// Saida : Arquivo "splinecubnatural.dados"
// Objetivo : Interpola de tres em tres pontos utilizando cubicas
//
//

/*

#include<Splines.h>



void SplineCubNatural(const double *_x , const double *_y , const int &_tamanho)
{

    int n(_tamanho);    // numero de pontos
    int tam=n-2;        // tamanho da matriz a ser resolvida

    double *h,*lambda;  //variaveis necessárias ao metodo
    double *sol;        // matriz solucao , pertence aos sistema do tridiag
    double *a,*b,*c,*d; // coeficientes do spline cubico
    double *lambda2,*meio; // posicoes da matriz tridiag
    double *S;                     // solucao da matriz tridiag
    double saiday;                 // polinomio do spline cubico
    double delta(0.01);     // distancia entre pontos no plot
    double px(_x[0]);          // ponto a ser interpolado no plot
    int k,i,j ; // contadores

//variaveis necessarias ao calculo do spline

    h = new double[n];
    meio = new double[tam];
    lambda = new double[tam];
    lambda2 = new double[tam];
    sol = new double[tam];
    a = new double[n];
    b = new double[n];
    c = new double[n];
    d = new double[n];
//fim

    S = new double[n]; // solucao do spline

    // inicio algoritmo

    //calcula h

    for ( i= 0 ; i < n ; i++) // i = 0 ... n-2
    {
        j=i+1;
        h[i] = _x[j]-_x[i]; //  h[1] = x[1] - x[0] ... // ok
       // cout << i << " " << h[i] << endl ;
    }



    for ( i= 0 ; i < tam ; i++) // i = 0 ... n-2
    {
          meio[i]= 4  ;
          lambda[i]= 1;
          lambda2[i]=1;
    }

    for ( i= 0 ; i < tam ; i++) // i = 0 ... n-1
    {
        sol[i]= (6/(h[i]*h[i])) *(_y[i+2]-(2*_y[i+1])+_y[i]);
    }



    cout << "Matriz Tridiagonal " << endl ;
    ImprimeMatrizTridiag(lambda,meio,lambda,tam);
    cout << "Matriz Solucao " << endl ;
    ImprimeMatriz(sol,tam);

   Tridiag(lambda,meio,lambda2,sol,S,tam);   //vetor a , vetor b , vetor c , vetor d , tamanho da matriz  ;

    AdiantaIndice(S,n);

    S[0]=0;
    S[n-1] = 0;

    cout << "Solucao do Spline-Cubico natural " << endl ;

    for (int i=0;i<n;i++)
     {
        cout << "M[" << i+1 << "]="<< setprecision(5) << S[i] << endl ;
     }


//calculando os coeficientes do spline cubico
    cout << "Coeficientes do Spline Cubico Natural" << endl ;
    for (int i=0;i<n;i++)
     {

        a[i] = (S[i+1]-S[i])/(6*h[i]);
        b[i] = (S[i])/(2);
        c[i] = ((_y[i+1]-_y[i])/(h[i])) - ((S[i+1]+2*S[i])/6)*h[i]; ;
        d[i]= _y[i];
        cout << _x[i] << " " <<a[i] << " " << b[i] << " " << c[i] << " " << d[i] <<  endl ;
     }

    cout << "Gerando os pontos do Gráfico" << endl ;

        for (k=0;k<n;k++)
        {
            do
            {

                saiday=  (a[k]*Elevado((px-_x[k]),3))+ (b[k]* Elevado((px-_x[k]),2))+(c[k]*(px-_x[k])) +(d[k]) ;
                EscreveArq("splinecubnatural.dados",px,saiday); // eu teria que eliminar o arquivo antes do for
                
                px+=delta;
            }while(px<_x[k+1]);
           
        }
    
    cout << "OK , Seus dados estao prontos para serem plotados ! " << endl ;
    }


//
// Interpolação Splines Parabolico com condições (M[1] = M[2] e M[N]= M[N-1] )
// Entrada : pontos x e y
// Saida : Arquivo "splineparabolico.dados"
// Objetivo : Interpola de tres em tres pontos utilizando parabolicas
// é uma boa interpolacao para funcoes exponenciais ou periodicas
//
//

void SplineParabolico(const double *_x , const double *_y , const int &_tamanho)
{

    int n(_tamanho);    // numero de pontos
    int tam=n-2;        // tamanho da matriz a ser resolvida

    double *h,*lambda;  //variaveis necessárias ao metodo
    double *sol;        // matriz solucao , pertence aos sistema do tridiag
    double *a,*b,*c,*d; // coeficientes do spline cubico
    double *lambda2,*meio; // posicoes da matriz tridiag
    double *S;                     // solucao da matriz tridiag
    double saiday;                 // polinomio do spline cubico
    double delta(0.01);     // distancia entre pontos no plot
    double px(_x[0]);          // ponto a ser interpolado no plot
    int k,i,j ; // contadores

//variaveis necessarias ao calculo do spline

    h = new double[n];
    meio = new double[tam];
    lambda = new double[tam];
    lambda2 = new double[tam];
    sol = new double[tam];
    a = new double[n];
    b = new double[n];
    c = new double[n];
    d = new double[n];
//fim

    S = new double[n]; // solucao do spline

    // inicio algoritmo

    //calcula h

    for ( i= 0 ; i < n ; i++) // i = 0 ... n-2
    {
        j=i+1;
        h[i] = _x[j]-_x[i]; //  h[1] = x[1] - x[0] ... // ok
       // cout << i << " " << h[i] << endl ;
    }


    
    for ( i= 0 ; i < tam ; i++) // i = 0 ... n-2
    {
          meio[i]= 4  ;
          lambda[i]= 1;
          lambda2[i]=1;
    }
    meio[0]=5;       // definicao do spline parabolico
    meio[tam-1] = 5 ; // definicao do spline parabolico

    for ( i= 0 ; i < tam ; i++) // i = 0 ... n-1
    {
        sol[i]= (6/(h[i]*h[i])) *(_y[i+2]-(2*_y[i+1])+_y[i]);
    }



    cout << "Matriz Tridiagonal " << endl ;
    ImprimeMatrizTridiag(lambda,meio,lambda,tam);
    cout << "Matriz Solucao " << endl ;
    ImprimeMatriz(sol,tam);

   Tridiag(lambda,meio,lambda2,sol,S,tam);   //vetor a , vetor b , vetor c , vetor d , tamanho da matriz  ;

     AdiantaIndice(S,n);

    S[0]=S[1];
    S[n-1] = S[n-2];

    cout << "Solucao do Spline-Parabolico " << endl ;

    for (int i=0;i<n;i++)
     {
        cout << "M[" << i+1 << "]="<< setprecision(5) << S[i] << endl ;
     }

cout << "Coeficientes do Spline cubico Parabolico" << endl ;
//calculando os coeficientes do spline cubico
    for (int i=0;i<n;i++)
     {

        a[i] = (S[i+1]-S[i])/(6*h[i]);
        b[i] = (S[i])/(2);
        c[i] = ((_y[i+1]-_y[i])/(h[i])) - ((S[i+1]+2*S[i])/6)*h[i]; ;
        d[i]= _y[i];
        cout << _x[i] << " " << a[i] <<" " <<  b[i] << " " << c[i] <<" " <<  d[i] << endl ;
     }

    cout << "Gerando os pontos do Gráfico" << endl ;

        for (k=0;k<n;k++)
        {
            do
            {

                saiday=  (a[k]*Elevado((px-_x[k]),3))+ (b[k]* Elevado((px-_x[k]),2))+(c[k]*(px-_x[k])) +(d[k]) ;
               EscreveArq("splineparabolico.dados",px,saiday); // eu teria que eliminar o arquivo antes do for
               
                px+=delta;
            }while(px<_x[k+1]);
           
        }
    cout << "OK , Seus dados estao prontos para serem plotados ! " << endl ;
    }



//
// Interpolação Splines Runout com condições (M[1] = 2M[2]-M3  e M[N]= 2M[N-1]-M[N-2] )
// Entrada : pontos x e y
// Saida : Arquivo "splinerunout.dados"
// Objetivo : Interpola de tres em tres pontos
// A condicao faz com que a curga seja degradada para uma cubica simples
// dentro dos dois ultimos intervalos e não como duas funcoes separadas 
//
//

void SplineRunOut(const double *_x , const double *_y , const int &_tamanho)
{

    int n(_tamanho);    // numero de pontos
    int tam=n-2;        // tamanho da matriz a ser resolvida

    double *h,*lambda;  //variaveis necessárias ao metodo
    double *sol;        // matriz solucao , pertence aos sistema do tridiag
    double *a,*b,*c,*d; // coeficientes do spline cubico
    double *lambda2,*meio; // posicoes da matriz tridiag
    double *S;                     // solucao da matriz tridiag
    double saiday;                 // polinomio do spline cubico
    double delta(0.01);     // distancia entre pontos no plot
    double px(_x[0]);          // ponto a ser interpolado no plot
    int k,i,j ; // contadores

//variaveis necessarias ao calculo do spline

    h = new double[n];
    meio = new double[tam];
    lambda = new double[tam];
    lambda2 = new double[tam];
    sol = new double[tam];
    a = new double[n];
    b = new double[n];
    c = new double[n];
    d = new double[n];
//fim

    S = new double[n]; // solucao do spline

    // inicio algoritmo

    //calcula h

    for ( i= 0 ; i < n ; i++) // i = 0 ... n-2
    {
        j=i+1;
        h[i] = _x[j]-_x[i]; //  h[1] = x[1] - x[0] ... // ok
       // cout << i << " " << h[i] << endl ;
    }



    for ( i= 0 ; i < tam ; i++) // i = 0 ... n-2
    {
          meio[i]= 4  ;
          

          lambda[i]= 1;
          //cout << lambda[i]<<endl ;

          lambda2[i]=1;

    }

    lambda[tam-1]= 0; // condição do método cubico
    lambda2[0] = 0 ; // condição do método cubico
    
    meio[0]=6;       // definicao do spline cubico
    meio[tam-1] = 6 ; // definicao do spline cubico

    for ( i= 0 ; i < tam ; i++) // i = 0 ... n-1
    {
        sol[i]= (6/(h[i]*h[i])) *(_y[i+2]-(2*_y[i+1])+_y[i]);
    }



    cout << "Matriz Tridiagonal " << endl ;
    ImprimeMatrizTridiag(lambda,meio,lambda2,tam);
    cout << "Matriz Solucao " << endl ;
    ImprimeMatriz(sol,tam);

   Tridiag(lambda,meio,lambda2,sol,S,tam);   //vetor a , vetor b , vetor c , vetor d , tamanho da matriz  ;

     AdiantaIndice(S,n);

    S[0]=2*S[1]-S[2];
    S[n-1] = 2*S[n-2]-S[n-3];

    cout << "Solucao do Spline-Runout " << endl ;

    for (int i=0;i<n;i++)
     {
        cout << "M[" << i+1 << "]="<< setprecision(5) << S[i] << endl ;
     }


//calculando os coeficientes do spline cubico
cout << "Coeficientes do Spline cubico Cubico" << endl ;
    for (int i=0;i<n;i++)
     {

        a[i] = (S[i+1]-S[i])/(6*h[i]);
        b[i] = (S[i])/(2);
        c[i] = ((_y[i+1]-_y[i])/(h[i])) - ((S[i+1]+2*S[i])/6)*h[i]; ;
        d[i]= _y[i];
        cout << _x[i] << " " << a[i] <<" " <<  b[i] << " " << c[i] <<" " <<  d[i] << endl ;
     }

    cout << "Gerando os pontos do Gráfico" << endl ;

        for (k=0;k<n;k++)
        {
            do
            {
                saiday=  (a[k]*Elevado((px-_x[k]),3))+ (b[k]* Elevado((px-_x[k]),2))+(c[k]*(px-_x[k])) +(d[k]) ;
                EscreveArq("splinerunout.dados",px,saiday); // eu teria que eliminar o arquivo antes do for
                px+=delta;
            }while(px<_x[k+1]);
           
        }
    cout << "OK , Seus dados estao prontos para serem plotados ! " << endl ;
    }




	*/

