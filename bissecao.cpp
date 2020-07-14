#include "metodosnum.h"


using namespace std;
////////////////////
///
//
///
//////////////////
void MetNum::Host_Bissecao(double _liminf,double _limsup,double _numiter,double _limiar )
{
	
	int k=1;
    
	double a(0),b(0),xm(0);
	a=_liminf;
	b=_limsup;
    
	do
    {
        xm = (a + b)/2;
		
        
		(funcao(a)*funcao(b)<0)?b=xm:a=xm;// teste de troca de sinal

		k++;
	}while ( (abs(funcao(xm))>_limiar) && (k < _numiter) && a!=b);

	//cout << true << " " << (abs(funcao(xm)>_limiar)) << endl;
	//cout << false << " " << (abs(funcao(xm)>_limiar)) << endl;
	//cout << funcao(xm) << " " << _limiar << endl;

	cout << " Solucao encontrada na iteracao " << k << " e vale " << setprecision(10) <<xm << endl ; 
	cout << " A proximidade com o zero vale  " << setprecision(10) << abs(funcao(xm)) << endl ; 
	
        
}