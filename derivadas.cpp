
#include "metodosnum.h"



// derivada analitica na mao 
double derivadaanalitica(double _ent)
{
	double a(10.0) , h(200.0);
	
	return ( (_ent)/2.0 +sin(_ent) );
}


// um passo da derivada numerica avancada 
double derivadaavancada ( double _x, double _h)
{
	double temp(_x+_h);

	return ((funcao(temp)-funcao(_x))/_h) ; 

}

// um passo da derivada numerica centrada
double derivadasegunda (double _x, double _h)
{
	double mais(_x+_h);
	double menos(_x-_h);


	return ((funcao(mais)-2*funcao(_x)+funcao(menos))/(_h*_h)) ; 

}

// um passo da derivada segunda numerica avancada 
double derivadasegundaavancada (double _x, double _h)
{
	double mais(_x+2*_h);
	double menos(_x+_h);


	return ((funcao(mais)-2*funcao(menos)+funcao(_x))/(_h*_h)) ; 

}


// derivada parcial analitica 
double derivadaparcial (double _x)
{
return (2*_x-2*exp(-_x) +2*_x*exp(-_x)-2*exp(-_x));
}

///retorna o vetor derron f(x) / derron xi
vector <double> MetNum::gradiente( vector <double> _x ,double _h)
{
	int tam = x.size();
	vector <double> grad, tempvecmais , tempvecmenos;
	double tempdoub(0.0); 
	for (int i=0;i<tam;i++)
	{
		tempvecmais.clear();
		tempvecmais=_x;
		tempvecmais[i]+=(_h);
		
		tempvecmenos.clear();
		tempvecmenos=_x;
		tempvecmenos[i]-=(_h);
		//cout << "Temp vec do gradiente " << endl ; 
		//cout.precision(20);ImprimeVetor(tempvec);

		tempdoub= (funcaomulti(tempvecmais)-funcaomulti(tempvecmenos))/(2*_h);// centrada
		//tempdoub= (funcaomulti(tempvecmais)-funcaomulti(_x))/_h; // adiantada 

		//cout << "funcao multi em _tempvec " << endl ;
		//cout.precision(20);cout<< (funcaomulti(tempvec)) << endl ;
		//cout << "funcao multi em _x " << endl ;
		//cout.precision(20);cout<< (funcaomulti(_x)) << endl ;
		//cout << "tempdoub" << endl ; 
		//cout.precision(20);cout<< (funcaomulti(tempvec)-funcaomulti(_x))/_h <<endl ; 
		grad.push_back(tempdoub);

	}
	
	
	return grad;
}

///retorna o vetor derron f(x) / derron xi
vector <double> MetNum::gradiente( double _h)
{
	int tam = x.size();
	vector <double> grad, tempvecmais , tempvecmenos;
	double tempdoub(0.0); 
	for (int i=0;i<tam;i++)
	{
		tempvecmais.clear();
		tempvecmais=x;
		tempvecmais[i]+=(_h);
		
		tempvecmenos.clear();
		tempvecmenos=x;
		tempvecmenos[i]-=(_h);
		//cout << "Temp vec do gradiente " << endl ; 
		//cout.precision(20);ImprimeVetor(tempvec);

		tempdoub= (funcaomulti(tempvecmais)-funcaomulti(tempvecmenos))/(2*_h);// centrada
		//tempdoub= (funcaomulti(tempvecmais)-funcaomulti(_x))/_h; // adiantada 

		//cout << "funcao multi em _tempvec " << endl ;
		//cout.precision(20);cout<< (funcaomulti(tempvec)) << endl ;
		//cout << "funcao multi em _x " << endl ;
		//cout.precision(20);cout<< (funcaomulti(_x)) << endl ;
		//cout << "tempdoub" << endl ; 
		//cout.precision(20);cout<< (funcaomulti(tempvec)-funcaomulti(_x))/_h <<endl ; 
		grad.push_back(tempdoub);

	}
	
	
	return grad;
}



// Calcula a Hessiana . Retorna a matriz quadrada hessiana calculada no vetor _x
double** MetNum::Hessiana( double _h)
{
	int tam = x.size();
	vector <double>tempvec , linha , mais , funcao , coluna  ;
	double tempdoub(0.0); 
	// gerando matriz 
	double**_H;
	_H= AlocaMatriz(tam,tam);
	funcao = gradiente(_h);

		for (int i=0;i<tam;i++) // numero de variaveis  CALCULANDO CADA COLUNA DA HESSIANA 
		{	
			tempvec.clear();
			tempvec=x;
			tempvec[i]+=_h;
			mais=gradiente(tempvec,_h); // calcula o gradiente da funcao 
			//cout <<"Imprimindo tempvec adicionei na posicao " <<  i <<  endl; 
			//ImprimeVetor(tempvec);
			//cout <<"Imprimindo mais " <<  i <<  endl; 
			//ImprimeVetor(mais);

			
			for (int j=0;j<tam;j++)
			{
				//tempvec2 = gradiente(tempvec,_h); 
				//cout << "Imprimindo grad" << endl ; 
				//ImprimeVetor(mais);
				//cout << "Imprimindo tempvec" << endl ; 
				//ImprimeVetor(tempvec);
				tempdoub=(mais.at(j)-funcao.at(j))/_h;
				
				coluna.push_back (tempdoub); // calcula a segunda derivada 
			}
			//cout << "Imprimindo a coluna da hessiana" << endl  ;
			//ImprimeVetor(coluna);
			// guarda coluna na matriz 
			for (int k=0;k<tam;k++)
			{
				_H[i][k]=coluna.at(k);
			}
			coluna.clear();
	  }
	//}
	//ImprimeMatriz(_H,tam,tam);	
	return _H;
}
