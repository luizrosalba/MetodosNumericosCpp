/* 
 * File:   Jacobi.h
 * Author: rosalba
 *
 * Created on 5 de Junho de 2010, 23:22
 */

#ifndef _JACOBI_H
#define	_JACOBI_H


#include <iostream>
#include <cmath>

//a * b = c

double Jacobi (double**,const double*,const double*,const int &, const int &, const double &);
// matriz a , matriz b ,  chute inicial ,tamanho da matriz, numero de iteracoes , tolerancia
double AlteraPouco(const double* , const double* , const int &) ; // condição de parada

#endif	/* _JACOBI_H */

