#ifndef FONCT
#define FONCT

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x);

/// dichotomie
double dichotomie(double a,double b);

/// méthode sécante
double* coeff(double x1,double y1,double x2,double y2);
double point_Secante(double a, double b);
double solution_secante(double a, double b);

/// méthode tangente
double derive_au_point(double xo);
double point_tangente(double xo);
double solution_tangente(double a);

#endif
