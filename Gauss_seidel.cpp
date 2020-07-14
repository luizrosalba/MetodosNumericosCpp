//
// Método de Gauss-Seidel
// Resolve sistemas A * B = C
// 
// Criterio de parada :
// 1) iterações alteram muito pouco de valor de uma iteração para outra (um menos a outra da quase zero)
// 2) K = max , não há convergencia
//


#include "metodosnum.h"


// matriz a , matriz solucao (C) , chute inicial , numero maximo de iteracoes e tolerancia 
bool MetNum::GaussSeidel (double**_A,vector <double> sol,vector <double> chute,const int &_maxiter, const double &_tol)
{
	

    int k(0),i(0),j(0) ; // contador
    //const int n=_tamanho; // so mudei para saber que a entrada eh o tamanho da matriz ...

	const int n = (sol.size());
	vector <double> novox;
 //   double *novox; // gerando o vetor da proxima iteralçao ( x^(k+1) )
  //  novox = new double[n];

	vector <double> atual;
    //double *x; // gerando o vetor da interaçao atual  ( x^(k) )
    //x = new double[n];
	atual = chute;
	
	if (chute.size()==0)
	{
		cout << "Chute da solucao Para Gauss-Seidel nao existe , favor definir chute" << endl ; 
		return false ;
	}
    double somat(0.0) ;
    double somat2(0.0);

    for (k=0;k<=_maxiter;k++)
    {

            for (i=0;i<n;i++)
            {

                for (j=0;j<n;j++)
                 {
						
                       if (j<i) {somat += _A[i][j]*novox.at(j);};
                       if (j>i) {somat2 += _A[i][j]*atual.at(j);};
					  
                  }
					novox.push_back((sol.at(i) - somat - somat2)/( _A[i][i] ) );
					somat = 0;  // reinicializando
					somat2 = 0;
            }
			//cout << "aqui " << endl ;
			//ImprimeVetor(novox);
			//ImprimeVetor(atual);
         if (AlteraPouco2(novox,atual) < _tol ) // se progredi pouco , paro o processo iterativo
            {
               // cout << "Solucao encontrada na iteração numero " << k << endl ;
                 //   for (i=0;i<n;i++)
                  //  {    cout << "x["<< i+1  << "] vale:  " << novox.at(i) << endl ;
                  //  }
					direcao.clear();
					direcao=novox; // dando a direcao de newton o valor da solucao 
                    return true;
            }
            else
            {


             //cout <<"novox[n] : " << novox[0] << " "<<novox[1] << endl ;
            // cout << "Convergencia : " << AlteraPouco2(novox,x,n) << endl ;
             //cout << endl ;
             atual = novox;  // guardando o vetor para gerar a proxima iteracao
			 novox.clear();

            }
             //cout << "Valor de x[n] encontrado na " << k+1 << " iteração : " << endl ;
			 //ImprimeVetor(novox);
    }
    //cout << "Não houve convergecia" << endl ;

    return false;
}

double AlteraPouco2(vector <double> enta , vector <double> entb  )
{
    double taxa(0);
	const int _n= enta.size();
    for (int i=0;i<_n;i++)
    {
		
        taxa+= (enta.at(i)-entb.at(i)) * (enta.at(i)-entb.at(i)) ;
    }

    return sqrt(taxa);
}
