#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>


struct _lista{
    No* head;
};

struct _no{
    int valor;
    No* prox;
};

ListaEncadeada* criar_lista(){
    ListaEncadeada *novo = malloc(sizeof(ListaEncadeada));
    if(novo)
    novo->head = NULL;
    return novo;
}

void liberar_lista(ListaEncadeada *lista){
    if(!lista)
    return;
    No* cur = lista->head;
    while(cur){
        No* temp = cur;
        cur = cur->prox;
        free(temp);
    }
    free(lista);
}

int inserir_lista(ListaEncadeada *lista, int valor){
    if(!lista) 
    return 0;
    No* novo = malloc(sizeof(No));
    if(!novo) 
    return 0;
    novo->valor = valor;
    novo->prox = NULL;

    if(!lista->head){
        lista->head = novo;
    }else{
        No* cur = lista->head;
        while(cur->prox) 
        cur = cur->prox;
        cur->prox = novo;
    }
    return 1;
}

void imprimir_lista(ListaEncadeada *lista){
    if(!lista) 
    return;
    No* cur = lista->head;
    while(cur){
    printf("%d -> ", cur->valor);
    cur = cur->prox;
    }           
    printf("NULL\n");
}

ListaEncadeada* lista_concatenada(ListaEncadeada *l1, ListaEncadeada *l2){
    ListaEncadeada* novo = criar_lista();
    No* cur;
    for(cur = l1->head; cur; cur = cur->prox){
        inserir_lista(novo, cur->valor);
    }
    for(cur = l2->head; cur; cur = cur->prox){
        inserir_lista(novo, cur->valor);
    }
    return novo;
}

ListaEncadeada* remover_primeiroN(ListaEncadeada *lista, int n){
    if(!lista) 
    return 0;
    while(lista->head && n--){
        No* temp = lista->head;
        lista->head = temp->prox;
        free(temp);
    }
    return lista;
}

int valor_maior(const ListaEncadeada *lista, int *pos, int *val){
    if(!lista || !lista->head) 
    return 0;
    int maior = lista->head->valor, p = 0, i = 0;
    No* cur = lista->head;
    while(cur){
        if(cur->valor > maior){
            maior = cur->valor;
            p = i;
        }
        i++;
        cur = cur->prox;
    }
    *pos = p;
    *val = maior;
    return 1;
}

ListaEncadeada* filtrar_numeros_pares(const ListaEncadeada *lista){
    ListaEncadeada* novo = criar_lista();
    for(No* cur = lista->head; cur; cur = cur->prox){
        if (cur->valor % 2 == 0){
            inserir_lista(novo, cur->valor);
        }
    }
    return novo;
}

int existe_na_lista(const ListaEncadeada* lista, int val){
    for(No* cur = lista->head; cur; cur = cur->prox){
        if(cur->valor == val){
            return 1;
        }
    }
    return 0;
}

ListaEncadeada* copiar_lista(ListaEncadeada *lista){
    ListaEncadeada* novo = criar_lista();
    for(No* cur = lista->head; cur; cur = cur->prox){
        if(!existe_na_lista(novo, cur->valor)){
            inserir_lista(novo, cur->valor);
        }
    }
    return novo;
}

ListaEncadeada* reverter_resultado(const ListaEncadeada *lista){
    ListaEncadeada* novo = criar_lista();
    for(No* cur = lista->head; cur; cur = cur->prox){
        No* no = malloc(sizeof(No));
        no->valor = cur->valor;
        no->prox = novo->head;
        novo->head = no;
    }
    return novo;
}

ListaEncadeada* merge_ordenada(const ListaEncadeada *l1, const ListaEncadeada *l2){
    ListaEncadeada* novo = criar_lista();
    No* cur = l1->head;
    while(cur){
        if(!existe_na_lista(novo, cur->valor)){
            inserir_lista(novo, cur->valor);
        }
        cur = cur->prox;
    }
    cur = l2->head;
    while(cur){
        if(!existe_na_lista(novo, cur->valor)){
            inserir_lista(novo, cur->valor);
        }
        cur = cur->prox;
    }
    for(No* i = novo->head; i; i = i->prox){
        for(No* j = i->prox; j; j = j->prox){
            if(i->valor > j->valor){
                int tmp = i->valor;
                i->valor = j->valor;
                j->valor = tmp;
            }
        }
    }

    return novo;
}

ListaEncadeada* intersecao_ordenada(const ListaEncadeada *l1, const ListaEncadeada *l2){
    ListaEncadeada* resultado = criar_lista();
    for(No* cur = l1->head; cur; cur = cur->prox){
        if (existe_na_lista(l2, cur->valor) && !existe_na_lista(resultado, cur->valor)){
            inserir_lista(resultado, cur->valor);
        }
    }
    return resultado;
}
