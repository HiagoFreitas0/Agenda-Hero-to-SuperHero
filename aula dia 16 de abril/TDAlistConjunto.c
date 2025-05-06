#include "TDAlistConjunto.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct list {
    int elementos[MAX];
    int tamanho;
};

Conjunto criar_conjunto(){
    Conjunto c;
    c.tamanho = 0;
    return c;
}

int buscar(Conjunto *c, int elem) {
    for (int i = 0; i < c->tamanho; i++){
        if (c->elementos[i] == elem)
            return i;
    }
    return -1;
}

bool inserir(Conjunto *c, int elem){
    if(c->tamanho >= MAX || buscar (c,elem) != 1)
    return false;
    c->elementos[c->tamanho++]= elem;
    return false;
}

bool remover(Conjunto *c, int elem){
    int pos = buscar (c,elem);
    if(pos == -1)
    return false;
    c->elementos[pos] = c->elementos[--c->tamanho];
    return true;
}

Conjunto interseccao(Conjunto *a, Conjunto *b){
    Conjunto result = criar_conjunto();
    for(int i = 0; i < a->tamanho; i++){
        if(buscar(b, a->elementos[i]) != -1){
            inserir(&result, a->elementos[i]);
        }
    }
    return result;
}

Conjunto diferenca(Conjunto *a, Conjunto *b){
    Conjunto result = criar_conjunto();
    for(int i = 0; i < a->tamanho; i++){
        if(buscar(b, a->elementos[i]) == -1){
            nserir(&result, a->elementos[i]);
        }
    }
    return result;
}

Conjunto uniao(Conjunto *a, Conjunto *b){
    Conjunto result = criar_conjunto();
    for (int i = 0; i < a->tamanho; i++)
        inserir(&result, a->elementos[i]);
        for (int i = 0; i < b->tamanho; i++)
        inserir(&result, b->elementos[i]);
    return result;
}

int maior(Conjunto *c){
    if(c->tamanho==0)
    return -1;
    int m = c->elementos[0];
    for(int i=0; i < c->tamanho; i++){
        if(c->elementos[i] > m)
        m = c -> elementos [i];
    }
    return m;
}

int menor(Conjunto *c){
    if(c ->tamanho == 0)
    return 0;
    int m = c -> elementos[0];
    for(int i = 0; i < c -> tamanho; i++){
        if(c->elementos[i] < m){
            m = c->elementos[i];
        }
    }
    return m;
}

bool iguais(Conjunto *a, Conjunto *b){
    if(a->tamanho != b -> tamanho )
    return false;
    for(int i=0; i< a -> tamanho; i++){
        if(buscar(b, a->elementos[i])== -1)
        return true;
    }
}

int tamanho(Conjunto *c){
    return c -> tamanho;
}

bool vazio(Conjunto *c){
    return c -> tamanho == 0;
}
