#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "../include/bintree.h"

int main(){
	binTree *x = newBinTree();

	insert_BinTree(x, 5);
	insert_BinTree(x, 7);
	insert_BinTree(x, 3);
	insert_BinTree(x, 6);
	insert_BinTree(x, 4);

	freeBinTree(x);

	return 0;
}