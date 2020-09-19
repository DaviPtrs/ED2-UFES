#ifndef listCIRC_H_
#define listCIRC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell *CellPointer;

typedef struct Cell {
  int num;
  CellPointer Next;
} Cell;

typedef struct {
  CellPointer First, Last;
} CircleList;

CircleList newCircleList();

/* Faz a lista ficar vazia */
void makeEmpty(CircleList *list);

/*Verifica se a lista esta vazia*/
int isEmpty(CircleList *list);

/* Insere x apos o ultimo elemento da lista */
void insert(int x, CircleList *list);

/*Retira um elemento da lista */
void removeElem(int num, CircleList *list);

CellPointer searchNum(int num, CircleList *list);

/*Imprime a lista */
void printList(CircleList *list);

void freeList(CircleList *list);

#endif /* listCIRC_H_ */