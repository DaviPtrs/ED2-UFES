#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    int key;
    node *left, *right;
};


typedef struct{
    node *head;
} binTree;

binTree *newBinTree();

node *newNode(int);

int isEmpty_BinTree(binTree *);

int insert_BinTree(binTree *, int);

int search_BinTree(binTree *, int);

void freeBinTree(binTree *);



