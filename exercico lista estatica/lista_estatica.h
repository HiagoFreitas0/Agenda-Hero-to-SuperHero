#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#define MAX 100

typedef struct Estatica listaEstatica;

/**
 * Cria uma nova lista estatica vazia
 * @return Ponteiro para a nova lista criada, ou NULL em caso de erro
 */
listaEstatica* criar_lista();

/**
 * Retorna o número de elementos na lista
 * @param lista Ponteiro para a lista
 * @return Quantidade de elementos na lista
 */
int tamanho_lista(const listaEstatica *lista);


/**
 * Libera a memoria alocada para a lista
 * @param lista Ponteiro para a lista a ser liberada
 */
void liberar_lista(listaEstatica *lista);

/**
 * Reinicializa a lista, tornando ele vazia
 * @param lista Ponteiro para a lista a ser reinicializada
 */
void inicializar_lista(listaEstatica *lista);

/**
 * Insere um valor no final da lista
 * @param lista Ponteiro para a lista
 * @param valor Valor a ser inserido
 * @return 1 se inserido com sucesso, 0 se a lista estiver cheia
 */
int inserir(listaEstatica *lista, int valor);

/**
 * Remove a primeira ocorrencia do valor da lista
 * @param lista Ponteiro para a lista
 * @param valor Valor a ser removido
 * @return 1 se removido com sucesso, 0 se não encontrado
 */
int remover_valor(listaEstatica *lista, int valor);

/**
 * Procura por um valor na lista
 * @param lista Ponteiro constante para a lista
 * @param valor Valor a ser procurado
 * @return 1 se encontrado, 0 caso não encontrar
 */
int procurar(const listaEstatica *lista, int valor);

/**
 * Imprime os elementos da lista na tela
 * @param lista Ponteiro constante para a lista
 */
void imprimir_lista(const listaEstatica *lista);

/**
 * Concatena duas listas usando funções do TAD
 * @param l1 Ponteiro para a primeira lista
 * @param l2 Ponteiro para a segunda lista
 * @return Nova lista com os elementos concatenados, ou NULL se alguma for NULL
 */
listaEstatica* concatenar_usando_funcoes(const listaEstatica *l1, const listaEstatica *l2);

/**
 * Concatena duas listas manualmente, sem chamar outras funções do TAD
 * @param l1 Ponteiro para a primeira lista
 * @param l2 Ponteiro para a segunda lista
 * @return Nova lista com os elementos concatenados, ou NULL em caso de erro
 */
listaEstatica*concatenar_sem_funcoes(listaEstatica *l1, listaEstatica *l2);

/**
 * Remove os n primeiros elementos da lista e retorna a posição e valor do maior deles
 * @param lista Ponteiro para a lista
 * @param n Quantidade de elementos a considerar
 * @param pos Ponteiro para armazenar a posição do maior valor
 * @param val Ponteiro para armazenar o maior valor
 * @return 1 se sucesso, 0 se a lista estiver vazia
 */
int remover_primeiroN(listaEstatica *lista, int n, int *pos, int *val);

/**
 * Encontra o maior valor da lista e sua posição
 * @param lista Ponteiro constante para a lista
 * @param pos Ponteiro para armazenar a posição do maior valor
 * @param val Ponteiro para armazenar o maior valor
 * @return 1 se sucesso, 0 se a lista estiver vazia
 */
int valor_maior(const listaEstatica *lista, int *pos, int *val);

/**
 * Filtra e retorna uma nova lista contendo apenas os valores pares
 * @param lista Ponteiro constante para a lista
 * @return Nova lista contendo apenas os pares
 */
listaEstatica* filtrar_numero_pares(const listaEstatica *lista);

/**
 * Copia todos os elementos da lista sem duplicados
 * @param lista Ponteiro constante para a lista
 * @return Nova lista com os elementos unicos
 */
listaEstatica* copiar_lista(const listaEstatica *lista);

/**
 * Retorna uma nova lista com os elementos da original em ordem reversa
 * @param lista Ponteiro constante para a lista
 * @return Nova lista revertida
 */
listaEstatica* reverter_resultado(const listaEstatica *lista);

/**
 * Une duas listas ordenadas em uma nova lista, sem repetir elementos
 * @param l1 Ponteiro para a primeira lista ordenada
 * @param l2 Ponteiro para a segunda lista ordenada
 * @return Nova lista ordenada com união sem repetição
 */
listaEstatica* merge_ordenada(const listaEstatica *l1, const listaEstatica *l2);

/**
 * Retorna a interseção entre duas listas ordenadas, sem repetir elementos
 * @param l1 Ponteiro para a primeira lista ordenada
 * @param l2 Ponteiro para a segunda lista ordenada
 * @return Nova lista com os elementos em comum
 */
listaEstatica* intersecao_ordenada(const listaEstatica *l1, const listaEstatica *l2);

/**
 * Verifica se um valor existe na lista
 * @param lista Ponteiro constante para a lista
 * @param val Valor a ser procurado
 * @return 1 se o valor existir, 0 caso não exista
 */
int existe(const listaEstatica *lista, int val);

#endif
