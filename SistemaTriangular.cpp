#include "metodosnum.h"

/// Encontra a solucao x de um sistema A x = b 
/// quando A é tringular superior ou inferior 
///

vector <double> MetNum::SistemaTriangular( vector <double> sol)
{

	vector <double> saida; // vetor de solucao do sistema A 
	int n = sol.size(); // tamanho do vetor solucao
	saida.assign(n,0.0);//aloca n posicoes no vetor de saida contendo 0.0 
	saida[n-1] = sol.at(n-1) / Matriz[n-1][n-1];
	double soma= 0.0;


	for (int k = (n-2); k>=0;k--)
	{
		soma = sol.at(k);
		for (int j=k+1;j<=n-1;j++)
		{
			soma -=Matriz[k][j]*saida[j];
		}
		if (Matriz[k][k] < 0.0000001) 
		{
			cout << "Erro , diagonal possui 0, impossivel resolver sistema triangular " << endl ; 
		}
		else 
		{
			saida[k]=soma/Matriz[k][k];
		}
		soma =0.0;
	}
	
	
	
	return saida;
}