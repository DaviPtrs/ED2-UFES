#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

typedef struct{
	int num;
	int marcado;
} Celula;


void initVetor(Celula *v, int N){
	for (int i = 0; i < N-1; i++){
		v[i].num = i+2;
		v[i].marcado = 0;
	}
}

void printVetor(Celula *v, int size){
	for (int i = 0; i < size-1; i++){
		Celula elem = v[i];
		printf("%d %d\n", elem.num, elem.marcado);
	}
}

void marcaTuto(Celula *v, int size){
	for (int i = 0; i < size-2; i++){
		Celula pivot = v[i];
		if(!pivot.marcado){
			for (int c = (i+1); c < size-1; c++){
				Celula elem = v[c];
				if(elem.num % pivot.num == 0){
					v[c].marcado = 1;
				}
			}
		}
	}
}

void printaPrimos(Celula *v, int size){
	for (int i = 0; i < size-1; i++){
		Celula elem = v[i];
		if(!elem.marcado){
			printf("%d ", elem.num);
		}
	}
	printf("\n");
}

int main(){
	int N;
	scanf("%d", &N);

	Celula vetor[N-1];

	initVetor(vetor, N);

	marcaTuto(vetor, N);

	printaPrimos(vetor, N);

	return 0;
}