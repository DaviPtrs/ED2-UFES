#ifndef PILHA_H_
#define PILHA_H_
#define MAXTAM 50
#define DOUBLE 0
#define CHAR 1

typedef struct celulaPilha celulaPilha;
typedef struct node node;

struct celulaPilha{
	node *fill;
	celulaPilha* prox;
};

typedef struct{
	celulaPilha *Base;
	celulaPilha *Topo;
} tPilha;


celulaPilha *criaCelula(node *);

tPilha criaPilha();

int pilhaVazia(tPilha *);

void liberaPilha(tPilha *);

void liberaCelula(celulaPilha *);

void push(tPilha *, celulaPilha *);

celulaPilha *pop(tPilha *);

#endif /* PILHA_H_ */