#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdbool.h>

#define MAX 100

typedef struct list Conjunto;

Conjunto criar_conjunto();

bool inserir(Conjunto *c, int elem);
bool remover(Conjunto *c, int elem);
int buscar(Conjunto *c, int elem);

Conjunto interseccao(Conjunto *a, Conjunto *b);
Conjunto diferenca(Conjunto *a, Conjunto *b);
Conjunto uniao(Conjunto *a, Conjunto *b);

int maior(Conjunto *c);
int menor(Conjunto *c);
bool iguais(Conjunto *a, Conjunto *b);
int tamanho(Conjunto *c);
bool vazio(Conjunto *c);

#endif
