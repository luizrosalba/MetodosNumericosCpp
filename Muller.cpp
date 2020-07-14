
#include "metodosnum.h"

void MetNum::Host_Muller (double _x0 ,double _x1 ,double _x2,  int _numiter)
{
    int k=2;

    double *x,*h,lambdan(0),lambda(0),sigma(0),g(0),c(0) ;
    
	x = new double [_numiter];
	h= new double [_numiter];

	x[0]=_x0;
	x[1]=_x1;
	x[2]=_x2;

	//while (k<_numiter)
    {
		h[k]= x[k]-x[k-1];
		//cout << "h[k] "<< h[k] << endl ;
		lambdan= h[k]/h[k-2];
		cout << "lambda[k] "<< lambdan << endl ;
		sigma = 1+lambdan;
		g=lambdan*lambdan*funcao(x[k-2])-sigma*sigma*funcao(x[k-1])+(lambdan+sigma)*funcao(x[k]);
		c= lambdan*(lambdan*funcao(x[k-2])-sigma*funcao(x[k-1])+funcao(x[k]));
		
		if (g>0)
			lambda=-(2*sigma*funcao(x[k]))/(g+sqrt(g*g-4*sigma*funcao(x[k])*c));
		else 
			lambda=-(2*sigma*funcao(x[k]))/(g-sqrt(g*g-4*sigma*funcao(x[k])*c));

		x[k+1]= x[k]+(x[k]-x[k-1])*lambda;
		x[k-1]= x[k]+(x[k]-x[k-1])*lambda;
		k++;

    }
	

	//cout <<x[0] << " " << x[1] << " " << x[2] << " " << x[3] << " " << x[4] << " " <<endl;
	//for (int i=0 ; i<_numiter;i++)
	//	std::cout <<"Iteracao " << i << " valor " << x[i] << endl;

   std::cout << "Fim das iteracoes" <<endl ;
}


