#include "metodosnum.h"

	///////////////////////////////////////////////////////
	///Encontra minimos (ou máximos ) atraves de métodos deterministicos 
	//
	// chave 0 = método da maxima descida  
	// chave 1 = metodo de newton Newton hibridizado com gradiente  


void MetNum::OtimizacaoDeterministica( double _epsilon , int _maxiter , int chave )
{

	double _h=0.0000001;
	int numiter(0);
	vector <double>  grad , alfa;
	double tempdoub(0.0),tempalfa(0);
	int tam = x.size();
	
	/// alterar essa hessiana para vector vector 
	double** _Hessiana;
	 
	for (int cont =0 ; cont < tam; cont ++ )
	{
		alfa.push_back(0.05);
	}
	
	grad=gradiente(_h);
	//cout << "Gradiente " << endl ; 
	//ImprimeVetor(grad) ;
	//cout << endl ; 
	double normagrad = norma(grad);

	if (chave==1) // calcula hessiana 
	{ 
	
		_Hessiana= Hessiana( _h);
		//cout << "Hessiana " << endl ; 
		//ImprimeMatriz(_Hessiana, 2 , 2 );
		//cout << endl ; 
	}

	while ( (normagrad>_epsilon) && (numiter<_maxiter) )
	{
		//cout << " P " << endl;
		//ImprimeVetor(p);
		//cout << " x " << endl;
		//ImprimeVetor();
		
		//cout << "Iteracao " << numiter <<  "  sol " <<funcaomulti(x) << endl ; 
		direcao.clear();

		if (chave==1) 
		{
			if (GaussSeidel(_Hessiana,grad,chute,100,0.001)) // tenta gaussseidel com 100 iteracoes 
			{
								
				//cout << "encontrou solucao " << endl;
				// se gausseidel resolveu direcao será newton 
				// testar o produto escalar 
				if (produtoescalar(grad,direcao) < 0.0 ) 
				{
					cout << "produto menor que zero  " << endl;
					// mantem direcao como newton 
					for (int i=0;i<tam ; i++)
					{
						tempdoub= x.at(i); // x0 
						tempdoub+=alfa.at(i)*direcao.at(i);
						x[i]=tempdoub;
						//cout <<"x " << i <<" " <<   _x[i] << endl ;
					}
				}
				else 
				{
					direcao.clear();
					for (int i=0;i<tam ; i++)
					{
						//cout << "produto maior que zero  " << endl;
						tempdoub = -1*grad.at(i)/normagrad; 
						direcao.push_back(tempdoub); // p0 
						tempdoub= x.at(i); // x0 
						tempdoub+=alfa.at(i)*direcao.at(i);
						x[i]=tempdoub;
						//cout <<"x " << i <<" " <<   _x[i] << endl ;
					}
				}
			}
			else 
			{
				//cout << "nao encontrou solucao " << endl;
				for (int i=0;i<tam ; i++)
				{
					tempdoub = -1*grad.at(i)/normagrad; 
					direcao.push_back(tempdoub); // p0 
					tempdoub= x.at(i); // x0 
					tempdoub+=alfa.at(i)*direcao.at(i);
					x[i]=tempdoub;
				//cout <<"x " << i <<" " <<   _x[i] << endl ;
				}
			}
		}
		if (chave==0) 
		{
			for (int i=0;i<tam ; i++)
			{
				tempdoub = -1*grad.at(i)/normagrad; 
				direcao.push_back(tempdoub); // p0 
				tempdoub= x.at(i); // x0 
				tempdoub+=alfa.at(i)*direcao.at(i);
				x[i]=tempdoub;
				//cout <<"x " << i <<" " <<   _x[i] << endl ;
			}
		}
		
		//ImprimeVetor(p);
		// calculos para proxima iteracao 
		
		grad.clear();
		grad=gradiente(_h);
		normagrad = norma(grad);
		numiter++;
		
	}
	EscreveArqFunc("saida.txt");
	
	cout << "Iteracao " << numiter << endl ; 

	cout << "Solucao encontrada " << endl ; 
	ImprimeVetor();
	//cout << "Valor da solucao encontrada " << endl ; 
	//cout << funcaomulti(x) << endl; ;
}