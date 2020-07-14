#include "metodosnum.h"

void MetNum::Host_Simpson(double _a , double _b)
{
	double saida(0);

    saida =(_b-_a)*(funcao(_a)+4.0*funcao((_a+_b)/2)+funcao(_b))/6.0;
    
    cout << " Integração por Simpson  = " << saida << endl;

}