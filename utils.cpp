#include "metodosnum.h"
/// funcoes uteis 


double quad(double &_x)
{
	
		return _x*_x;
}

double Elevado ( double _n, int _p)
{
     if(_p==0) return ((double)1.0); // este double é necessario para dar a precisao 
     if(_p > 0) return ((_n * Elevado(_n,_p-1)));
     return Elevado( 1.0 / _n ,  - _p - 1 )/ _n ;
}

void MetNum::Gera_Grid ( double _liminfx ,double _limsupx  ,  double _liminfy ,double _limsupy , double _espacamento )
{

	double contx(_liminfx) , conty(_liminfy) ; 
	ofstream out("teste.dat",ios::out|ios::app);

	while (conty< _limsupy)
	{
		while (contx<_limsupx) 
		{
			contx+=_espacamento ; 
			out << contx  << "   " << conty  << "  "  ;
			x.push_back(contx);
			x.push_back(conty);
			out << funcaomulti(x) << endl;
			x.clear();

		}
		contx = _liminfx; 
		conty+=_espacamento ; 
	}
	
	out.close();
	
}

// gera numdados dados entre liminf e lim sup 
void MetNum::Gera_dados ( double _liminf,double _limsup , int _numdados )
{
   
	double aux,temp(0.0);
	for (int i=0 ; i< _numdados; i++)
	{
		aux = (_limsup-_liminf)/RAND_MAX ;
		temp= _liminf + ( rand() *aux);
		x.push_back(temp);
	}
}
// gera numdados dados entre liminf e lim sup 
vector <double> MetNum::Gera_dadosRetorna ( double _liminf,double _limsup , int _numdados )
{
	vector <double> saida; 
    srand(time(0));
	double aux,temp(0.0);
	for (int i=0 ; i< _numdados; i++)
	{
		aux = (_limsup-_liminf)/RAND_MAX ;
		temp= _liminf + ( rand() *aux);
		saida.push_back(temp);
	}
	return saida;
}
// Imprime um vetor qualquer 
void MetNum::ImprimeVetor () 
{
	cout << "( " ;  
	for (int i=0;i<x.size();i++)
	{
		cout << setprecision(10) << x.at(i) << " " ;
		//cout <<  "Posicao " << i << " valor " << ent.at(i) << endl ;
	}
	cout << ")"<<endl ;
}

void MetNum::ImprimeVetor (vector <double> _x) 
{
	cout << "( " ;  
	for (int i=0;i<_x.size();i++)
	{
		cout << setprecision(10) << _x.at(i) << " " ;
		//cout <<  "Posicao " << i << " valor " << ent.at(i) << endl ;
	}
	cout << ")"<<endl ;
}

void ImprimeMatriz (double**_H , int altura ,int  largura ) 
{
	cout << "Imprimi" << endl ;
	
	for (int i=0 ; i < altura ; i++)
    {
		for (int j=0 ; j < largura ; j++)
		{
			cout << _H[i][j] << " " ;
		}
         cout << endl ;
    }

}

void ImprimeMatriz (vector< vector<double> > ent) 
{
	
	vector< vector<double> >::iterator iter_ii;
	 vector<double>::iterator    iter_jj;

	cout << "Imprimi" << endl ;
	

	 for(iter_ii=ent.begin(); iter_ii!=ent.end(); iter_ii++)
   {
      for(iter_jj=(*iter_ii).begin(); iter_jj!=(*iter_ii).end(); iter_jj++)
      {
         cout << *iter_jj << " ";
      }
	  cout << endl ; 
   }


}
double** MetNum::AlocaMatriz  (int tamx, int tamy) 
{
	// gerando matriz 
	double**_H;
	_H = new double*[tamx];
    for (int i=0 ; i < tamy ; i++)
    {
            _H[i]=new double [tamy];

    }

	for (int i=0 ; i < tamy ; i++)
    {
       for (int j=0 ; j < tamy ; j++)
		{
            _H[i][j]=0.0;

		 }
	}

	return _H;
}

//Escreve dois vetores em um arquivo 
void EscreveDoisVetArq(const string filename, vector <double > x, vector <double > y) 
{
	ofstream out(filename.c_str(),ios::out|ios::trunc);
	int tament= x.size();
	for (int i=0;i<tament;i++)
	{
		out << x.at(i) << "   " << y.at(i) << endl;
	}
	out.close();
}

