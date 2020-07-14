#include "metodosnum.h"

double funcao(double _x)
{
	//return (cos(_x+sqrt(2.0))+_x*(_x/2.0+sqrt(2.0)));
	//return(20*_x-quad(_x)+sqrt(20-_x)*_x+20*sqrt(_x) - _x*sqrt (_x) +sqrt(20-_x)*sqrt(_x) - 155.55);
	//return(quad(_x)-2*_x*exp(-_x)+exp(-2*_x));		                            
	//return ( quad(_x)*quad(_x)-7*_x*_x+12 );
	//return (pow(_x,3.0)-(3*pow(_x,2.0)*pow(2.0,-_x))+(3*_x*pow(4.0,-_x))+pow(8.0,-_x));

	//return (exp(6*_x)+3*pow(log(2.0),2.0)*exp(2*_x)-(log(8.0)*exp(4*_x))-pow(log(2.0),3.0)) ;
	return ((_x*_x*_x)-(3*_x*_x*pow(2.0,-_x))+(3*_x*pow(4.0,-_x))+pow(8.0,-_x));
	
	 
	//return ((_x*_x*_x)-(3*_x*_x*pow(2.0,-_x))+(3*_x*pow(4.0,-_x))+pow(8.0,-_x));
}



double funcaomulti(vector <double> _x)
{
	double x0quad = Elevado(_x.at(0),2);
	//return (_x.at(0)*_x.at(1)+Elevado(_x.at(0),2)+Elevado(_x.at(1),3));//quadratica
	//return (Elevado(_x.at(0),2)+Elevado(_x.at(1),2));//quadratica
	//return (1.0316285+4* Elevado(_x.at(0),2)-2.1*Elevado(_x.at(0),4)+Elevado(_x.at(0),6)/3.0+_x.at(0)*_x.at(1)-4*Elevado(_x.at(1),2)+4*Elevado(_x.at(1),4));//Hump Functions 
	//return (log(exp(_x.at(0))+exp(_x.at(1)) )) ; 
	//return ((Elevado(_x.at(0),2))+Elevado(_x.at(1),2)) ; 
	//return ( (25 *(Elevado(_x.at(0),2) )+ (Elevado(_x.at(1),2)  )));// 
	//return ( (10* (Elevado((_x.at(1)-x0quad),2)))+ Elevado(  (1-_x.at(0))    ,2))  ;// 

	 // generalized rosenbrock function 
	double som= 0.0;
	double c =100.0;
	double temp =0.0;
	for (int i = 0 ; i< (_x.size()-1);i++)
	{
		temp = (  _x.at(i+1) - Elevado(_x.at(i),2)   ); 
		som +=  c* Elevado (temp,2) + Elevado((1-_x.at(i)),2);
	}
	return som ;
	





	/*
	 // extended penalty fuction
	double som= 0.0;
	double temp =0.0;

	for (int i = 0 ; i< (_x.size()-1);i++)
	{
		temp = (  _x.at(i) - 1  ); 
		som +=Elevado (temp,2); 
	}
	for (int i = 0 ; i< (_x.size());i++)
	{
		som +=   Elevado (_x.at(i),2);
	}
	som -=0.25;
	som = Elevado(som,2);
	return som ;
	*/

	// sphere 
	/*
	double som= 0.0;

	for (int i = 0 ; i< _x.size();i++)
	{
		som +=Elevado (_x.at(i),2); 
	}
	return som ; 
	*/

	//return ((Elevado(_x.at(0),2))+Elevado(_x.at(1),2)) ;  // rosenbrock generalizada  
}




double F(double _ent)
{
	
	double a(10.0) , h(10.0);
	
	return ( (_ent*_ent)/4.0 -cos(_ent) );
	//return ( tan(_ent*a) -( h/_ent) );
	
	/*
	double t1(_ent-0.1);
	double t2(_ent-0.2);
	


	if (_ent>=0 && _ent<=0.1)
		return (pow(_ent,3.0)+1.0);
	
	if (_ent>0.1 && _ent<=0.2)
		return(1.001+0.03*(t1)+0.3*(t1*t1)+2.0*(t1*t1*t1));
	
	if (_ent>0.2 && _ent<=0.3)
		return(1.009+0.15*(t2)+0.9*(t2*t2)+2.0*(t2*t2*t2));
	
	
	/*
	return (pow(_ent,1.0/3.0));
	*/
}
