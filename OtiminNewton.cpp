#include "metodosnum.h"

void  MetNum::OtiminNewton( double _epsilon , int _maxiter)
{
	double _h=0.00001;
	int numiter(0);
	vector <double> p , grad , alfa;
	double tempdoub(0.0),tempalfa(0);
	int tam = x.size();
	
	alfa.push_back(0.1);
	alfa.push_back(0.1);

	grad=gradiente(_h);
	double normagrad = norma(grad);

	//cout << " grad inicial " << endl ;
	//ImprimeVetor(grad) ; 
	double** _H;
	//_h=0.0001;
	_H= Hessiana( _h);

	
	while ( (normagrad>_epsilon) && (numiter<_maxiter) )
	{
		//cout << " P " << endl;
		//ImprimeVetor(p);
		//cout << " x " << endl;
		//ImprimeVetor(_x);
		p.clear();
		

		for (int i=0;i<tam ; i++)
		{
			tempdoub = -1*grad.at(i)/normagrad; 
			p.push_back(tempdoub); // p0 
			cout << " P " << endl ; 

			tempdoub= x.at(i); // x0 
			tempdoub+=alfa.at(i)*p.at(i);
			x[i]=tempdoub;
			//cout <<"x " << i <<" " <<   _x[i] << endl ;
		}
		ImprimeVetor(p);
		cout << "Iteracao " << numiter <<  "  sol " <<funcaomulti(x) << endl ; 
		// calculos para proxima iteracao 
		grad.clear();
		grad=gradiente(_h);
		normagrad = norma(grad);
		numiter++;
		
	}
	cout << "Iteracao " << numiter << endl ; 
	cout << "Solucao encontrada " << endl ; 
	ImprimeVetor();
	cout << "Valor da solucao encontrada " << endl ; 
	cout << funcaomulti(x) << endl; ;
	
}