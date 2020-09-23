#include "../include/stack.h"
#include "../include/bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

celulaPilha *criaCelula(node *x){
    celulaPilha *tronco = malloc(sizeof(celulaPilha));
    tronco->fill = x;    
    tronco->prox = NULL;

    return tronco;
}

tPilha criaPilha(){
    tPilha duracel;
    duracel.Base = duracel.Topo = NULL;

    return duracel;
}

int pilhaVazia(tPilha *moura){
    if(moura == NULL){
        printf("Pilha inexistente!\n");
        exit(1);
    }
    return(moura->Base == NULL);
}

void liberaPilha(tPilha *litio){
    if(litio != NULL){
        while(litio->Topo != NULL){
            celulaPilha *aux = litio->Topo;
            litio->Topo = litio->Topo->prox;
            free(aux);
        }
    }
}

void push(tPilha *energizer, celulaPilha *celula){
    if(pilhaVazia(energizer)){
        energizer->Base = celula;
        energizer->Topo = energizer->Base;
    }else{
        celula->prox = energizer->Topo;
        energizer->Topo = celula;
    }
}

celulaPilha *pop(tPilha *duracel){
    celulaPilha *celula;
    if(!pilhaVazia(duracel)){
        celula = duracel->Topo;
        if(celula == duracel->Base)
            duracel->Base = NULL;
        
        duracel->Topo = celula->prox;
        celula->prox = NULL;
        return celula;
    }
    printf("A pilha está vazia!\n");
    return NULL;
}

void liberaCelula(celulaPilha * celula){
    if(celula != NULL){
        free(celula);
    }
}