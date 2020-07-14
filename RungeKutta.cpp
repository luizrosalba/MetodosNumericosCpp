/*
#include <RungeKutta.h>

#include "Elevado.h" 



double RungeKuttaSegundaOrdem(double _x,double _y,double _h, double _numiter )
{
    
    double m0temp(0) , m1temp(0) ;
    double novoy(0);
    
    double xmaish(0);
    double ymaism0(0);
 
    for (int k=0;k<_numiter;k++)
    {
        cout << " x = "  << _x << " y = " << _y << endl ;
        m0temp=m0(_x,_y,_h);

        xmaish=_x+_h;
        ymaism0=_y+m0temp;

        m1temp=m0(xmaish,ymaism0,_h);

        novoy=_y+(0.5*(m0temp+m1temp));

     //   cout << "m0= " << m0temp << " m1 = " << m1temp << endl ;
        cout << "O valor de y_" << k+1 << " eh: " << novoy<< endl ;

        cout << endl << endl ;
        _y+=novoy;
        _x+=_h; // somei h ao t inicial

    }

    
return 0 ;     
}


double RungeKuttaQuartaOrdem(double _x,double _y,double _h, double _numiter )
{
    
    double m0temp(0) , m1temp(0) , m2temp(0) , m3temp(0);
    double novoy(0);
    
    double xmaish(0);
    double ymaism(0);
 
    for (int k=0;k<_numiter;k++)
    {
        cout << " x = "  << _x << " y = " << _y << endl ;
        
        m0temp=m0(_x,_y,_h);

        xmaish=_x+_h/2;
        ymaism=_y+m0temp/2;
        m1temp=m0(xmaish,ymaism,_h);

        xmaish=_x+_h/2;
        ymaism=_y+m1temp/2;
        m2temp=m0(xmaish,ymaism,_h);

        xmaish=_x+_h;
        ymaism=_y+m2temp;
        m3temp=m0(xmaish,ymaism,_h);

        
        novoy=_y+(0.16666666*(m0temp+2*m1temp+2*m2temp+m3temp));
        
        

        cout << "m0= " << m0temp << " m1 = " << m1temp << "m2= " << m2temp << " m3 = " << m3temp <<  endl ;
        cout << "O valor de y_" << k+1 << " eh: " << novoy<< endl ;

        cout << endl << endl ;
        _y+=novoy;
        _x+=_h; // somei h ao t inicial

    }

    
return 0 ;     
}


double m0(double &_x , double &_y , double &_h)
{
return (_h*funcao(_x,_y));
}


double funcao (double &_x , double &_y)
{
 double beta(1); // aqui varia-se o valor de beta
return (  20 +   beta*sin(3*_x) -    pow((_y/5.0),(2.0/3.0))    ); // funcao do SN
//*return ( (_x/(1+(_x*_x))) );
//return (-2*_x-(_y)) ;
}

*/