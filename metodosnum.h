
/// Cabecalhos das funcoes

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <complex>
#define PI 3.141592653589;
using namespace std;


// utils


class MetNum{

public:
		MetNum()	{srand(time(0));}	// construtor
public:
	vector <double> x ,  // x é multidimensional
					z ,  // z é F(x_k)
					chute ,
					direcao; // vetor da direcao dos metodos de otimizacao

	vector <int>   tammatriz;
	vector< vector<double> >::iterator iter_ii;
	vector<double>::iterator             iter_jj; // iteradores
	vector< vector<double> > Matriz ;    // array multidimensional

	////////////////////////
	// derivadas
	///////////////////////
	double** Hessiana( double _h);
	double** AlocaMatriz  (int tamx, int tamy);
	vector< vector<double> >  InicializaMatriz  (   int tamx, int tamy);
	///////////////////////
	//utils
	/////////////////////////
	double norma();
	double norma(vector <double> );
	// gera numdados dados entre liminf e lim sup e guarda em x da classe
	void Gera_dados ( double _liminf , double _limsup , int _numdados );
	vector <double>  Gera_dadosRetorna ( double _liminf , double _limsup , int _numdados );
	void Gera_Grid ( double _liminfx ,double _limsupx  ,  double _liminfy ,double _limsupy , double _espacamento );

	void ImprimeVetor ();
	void ImprimeVetor (vector <double>);
	void EscreveVetArq(const string filename) ;
	void EscreveArqFunc(const string filename);
	vector <double> gradiente( double _h);
	vector <double> gradiente( vector <double> _x ,double _h);
	double produtoescalar(vector <double> , vector <double>);
	vector< vector<double> > ProdutoMatriz(vector< vector<double> > , vector< vector<double> >);
	vector<int> SizeMatriz (vector< vector<double> >) ;

	//////////////////////////////////////
	// Pega o vetor x e z da classe e imprime em arquivo passando pelo funcao RnR1 pronto para ser plotado
	// entradas nome do arquivo , x , z,  numpontos , limite inferior  , limite superior
	////////////////////////////////////
	void PlotaRnR1(const string filename, vector <double > x, vector <double > z , int numpontos  , double liminf , double  limsup) ;

	/////////////////////////
	//metodos
	/////////////////////////
	//  Host_Bissecao
	//liminf,limsup,numiter,limiar
	//
	void Host_Bissecao(double _liminf,double _limsup,double _numiter,double _limiar);

	// secante
	//
	void Host_Secante (double _x0 , double _x1,int _numiter, double _limiar);
	// Newton
	//
	void Host_Newton (double _x0 , int _numiter, double _limiar);
	// Newton Mdoficado
	void Host_NewtonModificado (double _x0 , int _numiter, double _limiar);
	//Newton Corrigido
	//
	void Host_NewtonCorrigido (double _x0 , int _numiter, double _limiar);
	/// muller : Buscador de raizes
	///
	void Host_Muller (double _x0 ,double _x1 ,double _x2,  int _numiter);
	///Simpson : Resolve integrais
	//
	void Host_Simpson(double  , double );
	/// Interpolação de Lagrange
	// recebe dois vetores de entrada contendo x e f(x) = y e interpola
	void Host_Interp_Lagrange(vector <double>,vector <double> );
	///Interpolacao FFT não funcionando ...
	//
	void FFT(vector <double> _x, vector <double>_y, int m );
	/////////////////////////////////////////////////
	// resolve integrais.
	//  entrada : a e b , limite de inicio e fim da integracao
	//  dependencia: F -> uma funcao a ser integrada
	//				 o valor de n (tamanho da coluna)
	//				fornece a precisao e só pode ser alterada
	//				de dentro do codigo pois eh const int
	//  retorno : o valor da integral definida
	////////////////////////////////////////////////////
	double Romberg(double  , double );

	///////////////////////////////////////////////////////
	///Encontra minimos (ou máximos ) atraves de métodos deterministicos
	//
	// chave 0 = método da maxima descida
	// chave 1 = metodo de newton Newton hibridizado com gradiente
	void  OtimizacaoDeterministica( double _epsilon , int _maxiter , int _chave);

	///Soluciona Ax = B
	//	requer diagonal dominante
	// matriz a , matriz solucao ,  chute inicial , numero de iteracoes , tolerancia
	bool GaussSeidel (double**_A,vector <double> sol,vector <double> chute,const int &_maxiter, const double &_tol);
	///
	//

	///Soluciona Ax = B
	//	requer Matriz A como diagonal superior ou inferior
	vector <double> SistemaTriangular( vector <double> sol);

	double Jacobi (double**_A,const double*_b,const double*_x,const int &_tamanho, const int &_max, const double &_tol);

	~MetNum() // destrutor
	{
	};

};
	void EscreveDoisVetArq(const string filename, vector <double > x, vector <double > y) ;
	double Elevado ( double _n, int _p);
	double fatorial(const int &_n);
	//verifica se a atual iteracao é igual a anterior
	double AlteraPouco2(vector <double> novox , vector <double> _x  );

	void ImprimeMatriz (double**_H , int altura ,int  largura ) ;
	void ImprimeMatriz (vector< vector<double> >) ;

	double AlteraPouco(const double *_novox , const double*_x , const int &_n);

	double quad(double &);
	double F(double );
	double funcao(double );
	double funcaomulti(vector <double> _x);

	double derivadaavancada (double _x,double _h);
	double derivadaanalitica(double _x);
	double derivadasegunda (double _x, double _h);

	double derivadasegundaavancada (double _x, double _h);





//
	//

