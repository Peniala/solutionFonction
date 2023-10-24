#include "solution_fonction.h"

double f(double x){
	//~ return (9*x + 56);
	return -log(x) + 1;
}

// Dichotomie
// si fabs(f(a)-f(b)) > 0.00001 fait dichotomie sinon pas de solution
double dichotomie(double a,double b){
	double a1 = 0.0;
	if(f(a)*f(b) < 0){
		while(fabs(f(a)-f(b)) > 0.00001){
			a1 = (a+b)/2;
			if(f(a)*f(a1) < 0){
				b = a1;
			}
			else{
				a = a1;
			}
		}
	}
	else{
		printf("Pas de solution");
	}
	return a1;
}

// Méthode sécante
// si i1 n'appartient pas à a,b pas de solution
double* coeff(double x1,double y1,double x2,double y2){
	double* c = malloc(2*sizeof(double));
	c[0] = (y1 - y2)/(x1 - x2);
 	c[1] = y1 - c[0]*x1;
 	return c;
}
double point_Secante(double a, double b){
	return (-b/a);
}
double solution_secante(double a, double b){
	while(fabs(f(a)) > 0.00001 && fabs(f(b)) > 0.00001){
 		double* c = coeff(a,f(a),b,f(b));
 		if(f(a)<0){
			a = point_Secante(c[0],c[1]);
		}
		else{
			b = point_Secante(c[0],c[1]);
		}
 	}
	return a;
}

// Méthode tangente
// si a n'appartient pas à a;b donc pas de solution

/// equation de la tangente f'(xo)(x - xo) + f(xo)
double derive_au_point(double xo){
	return -(1/xo);
}
double point_tangente(double xo){
	return (-f(xo)/derive_au_point(xo)) + xo;
}
double solution_tangente(double a){
	while(fabs(f(a)) > 0.00001){
		a = point_tangente(a);
	}
	return a;
}
