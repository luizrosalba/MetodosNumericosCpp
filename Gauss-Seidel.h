/* 
 * File:   Gauss-Seidel.h
 * Author: rosalba
 *
 * Created on 6 de Junho de 2010, 12:30
 */

#ifndef _GAUSS_SEIDEL_H
#define	_GAUSS_SEIDEL_H
#include<iostream>
#include<cmath>


double GaussSeidel(double**,const double*,const double*,const int &, const int &, const double &);
// matriz a , matriz b ,  chute inicial ,tamanho da matriz, numero de iteracoes , tolerancia
double AlteraPouco2(const double* , const double* , const int &) ; // condição de parada


#endif	/* _GAUSS_SEIDEL_H */

