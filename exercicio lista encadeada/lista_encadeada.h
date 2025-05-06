#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct _lista ListaEncadeada;
typedef struct _no No;

ListaEncadeada* criar_lista();
void liberar_lista(ListaEncadeada *lista);
int inserir_lista(ListaEncadeada *lista, int valor);
void imprimir_lista(ListaEncadeada *lista);

ListaEncadeada* lista_concatenada(ListaEncadeada *l1, ListaEncadeada *l2);
ListaEncadeada* remover_primeiroN(ListaEncadeada *lista, int n);
int valor_maior(const ListaEncadeada *lista, int *pos, int *val);
ListaEncadeada* filtrar_numeros_pares(const ListaEncadeada *lista);
ListaEncadeada* copiar_lista(ListaEncadeada *lista);
ListaEncadeada* reverter_resultado(const ListaEncadeada *lista);
ListaEncadeada* merge_ordenada(const ListaEncadeada *l1, const ListaEncadeada *l2);
ListaEncadeada* intersecao_ordenada(const ListaEncadeada *l1, const ListaEncadeada *l2);



#endif
