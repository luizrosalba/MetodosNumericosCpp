

#include "metodosnum.h"

/////////////////////////////////////////////////
// resolve integrais. 
//  entrada : a e b , limite de inicio e fim da integracao
//  dependencia: F -> uma funcao a ser integrada 
//				 o valor de n (tamanho da coluna) 
//				fornece a precisao e só pode ser alterada
//				de dentro do codigo pois eh const int
//  retorno : o valor da integral definida
////////////////////////////////////////////////////

double MetNum::Romberg( double _a , double _b )
{
	ofstream saida;
	const int n(3);
	double a(_a) , b(_b); // intervalo de integracao
	saida.open("saida.txt",ios::trunc);
	vector <double> h ; 


	h.push_back(0); // para trabalhar com os mesmos indices do 
					// problema 
	for (int i =1 ; i <=n ; i ++ )
	{
		h.push_back((b-a)/(pow(2.0,i-1)));
		cout <<  " h "<< h.at(i) << endl ;
	}
	
	vector <double> R;
	R.push_back(0); // preenchendo a primeira posicao para 
			       /// facilitar o trabalho com os indices
	
	R.push_back((h.at(1)/2.0)*(F(a)+F(b))); // primeiro valor da coluna
	cout << " k e R em k " << 1 <<  " "  <<   R.at(1) << endl ;
	double somat(0);
	for (int k =2 ; k <=n ; k ++ )
	{

		for (int i=1;i<=int(pow(2.0,(k-2)));i++)
		{
			somat+=F(a+(2*i-1)*h.at(k)); 
		}
		
		R.push_back(0.5*( R.at(k-1)+ h.at(k-1)*somat ));

		//cout << " k e R em k " << k <<  " "  <<   R.at(k) << endl ;
		somat=0;
	}


	double matriz[n+1][n+1];
	for (int k =1 ; k <=n ; k ++ )
	{
		matriz[k][1]=R.at(k);
		
	}


	for (int k =2 ; k <=n ; k ++ )
	{
		
		for (int j=2;j<=k;j++)
		{
			matriz[k][j] = matriz[k][j-1]+( 1.0*(matriz[k][j-1]-matriz[k-1][j-1] ) / (pow(4.0,(j-1))-1.0) );	
		}
		cout << endl << endl ; 
		
		
	}

	for (int j =1 ; j <=n ; j ++ )
	{
		
		for (int k=j;k<=n;k++)
		{
			saida <<  matriz[k][j] << endl ;  
			cout <<  matriz[k][j] << endl ;  
		}	
		saida<< endl << endl; 
		cout<< endl << endl; 
	}


	return (matriz[n][n]);
}
