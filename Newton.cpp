
#include "metodosnum.h"

void MetNum::Host_Newton (double _x0 , int _numiter, double _limiar)
{
    int k=1;
    double x, teste1, teste2, e=_limiar, x1, teste3,h=1e-5;
    x=_x0;

	while (k<_numiter)
    {
        teste1 = fabs(funcao(x));

        teste2 = derivadaavancada(x,h);
		//teste2 = derivadanamao(x);

        if ( teste1 < e)
        {
            cout << " A solucao eh T1: " << x << endl;
			cout <<" Limiar dado " <<  e  <<  " Valor alcancado " << teste1 << endl ; 
            break;
        }

        if (teste2 == 0)
        {
            cout << " A derivada eh nula T2" << endl;
            break;
        }

        x1 = x - (funcao(x)/derivadaavancada(x,h));
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


