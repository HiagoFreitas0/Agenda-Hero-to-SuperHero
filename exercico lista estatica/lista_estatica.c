#include "LISTA_ESTATICA.h"
#include <stdlib.h>
#include <stdio.h>

struct Estatica {
    int data[MAX];
    int size;
};

listaEstatica* criar_lista(){
    listaEstatica *nova = malloc(sizeof(listaEstatica));
    if(nova != NULL)
    nova->size = 0;
    return nova;
}

int tamanho_lista(const listaEstatica *lista){
    return lista->size;
}

void liberar_lista(listaEstatica *lista){
    free(lista);
}

void inicializar_lista (listaEstatica *lista){
    lista->size = 0;
}

int inserir (listaEstatica *lista, int valor){
    if(lista->size >=MAX)
    return 0;
    lista ->data[lista->size++] = valor;
    return 1;
}

int remover_valor (listaEstatica *lista, int valor){
    int i, fundar = 0;
    for(i=0; i<lista->size; i++){
        if(lista->data[i] == valor){
            fundar = 1;
            break;
        }
    }
    if(!fundar)
    return 0;
    for(; i < lista->size - 1; i++){
        lista->data[i] = lista->data[i+1];
    }
    lista->size--;
    return 1;
}

int procurar (const listaEstatica *lista, int valor){
    for(int i=0; i<lista->size; i++){
        if(lista->data[i] == valor){
          return 1;
        }
    }
    return 0;
}

void imprimir_lista (const listaEstatica *lista){
    if(lista == NULL){
        puts("lista nula");
        return;
    }
    puts("lista: ");
    for(int i=0; i<lista->size; i++){
        printf("%d ", lista->data[i]);
    }
    puts(" ");
}

listaEstatica* concatenar_usando_funcoes(const listaEstatica *l1, const listaEstatica *l2){
    if(l1 == NULL || l2 == NULL){
        return NULL;
    }

    listaEstatica *resultado = criar_lista();
    if(resultado == NULL){
        return NULL;
    }
    for(int i=0; i<l1->size; i++){
        inserir(resultado,l1->data[i]);
    }
    for(int i=0; i<l2->size; i++){
        inserir(resultado,l2->data[i]);
    }
    return resultado;
}

listaEstatica* concatenar_sem_funcoes(listaEstatica *l1, listaEstatica *l2){
    if(l1 == NULL || l2 == NULL){
        return NULL;
    }
    listaEstatica *nova = criar_lista();
    if(nova == NULL) 
    return NULL;

    int total=l1->size + l2->size;
    if(total > MAX) 
    total=MAX;

    int i=0;
    for(; i<l1->size && i<MAX; i++){
        nova->data[i] = l1->data[i];
    }
    for(int j=0; j<l2->size && i<MAX; j++, i++){
        nova->data[i] = l2->data[j];
    }
    nova->size = i;

    return nova;
}

int remover_primeiroN(listaEstatica *lista, int n, int *pos, int *val){
    if(lista == NULL || pos == NULL || val == NULL || lista->size == 0 || n <= 0){
        return 0;
    }
    if(n>lista->size){
        n = lista->size;
    }
    *val = lista->data[0];
    *pos = 0;

    for(int i=1; i<n; i++){
        if(lista->data[i] > *val){
            *val = lista->data[i];
            *pos = i;
        }
    }
    for(int i = n; i < lista->size; i++){
        lista->data[i - n] = lista->data[i];
    }
    lista->size -= n;

    return 1;
}

int valor_maior(const listaEstatica *lista, int *pos, int *val){
    if(lista == NULL || lista->size == 0 || pos == NULL || val == NULL){
        return 0;
    }
    *val = lista->data[0];
    *pos = 0;
    for(int i=0; i<lista->size; i++){
        if(lista->data[i]>*val){
            *val = lista->data[i];
            *pos = i;
        }
    }
    return 1;
}

listaEstatica* filtrar_numero_pares(const listaEstatica *lista){
   listaEstatica *resultado = criar_lista();
   if(lista == NULL) 
   return NULL;
   for(int i=0; i< lista->size; i++){
    if(lista->data[i] % 2 == 0)
    inserir(resultado, lista->data[i]);
   }
   return resultado;
}

int existe(const listaEstatica *lista, int val){
    for(int i=0; i<lista->size; i++){
        if(lista->data[i] == val)
        return 1;
    }
    return 0;
}

listaEstatica* copiar_lista(const listaEstatica *lista){
    listaEstatica *resultado = criar_lista();
    if(lista == NULL) 
    return NULL;
    for(int i=0; i< lista->size; i++){
        if(!existe(resultado,lista->data[i])){
            inserir(resultado, lista->data[i]);
        }
    }
    return resultado;
}

listaEstatica* reverter_resultado(const listaEstatica *lista){
    listaEstatica *resultado = criar_lista();
    if(lista == NULL) 
    return NULL;
    for(int i=lista->size - 1; i>=0; i--){
        inserir(resultado, lista->data[i]);
    }
    return resultado;

}

listaEstatica* merge_ordenada(const listaEstatica *l1, const listaEstatica *l2){
    listaEstatica *resultado = criar_lista();
    if(l1 == NULL || l2 == NULL)
    return NULL;
    int i=0, j=0;
    while(i<l1->size && j<l2->size){
        int val = (l1->data[i] < l2->data[j]) ? l1->data[i++] : l2->data[j++];
        if(!existe(resultado,val)) 
        inserir(resultado,val);
    }
    while(i < l1->size){
        if(!existe(resultado,l1->data[i])) 
        inserir(resultado,l1->data[i]);
        i++;
    }
    while(j<l2->size){
        if(!existe(resultado,l2->data[j])) 
        inserir(resultado,l2->data[j]);
        j++;
    }
    return resultado;
}

listaEstatica* intersecao_ordenada(const listaEstatica *l1, const listaEstatica *l2){
    listaEstatica *resultado = criar_lista();
    if(l1 == NULL || l2 == NULL) 
    return NULL;
    for (int i=0; i<l1->size; i++){
        if(existe(l2, l1->data[i]) && !existe(resultado, l1->data[i])){
            inserir(resultado,l1->data[i]);
        }
    }
    return resultado;
}