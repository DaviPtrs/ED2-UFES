#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/circle_list.h"
#include <stdbool.h>

CircleList newCircleList(){
    CircleList list;
    list.First = NULL;
	list.Last = NULL;

    return list;
}

/* Faz a lista ficar vazia */
void makeEmpty(CircleList *list){
	if(!isEmpty(list)){
        list->First = list->Last = NULL;
    }
}

/*Verifica se a lista esta vazia*/
int isEmpty(CircleList *list){
        return ((list->First == NULL) && (list->Last == NULL));
}

/* Insere x apos o ultimo elemento da lista */
void insert(int x, CircleList *list){
    if(isEmpty(list)){
		list->First = (CellPointer) malloc(sizeof(Cell));
		list->First->num = x;
		list->Last = list->First;
        list->Last->Next = list->First;
	}else{
        CellPointer newCell = (CellPointer) malloc(sizeof(Cell));
        newCell->num = x;
        newCell->Next = list->First;
        list->Last->Next = newCell;
        list->Last = newCell;
		
	}
}

/*Retira um elemento da lista */
void removeElem(int x, CircleList *list){
    if(isEmpty(list)){
        printf("Elemento não encontrado\n");
    }else{
        CellPointer prevElem = NULL;
        for(CellPointer elem = list->First; prevElem != list->Last ; elem = elem->Next){
            if(elem->num == x){
                if(elem == list->First){
                    list->First = list->First->Next;
                    list->Last->Next = list->First;
                }else if(elem == list->Last){
                    prevElem->Next = list->First;
                    list->Last = prevElem;
                }else{
                    prevElem->Next = elem->Next;
                }
                free(elem);
                return;
            }else{
                prevElem = elem;
            }
        }
        printf("Elemento não encontrado\n");
    }
}

/*Imprime a lista */
void printList(CircleList *list){
    CellPointer prevElem = NULL;
    for(CellPointer elem = list->First; prevElem != list->Last ; elem = elem->Next){
        printf("%d\n", elem->num);
        prevElem = elem;
    }
}

CellPointer searchNum(int x, CircleList *list){
    CellPointer prevElem = NULL;
    for(CellPointer elem = list->First; prevElem != list->Last ; elem = elem->Next){
        if(elem->num == x){
            return elem;
        }
        prevElem = elem;
    }
    return NULL;

}
 
void freeList(CircleList *list){
	CellPointer backup = NULL;
	while(list->First != NULL){
		backup = list->First;
        if(list->First->Next != list->Last){
		    list->First = list->First->Next;
        }else{
            list->First = NULL;
        }
		free(backup);
	}
}