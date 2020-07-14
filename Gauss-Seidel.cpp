/
// Método de Gauss-Seidel
// Resolve sistemas A * B = C
// Criterio de parada :
// 1) iterações alteram muito pouco de valor de uma iteração para outra (um menos a outra da quase zero)
// 2) K = max , não há convergencia
//
#include "metodosnum.h"


using namespace std;
// matriz a , matriz b , matriz c , chute inicial , numero maximo de iterações  , tolerancia
double GaussSeidel (double**_A,const double*_b,const double*_x,const int &_tamanho, const int &_max, const double &_tol)
{
    int k(0),i(0),j(0) ; // contador
    const int n=_tamanho; // so mudei para saber que a entrada eh o tamanho da matriz ...

    double *novox; // gerando o vetor da proxima iteralçao ( x^(k+1) )
    novox = new double[n];

    double *x; // gerando o vetor da interaçao atual  ( x^(k) )
    x = new double[n];

    for (i=0;i<n;i++)
    {
        x[i] = _x[0]; // tranferindo o chute inicial para um vetor editavel
    }


    double somat(0) ;
    double somat2(0);

    for (k=0;k<=_max;k++)
    {

            for (i=0;i<_tamanho;i++)
            {
                for (j=0;j<n;j++)
                    {
                       if (j<i) {somat += _A[i][j]*novox[j];};
                       if (j>i) {somat2 += _A[i][j]*x[j];};


                    }
                novox[i] =   (_b[i] - somat - somat2)/( _A[i][i] );
                somat = 0;  // reinicializando
                somat2=0;
            }

         if (AlteraPouco2(novox,x,n) < _tol ) // se progredi pouco , paro o processo iterativo
            {
                cout << "Solucao encontrada na iteração numero " << k << endl ;
                    for (i=0;i<n;i++)
                    {    cout << "x["<< i+1  << "] vale:  " << novox[i] << endl ;
                    }
                    return 0;
            }
            else
            {

                   
             //cout <<"novox[n] : " << novox[0] << " "<<novox[1] << endl ;
            // cout << "Convergencia : " << AlteraPouco2(novox,x,n) << endl ;
             cout << endl ;
                 for (i=0;i<n;i++)
                    {
                        x[i] = novox[i];  // guardando o vetor para gerar a proxima iteracao
                    }


            }
             cout << "Valor de x[n] encontrado na " << k+1 << " iteração : " << endl ;
                for (i=0;i<n;i++)
                {
                    cout << "x["<< i+1  << "] vale:  " << novox[i] << endl ;
                }

    }
    cout << "Não houve convergecia" << endl ;
   
    return 1;
}

double AlteraPouco2(const double *_novox , const double*_x , const int &_n)
{
    double taxa(0);

    for (int i=0;i<_n;i++)
    {
        taxa+= (_novox[i]-_x[i]) * (_novox[i]-_x[i]) ;
    }

    return sqrt(taxa);
}



