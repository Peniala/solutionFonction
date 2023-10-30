#include "solution_fonction.h"

double f(double x){
	//~ return (9*x + 56);
	return -log(x) + 1;
}

// Dichotomie
// si f(a)*f(b) < 0 fait dichotomie sinon pas de solution
double dichotomie(double a,double b){
	double a1 = 0.0;
	/// if(f(a)*f(b) < 0){
	while(fabs(f(a)-f(b)) > 0.00001){
		a1 = (a+b)/2;
		printf("<tr>\n");
		printf("<td>%f</td>\n",a);
		printf("<td>%f</td>\n",b);
		printf("<td>%f</td>\n",a1);
		printf("<td>%f</td>\n",f(a1));
		printf("</tr>\n");
		if(f(a)*f(a1) <= 0){
			b = a1;
		}
		else{
			a = a1;
		}
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
	// double i1 = a, i2 = b;
	// if(f(b) < 0){
	// 	i1 = b;
	// 	i2 = a;
	// }
	double tmp = 0.0;
	while(fabs(f(b)) > 0.00001 && a!=b){
 		double* c = coeff(a,f(a),b,f(b));
 		tmp = b;
		b = point_Secante(c[0],c[1]);
		printf("<tr>\n");
		printf("<td>%f</td>\n",a);
		printf("<td>%f</td>\n",tmp);
		printf("<td>%f</td>\n",b);
		printf("<td>%f</td>\n",f(b));
		printf("</tr>\n");
 	}
	return b;
}

// Méthode tangente
// si a n'appartient pas à a;b donc pas de solution

/// equation de la tangente f'(xo)(x - xo) + f(xo)
double derive_au_point(double xo){
	return -1/xo;
}
double point_tangente(double xo){
	return (-f(xo)/derive_au_point(xo)) + xo;
}
double solution_tangente(double a){
	double tmp = 0.0;
	while(fabs(f(a)) > 0.00001){
		tmp = a;
		a = point_tangente(a);
		printf("<tr>\n");
		printf("<td>%f</td>\n",tmp);
		printf("<td>%f</td>\n",a);
		printf("<td>%f</td>\n",f(a));
		printf("</tr>\n");
	}
	return a;
}

/// Tableau
void tableIteration(double a,double b,char* method){
	if(f(a)*f(b) < 0){
		if(strcmp(method,"dicho")==0){
			printf("<table>\n");
			printf("<tr id=\"entete\">\n");
			printf("<td>a</td>\n");
			printf("<td>b</td>\n");
			printf("<td>a1 : between a,b</td>\n");
			printf("<td>f(a1)</td>\n");
			printf("</tr>\n");

			dichotomie(a,b);

			printf("</table>\n");
		}
		else if(strcmp(method,"newton")==0){
			printf("<table>\n");
			printf("<tr id=\"entete\">\n");
			printf("<td>a</td>\n");
			printf("<td>Intersection of T(a)</td>\n");
			printf("<td>f(t)</td>\n");
			printf("</tr>\n");

			solution_tangente(a);

			printf("</table>\n");
		}
		else if(strcmp(method,"descartes")==0){
			printf("<table>\n");
			printf("<tr id=\"entete\">\n");
			printf("<td>a</td>\n");
			printf("<td>b</td>\n");
			printf("<td>Intersection of (ab)</td>\n");
			printf("<td>f(d)</td>\n");
			printf("</tr>\n");

			solution_secante(a,b);

			printf("</table>\n");
		}
	}
	else {
		printf("<h1 id=\"pasSolution\">Pas de solution dans l'intervalle [ %lf ; %lf ]</h1>\n",a,b);
	}
}

/// compter le nombre d'iteration
// int countApproximation(){
// 	FILE* file = fopen("solution.txt","r");
// 	int c = 0;
// 	char ligne[300];

// 	if(file == NULL){
// 		exit(1);
// 	}

// 	while(fgets(ligne,300,file)!=NULL){
// 		c++;
// 	}

// 	fclose(file);
// 	return c;
// }


// void tableIteration(char* method){
// 	FILE* file = fopen("solution.txt","r");
// 	char ligne[300];

// 	if(file == NULL){
// 		exit(1);
// 	}
// 	while(fgets)
// 	fclose(file);
// }
