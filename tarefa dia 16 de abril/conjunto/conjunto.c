#include "conjunto.h"

struct conjunto_dados{
    int elementos[MAX];
    int tamanho;
};


Conjunto criar_conjunto(){
    Conjunto c;
    c.tamanho = 0;
    return c;
}

int contem(Conjunto *c, int elem){
    for(int i=0; i<c->tamanho; i++){
        if(c->elementos[i] == elem)
        return 1;
    }
    return 0;
}

void inserir(Conjunto *c, int elem) {
    if(!contem(c, elem) && c->tamanho < MAX){
        c->elementos[c->tamanho++] = elem;
    }
}

void remover(Conjunto *c, int elem){
    for(int i=0; i<c->tamanho; i++){
        if(c->elementos[i] == elem){
            c->elementos[i] = c->elementos[c->tamanho - 1];
            c->tamanho--;
            return;
        }
    }
}

Conjunto intersecao(Conjunto *a, Conjunto *b){
    Conjunto res = criar_conjunto();
    for(int i=0; i<a->tamanho; i++){
        if(contem(b, a->elementos[i])){
            inserir(&res, a->elementos[i]);
        }
    }
    return res;
}

Conjunto diferenca(Conjunto *a, Conjunto *b){
    Conjunto res = criar_conjunto();
    for(int i=0; i<a->tamanho; i++){
        if(!contem(b, a->elementos[i])){
            inserir(&res, a->elementos[i]);
        }
    }
    return res;
}

Conjunto uniao(Conjunto *a, Conjunto *b){
    Conjunto res = criar_conjunto();
    for(int i = 0; i < a->tamanho; i++){
        inserir(&res, a->elementos[i]);
    }
    for(int i = 0; i < b->tamanho; i++){
        inserir(&res, b->elementos[i]);
    }
    return res;
}

int maior_valor(Conjunto *c){
    int maior = c->elementos[0];
    for(int i=1; i<c->tamanho; i++){
        if(c->elementos[i] > maior)
            maior = c->elementos[i];
    }
    return maior;
}

int menor_valor(Conjunto *c){
    int menor = c->elementos[0];
    for(int i=1; i<c->tamanho; i++){
        if(c->elementos[i] < menor)
            menor = c->elementos[i];
    }
    return menor;
}

int sao_iguais(Conjunto *a, Conjunto *b){
    if(a->tamanho != b->tamanho)
    return 0;
    for(int i = 0; i < a->tamanho; i++){
        if(!contem(b, a->elementos[i]))
        return 0;
    }
    return 1;
}

int tamanho(Conjunto *c){
    return c->tamanho;
}

int esta_vazio(Conjunto *c){
    return c->tamanho == 0;
}