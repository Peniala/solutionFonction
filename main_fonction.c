#include "solution_fonction.h"

int main(){
	printf("Content-Type: text/html\n\n");
	
	char fonction[200] = "1 - ln(x)";
	char ligne[300];
	char* url = getenv("QUERY_STRING");
	double a = 0, b= 0; // intervalle
	char method[20];

	// printf("Par dichotomie : %f\n",dichotomie(a,b));
	// printf("Par la méthode de Newton : %f\n",solution_tangente(a));
	// printf("Par la méthode de Descartes : %f\n",solution_secante(a,b));
	
	sscanf(url,"a=%lf&b=%lf&method=%s",&a,&b,method);
	
	FILE* file = fopen("solution.html","r");

	if(file == NULL){
		exit(1);
	}
	while(fgets(ligne,300,file)!=NULL){
		if(strstr(ligne,"<section>") != NULL){
			printf("%s\n",ligne);
			printf("<div id=\"fonction\"><h1>f(x) = %s</h1></div>\n",fonction);
			
			tableIteration(a,b,method);
		}
		else{
			printf("%s\n",ligne);
		}
	}
	fclose(file);
	return 0;
}
