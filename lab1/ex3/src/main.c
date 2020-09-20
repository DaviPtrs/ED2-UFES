#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "../include/stack.h"
#include <ctype.h>

void splinterPrint(){
	printf("=-=-=-=-=-=-=-=-=-=-=-=\n");
}

int isOperator(char c){
	return ((c == '/') || (c == '*') || (c == '-') || (c == '+'));
}

int opera(double n1, double n2, char operador){
	switch (operador){
	case '*':
		return n1 * n2;
	case '/':
		return n1 / n2;
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	}
}

int main(int argc, char const *argv[]){
	if(argc <= 1){
		printf("Nenhum argumento fornecido.\n");
		exit(1);
	}

	char *expression = argv[1];
	int readingNumFlag = 0;
	int num;
	tPilha operadores = criaPilha();
	tPilha numeros = criaPilha();
	for (size_t i = 0; i < strlen(expression); i++)
	{
		char c = expression[i];
		if (!((c == '(') || (c == ' '))){
			if(isdigit(c)){
				if(!readingNumFlag){
					readingNumFlag = 1;
					num = atoi(&c);
				}else{
					num = num * 10;
					num = num + atoi(&c);
				}
			}else if(isOperator(c)){
				readingNumFlag = 0;
				// printf("Empilha %c\n", c);
				push(&operadores, criaCelulaOperador(c));
			}else if(c == ')'){
				readingNumFlag = 0;
				celulaPilha *n1Cell = pop(&numeros);
				double n1 = n1Cell->num;
				free(n1Cell);
				celulaPilha *n2Cell = pop(&numeros);
				double n2 = n2Cell->num;
				free(n2Cell);
				celulaPilha *opCell = pop(&operadores);
				char operador = opCell->operador;
				free(opCell);
				double resultado = opera(n1,n2,operador);
				push(&numeros, criaCelulaNum(resultado));
			}else{
				printf("Syntax error\n");
				liberaPilha(&operadores);
				liberaPilha(&numeros);
				exit(1);
			}
		}else{
			if(readingNumFlag){
				// printf("Empilha %d\n", num);
				push(&numeros, criaCelulaNum((double)num));
				readingNumFlag = 0;
			}
		}
	}
	if(numeros.Base == numeros.Topo){
		printf("Resultado: %f\n", numeros.Base->num);
	}else{
		printf("Deu ruim\n");
	}

	liberaPilha(&operadores);
	liberaPilha(&numeros);
	
	
	return 0;
}