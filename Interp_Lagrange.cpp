#include "metodosnum.h"

// 
//
//

//vector <double>  x , y ;
//vector <double>::iterator dblitr;


void MetNum::Host_Interp_Lagrange(vector <double> _x ,vector <double> _y )
{
	
	
	vector <double> dados,saida;
	double menor, maior;
	int tamx = _x.size();
	// calculo dos polinomios L 
	double baixo(1.0);
	//cout << tamx << endl; 
	
	menor=*min_element(_x.begin(),_x.begin()+tamx);
	maior=*max_element(_x.begin(),_x.begin()+tamx);
	
	//cout << menor << maior << endl ;
	
	//cout << menor<< endl ;
	//Gerando dados no intervalo do x 
	
	dados = Gera_dadosRetorna(menor,maior,100);
	int tamdados=dados.size();
	double somatorio(0);
	double prod(1);
	
	for (int k=0;k<tamdados;k++)
	{
		somatorio=0.0;
		for (int i=0; i<tamx;i++)
		{
			prod=1;
			//calculo do Lj
			for (int j=0;j<tamx;j++)
			{
				if(j!=i)
				{
					prod*=(dados.at(k)-_x.at(j))/(_x.at(i)-_x.at(j));
				}	
			}
			somatorio += _y.at(i)*prod;
		}
		saida.push_back(somatorio);
	}
	const string nome("saida.txt");
	EscreveDoisVetArq(nome,dados,saida);
	cout << "salvo"<< endl ;
}