/*direttive al preprocessore*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void parse(int numArg, char* argument[], float *v1, float *v2, char *op);

void elabora(float v1, float v2, char o, float *r);

void visualizza(float v1, float v2, char o, float r);
/*prova*/

int main(int argc, char* argv[]){
	float n1,n2;
	char op;
	float ris;
	
	parse(argc,argv,&n1,&n2,&op);
	
	elabora(n1,n2,op,&ris);
	
	visualizza(n1,n2,op,ris);
	
	return 0;
}

void parse(int numArg, char* argument[], float *v1, float *v2, char *op){
	if(numArg!=4){
		printf("Error usage: %s <val1> <op> <val2>",argument[0]);
		exit(-1);
	}
	*op=argument[2][0];
	if (*op!='+' && *op!='-' && *op!='*'){
		printf("Error usage: %s <val1> <op> <val2>",argument[0]);
		exit(-2);
	}
	sscanf(argument[1],"%f",v1);
	sscanf(argument[3],"%f",v2);
}


void elabora(float v1, float v2, char o, float *r){
	switch (o){
		case '+':
			*r=v1+v2;
			break;
		case '-':
			*r=v1-v2;
			break;
		case '*':
			*r=v1*v2;
			break;
	}
}


void visualizza(float v1, float v2, char o, float r){
	printf("\n%.2f %c %.2f = %.2f\n",v1,o,v2,r);
}	
