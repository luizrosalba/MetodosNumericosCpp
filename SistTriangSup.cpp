//
// Método de Solução de Sistemas Triangulares Superiores
// Resolve sistemas A * B = C onde A é matriz escada
// Criterio de parada :
// 1) Metodo Direto (resolve sempre)
// Obs : As vezes podemos reduzir uma matriz a uma matriz escada escalonando-a
//
/*
#include <SistTriangSup.h>

using namespace std;

double SisTriangSup(double**_A,const double*_b,const int &_tamanho)
{
    int n = _tamanho ; // tamanho da matriz
    int i,j,k ; // contador
    double soma(0) ;
     double *x; // gerando o vetor da interaçao atual  ( x^(k) )
    x = new double[n];

    x[n-1] = _b[n-1]/_A[n-1][n-1]; // ultima solução jah sabemos ...    
    for (k=(n-2);k>=0;k--) // k = 1 e 0
    {
        
        soma = _b[k]; // soma = _b[1] = 3

        for (j=k+1;j<n;j++) // j = 2 ; j < 3 ; j ++
        {
            soma = soma - (_A[k][j]*x[j]); // soma = 3 - 2 = 1            
        }
         cout << "soma : " << soma << endl ;
        x[k]= soma/_A[k][k]; // x[2] =
    }

    cout << " A solucao vale : " << endl ;
     for (i=0;i<n;i++)
    {
         cout << "x[" << i+1 << "]: " << x[i] << endl ;
    }

}


*/