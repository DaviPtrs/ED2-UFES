#ifndef PILHA_H_
#define PILHA_H_
#define MAXTAM 50
#define DOUBLE 0
#define CHAR 1

typedef struct celulaPilha celulaPilha;

struct celulaPilha{
	double num;
    char operador;
	celulaPilha* prox;
};

typedef struct{
	celulaPilha *Base;
	celulaPilha *Topo;
} tPilha;

celulaPilha *criaCelulaOperador(char);

celulaPilha *criaCelulaNum(double);

tPilha criaPilha();

int pilhaVazia(tPilha *);

void liberaPilha(tPilha *);

void liberaCelula(celulaPilha *);

void push(tPilha *, celulaPilha *);

celulaPilha *pop(tPilha *);

void printPilha(tPilha *);

#endif /* PILHA_H_ */