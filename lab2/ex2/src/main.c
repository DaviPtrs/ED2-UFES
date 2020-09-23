#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "../include/bintree.h"

int main(int argc, char const *argv[]){

	srand(time(NULL));

	if(argc < 2){
		printf("Missing argument");
		exit(1);
	}

	char *c = argv[1];
  	int N = atoi(c);


	binTree *x = newBinTree();

	for (int i = 0; i < N; i++){
		int key = rand();
		insert_BinTree(x, key);
	}
	
	printf("Height: %d\n", height_BinTree(x));

	freeBinTree(x);

	return 0;
}
