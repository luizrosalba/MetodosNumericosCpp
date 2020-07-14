//
// Método de Euler
// Resolve Equações diferenciais
//
//  dy/dx - y = 0
//  usa-se de :
//  y(k+1) = dy/dx (x-xk) + y (k)
// onde x-xk = intervalo entre uma iteracao e outra
// dy/dx = derivada da funcao
// y(k) = y calculado na iteração anterior
//


#include "metodosnum.h"
/*
// valor inicial de x , o intervalo e o limite de iterações
double Euler (const double &_x0,const double &_intervalo, const double &_limite )
{
    double x(_x0);
    
    double y(0);


    for (int k = 0 ; k < _limite ; k++ )
    {
        y = (derivada(x) * _intervalo) + x;
        cout << "Iteracao " << k+1 << " Valor de x : " <<setprecision(10)<< x << " Y calculado : " <<setprecision(10)<< y << endl;
        x = y; // para a proxima iteracao
        
    }
}

double derivada (const double &_x)
{
    double gama = 0.0007;


    return gama*(_x);

}*/