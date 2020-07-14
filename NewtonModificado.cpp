
#include "metodosnum.h"

void MetNum::Host_NewtonModificado (double _x0 , int _numiter, double _limiar)
{
    int k=1;
    double x, teste1, teste2, e=_limiar, x1, teste3,h=1e-3,tempder(0),tempfun(0),derdupla(0);
    x=_x0;

	while (k<_numiter)
    {
        teste1 = fabs(funcao(x));

        teste2 = fabs(derivadaavancada(x,h));
		//teste2 = derivadanamao(x);

        if ( teste1 < e)
        {
            cout << " A solucao eh T1: " << x << endl;
			cout <<" Limiar dado " <<  e  <<  " Valor alcancado " << teste1 << endl ; 
            break;
        }

        if (teste2 < 1e-15)
        {
			cout << "teste 2 " << teste2 << endl; 
            cout << " A derivada eh nula T2" << endl;
            break;
        }
		tempder = derivadaavancada(x,h);
		tempfun=funcao(x);
		derdupla=derivadasegunda(x,1e-3);

		x1 = x - ((    tempfun*tempder) / ((tempder*tempder)-(tempfun*derdupla ))) ;
		//x1 = x - (funcao(x)/derivadanamao(x));
		
        teste3 = fabs(x - x1);

        if(teste3 < e)
        {
            cout << " A solucao eh T3: " << x1 << endl;
            break;
        }
		
		cout << " Iteracao " << k << " valor " << x1 << " " <<  endl;

        x = x1;
        k++;

    }

   cout << "Fim das iteracoes" <<endl ;
}


