#include "solution_fonction.h"

int main(){
	double a = 0.001, b= 300; // intervalle
	printf("Par dichotomie : %f\n",dichotomie(a,b));
	printf("Par la méthode de Newton : %f\n",solution_tangente(a));
	printf("Par la méthode de Descartes : %f\n",solution_secante(a,b));
	return 0;
}
