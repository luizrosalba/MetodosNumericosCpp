#include "metodosnum.h"

// 
//
//

void MetNum::FFT(vector <double> _x, vector <double>_y, int grau )
{
	int m=grau;
	//m=  dimensao do polinomio interpolador
	double pi(3.141592653589);
	double tamx=_x.size();
	int M=(2*m)-1; // limite do somatorio
	vector <double> xj ,a,b; 
	double temp(0);
	// calculando os nós 
	for (int i=0;i<tamx;i++)
	{
		
		temp = (i/(m*1.0))*pi-pi;
		xj.push_back(temp);
		//cout << xj.at(i) << endl ;

	}
	
	complex <double> ck(0,0),comtemp(0,0); // construtor do complexo
	// calculo dos ak e bk atraves de ck 
	cout << "Calculo do coeficientes" << endl;
	for (int k=0;k<M;k++)
	{
		ck=(0,0);
		for (int j=0;j<M;j++)
		{
			
			temp=  k * xj.at(j);

			comtemp=complex<double>(cos( temp ),sin(temp)  );
			ck+= _y.at(j)*(comtemp);
			
		}
		
		ck*=(complex<double>(cos( k*pi ),-sin(k*pi))/(m*1.0));

		a.push_back(ck.real()/(m*1.0));
		b.push_back(ck.imag()/(m*1.0));
		
	}
	
	cout << "coeficientes a" << endl;
	ImprimeVetor(a);
	cout << "coeficientes b" << endl;
	ImprimeVetor(b);
	cout << "Polinomio interpolador" << endl;

	double menor, maior;
	vector <double> dados,saida;

	menor=*min_element(_x.begin(),_x.begin()+tamx);
	maior=*max_element(_x.begin(),_x.begin()+tamx);
	dados=Gera_dadosRetorna(menor,maior,10);
	int tamdados=dados.size();
	double prim(0),somat(0);
	// polinomio interpolador 
	for (int i=0;i<tamdados;i++)
	{
		somat=0;
		 
		for(int k=1;k<=m-1;k++)
		{
			//cout <<"aa "<< 		(a.at(k)*cos(k*dados.at(i)))+(b.at(k)*sin(k*dados.at(i)));			
			somat+=(a.at(k)*cos(k*dados.at(i)))+(b.at(k)*sin(k*dados.at(i)));			
		}

		prim=(a.at(0)+a.at(m-1)*cos(m*dados.at(i)))/2.0;
		saida.push_back(prim+somat);
		
	}
	
	EscreveDoisVetArq("saida.txt",dados,saida);
	cout << "Escrito" << endl;
}