//Escreve um vetor em um arquivo 
void MetNum::EscreveVetArq(const string filename ) 
{
	ofstream out(filename.c_str(),ios::out|ios::trunc);
	int tament= x.size();
	for (int i=0;i<tament;i++)
	{
		out << x.at(i) << "   " << endl;
	}
	out.close();
}

// Escreve um vetor x e sua funcao 

void MetNum::EscreveArqFunc(const string filename) 
{
	
	ofstream out(filename.c_str(),ios::out|ios::app);
	
	int tament= x.size();
	for (int i=0;i<tament;i++)
	{
		out << x.at(i) << "   " ;
	}

	out << funcaomulti(x) << endl;
	
	out.close();
}


double fatorial(const int &_n)
{
    if(_n<=1) return 1;
    return _n*fatorial(_n-1);
}

// calcula a norma de um vetor 
double MetNum::norma()
{

	int tam = x.size();
	double temp(0.0);
    for (int i=0;i < tam; i++)
	{
		temp+=Elevado(x.at(i),2);
	}
	return (sqrt(temp));

}
double MetNum::norma( vector <double > _x)
{

	int tam = _x.size();
	double temp(0.0);
    for (int i=0;i < tam; i++)
	{
		temp+=Elevado(_x.at(i),2);
	}
	return (sqrt(temp));

}

double AlteraPouco(const double *_novox , const double*_x , const int &_n)
{
    double taxa(0);

    for (int i=0;i<_n;i++)
    {     
        taxa+= (_novox[i]-_x[i]) * (_novox[i]-_x[i]) ;   
    }
    
    return sqrt(taxa);
}

double MetNum::produtoescalar(vector <double> _a  , vector <double> _b)
{

	int tam = _a.size();
	double somatorio(0.0);
	for (int i =0 ; i < tam ; i++)
	{
		somatorio+=(_a.at(i)*_b.at(i));
		
	}
	return (somatorio);
}

 vector< vector<double> >  MetNum::InicializaMatriz  (  int tamx, int tamy)
{
	 vector<double> temp;
	
	 vector< vector<double> > entra ; 
	 for (int col = 0 ; col<tamy; col++) // coluna de B  
	 {
			temp.push_back(0.0);
			
	 }
	
	for (int lin = 0 ; lin<tamx; lin++) // linha de A 
	{
		entra.push_back(temp);
	}
	
	return entra; 
	
}

vector< vector<double> > MetNum::ProdutoMatriz(vector< vector<double> > A, vector< vector<double> > B )
{
	vector<int> sizeA , sizeB ; 
	vector< vector<double> > C ;
	sizeA= SizeMatriz(A);
	sizeB= SizeMatriz(B);
	double temp(0.0) ; 
	int colB(0);
	if (sizeA.at(1)!=sizeB.at(0)) // 
	{
		cout << "impossivel multiplicar matrizes" <<endl ;
	}
	else 
	{
		C = InicializaMatriz(sizeA.at(1),sizeB.at(0));
		
		for (int largA = 0 ; largA<sizeA.at(0); largA++) // linha de A 
		{
			for (colB = 0 ; colB<sizeB.at(1); colB++) // coluna de B  
			{
				for (int r=0 ; r < sizeA.at(1) ; r++) 
				{
					temp += A[largA][r] * B[r][colB];
				}
				C[largA][colB]=temp;
				temp=0.0;
			}
		}
	}
	 
	
	ImprimeMatriz(C);
	

	return C ; 

}

// 1 posicao do vetor de retorno - altura 2 posicao largura 
vector<int> MetNum::SizeMatriz (vector< vector<double> > A ) 
{
	int linA(0) , colA(0); 
	linA = A.size();
	vector<int> saida;

   iter_ii=A.begin();
   for(iter_jj=(*iter_ii).begin(); iter_jj!=(*iter_ii).end(); iter_jj++)
   {
		  colA++ ;
		
         //cout << (*iter_jj) << " ";
   }
   saida.push_back(linA);
   saida.push_back(colA);
   return saida;
	  //cout << endl ; 
   
  // cout <<linA <<  " " << colA << endl ; 
}