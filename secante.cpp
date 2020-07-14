
#include "metodosnum.h"

void MetNum::Host_Secante (double _x0 , double _x1,int _numiter, double _limiar)
{
    int k=1;
   
	double teste1, teste2, e=_limiar, x0,x1;//
    double  *x; // matriz dos coeficientes nao nulos
    //vector <double>::itr;
    
	x = new double [_numiter];

    x[0]=_x0;
    x[1]=_x1;
    while (k<_numiter)
    {
        x[k+1] =  x[k]- funcao(x[k])*(x[k] -x[k-1]) / (  funcao(x[k]) - funcao(x[k-1])    );
       
        teste1 = fabs(funcao(x[k+1]));

        teste2 = fabs(x[k-1] - x[k]);

        if ( teste1 < e)
        {

            cout << " A solucao eh: teste 1 " << x[k+1]<< endl;
			cout << " iteracao "<< k << "  a " << x[k-1] << " b "<< x[k] <<  " PM  " << x[k+1] <<endl;
			cout << " f[a] " << funcao(x[k-1]) << " f[b] " << funcao(x[k]) << " f(PM ) "<< funcao(x[k+1])<<   endl;
            break;
        }

        if(teste2 < e)
        {
            cout << " A solucao eh: teste 2 " << x[k+1] << endl;
			cout << " iteracao "<< k << "  a " << x[k-1] << " b "<< x[k] <<  " PM  " << x[k+1] <<endl;
			cout << " f[a] " << funcao(x[k-1]) << " f[b] " << funcao(x[k]) << " f(PM ) "<< funcao(x[k+1])<<   endl;
		    cout << endl << endl ;
			break;
        } 
		cout << " iteracao "<< k << "  a " << x[k-1] << " b "<< x[k] <<  " PM  " << x[k+1] <<endl;
		cout << " f[a] " << funcao(x[k-1]) << " f[b] " << funcao(x[k]) << " f(PM ) "<< funcao(x[k+1])<<   endl;
       cout << endl << endl ;

        k++;

    }
}