#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/circle_list.h"

void splinterPrint(){
	printf("=-=-=-=-=-=-=-=-=-=-=-=\n");
}

// Elimina e retorna o elemento eliminado
int elimina(int M, CellPointer *pointer){
	CellPointer elem = NULL;
	for (int i = 0; i < M; i++){
		if(i==0){
			elem = *pointer;
		}else{
			elem = elem->Next;
		}
	}
	*pointer = elem;
	return elem->num;	
}

int main(int argc, char const *argv[]){
	if(argc <= 1){
		printf("Nenhum argumento fornecido.\n");
		exit(1);
	}

	int N = atoi(argv[1]);
	int M = atoi(argv[2]);

	printf("N: %d\n", N);
	printf("M: %d\n", M);

	CircleList list = newCircleList();
	makeEmpty(&list);

	for (int i = 0; i < N; i++){
		insert(i+1, &list);
	}

	splinterPrint();
	printf("Lista inicial:\n");
	printList(&list);
	splinterPrint();

	CellPointer pointer = list.First;
	printf("Eliminados: \n");
	while (list.First != list.Last)
	{
		int eliminado = elimina(M, &pointer);
		printf("%d ", eliminado);
		pointer = pointer->Next;
		removeElem(eliminado, &list);
	}
	printf("\n");

	splinterPrint();
	printf("Escolhido: %d\n", list.First->num);

	freeList(&list);

	return 0;
}