//
// Método de Solução de Matrizes Tridiagonais
//
// Criterio de parada :
//
// 1) Metodo Direto (resolve sempre)
//
//
//          b1  c1                                              d1
//
//      [   a2  b2  c2                          ]   =   [       d2  ]
//              .   .   .                                       .
//                  .   .   .                                   .
//                 an-1    bn-1    cn-1                         dn-1
//                          an     bn                           dn
/*

#include <Tridiag.h>
#include <iomanip>

using namespace std;
//vetor a , vetor b (meio) , vetor c , vetor d (solucao), tamanho da matriz  ;
void Tridiag(const double*_a,const double*_b,const double*_c,const double*_d,double *_x,const int &_tamanho)
{
    double *a,*b,*d;
    int n(_tamanho);
    a = new double [_tamanho];
    b = new double [_tamanho];
    d = new double [_tamanho];

    for (int k= 0 ; k < n;k++)
    {
        a[k]=_a[k];
        b[k]=_b[k];
        d[k]=_d[k];
       // cout << a[k] << " " << b[k]<< " " << _c[k]<<" "  << d[k] << endl ;
    }


    
   for (int k= 1; k < n;k++)
    {
        a[k]=a[k]/b[k-1];
        b[k]=b[k]-a[k]*_c[k-1];
        //ok // cout << _a[k] << " " << _b[k] << endl ;
    }

   for (int k= 1; k < n;k++)
    {
        d[k]=d[k]-(a[k]*d[k-1]);
       // cout << _d[k] << endl ;// ok
    }

    _x[n-1]= d[n-1]/b[n-1];
    //cout << _x[n-1] << endl ;
    for (int k= n-2; k >= 0;k--)
    {
        _x[k]=(d[k]-(_c[k]*_x[k+1]))/b[k];
       //cout << _x[k] << endl ;
    }
 }

 */