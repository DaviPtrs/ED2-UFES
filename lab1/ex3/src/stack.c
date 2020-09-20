#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

celulaPilha *criaCelulaNum(double x){
    celulaPilha *tronco = malloc(sizeof(celulaPilha));
    tronco->num = x;    
    tronco->operador=' ';
    tronco->prox = NULL;

    return tronco;
}

celulaPilha *criaCelulaOperador(char x){
    celulaPilha *tronco = malloc(sizeof(celulaPilha));
    tronco->operador = x;    
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

void printPilha(tPilha *litio){
    if(litio == NULL){
        printf("Pilha inexistente!\n");
        exit(1);
    }
    if(!pilhaVazia(litio)){
        celulaPilha *aux = litio->Topo;
        for(int i = 0; aux!=NULL; i++){
            if (aux->operador == ' '){
                printf("%dº operando: %c\n", i, aux->operador);
            }else{
                printf("%dº número: %f\n", i, aux->num);
            }
            aux = aux->prox;
        }
    }else{
        printf("A pilha está vazia!\n");
    }
}