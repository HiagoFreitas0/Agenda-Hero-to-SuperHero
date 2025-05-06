#ifndef CONJUNTO_H
#define CONJUNTO_H

#define MAX 100

/**
 * Struct que representa um conjunto de números inteiros
 * armazenados em um vetor com tamanho definido em 100
 */
typedef struct {
    int elementos[MAX];  // Vetor que armazena os elementos do conjunto
    int tamanho;  // Quantidade de elementos no conjunto
} Conjunto; 


/**
 * Cria e retorna um conjunto vazio
 * @return conjunto instancia de conjunto inicializada vazia
 */
Conjunto criar_conjunto();

/**
 * Verifica se um elemento pertence ao conjunto
 * @param c ponteiro para o conjunto
 * @param elem elemento a ser verificado
 * @return int 1 se o elemento está presente, 0 caso contrario
 */
int contem(Conjunto *c, int elem);

/**
 * Insere um elemento no conjunto, se ele ainda não estiver presente
 * @param c ponteiro para o conjunto
 * @param elem elemento a ser inserido
 */
void inserir(Conjunto *c, int elem);

/**
 * Remove um elemento do conjunto, se ele existir
 * @param c ponteiro para o conjunto
 * @param elem elemento a ser removido
 */
void remover(Conjunto *c, int elem);

/**
 * Calcula a interseção entre dois conjuntos
 * @param a ponteiro para o primeiro conjunto
 * @param b ponteiro para o segundo conjunto
 * @return conjunto contendo os elementos comuns entre a e b
 */
Conjunto intersecao(Conjunto *a, Conjunto *b);

/**
 * Calcula a diferença entre dois conjuntos a - b
 * @param a ponteiro para o conjunto base
 * @param b ponteiro para o conjunto a ser subtraído
 * @return conjunto com os elementos que estão em a e não estão em b
 */
Conjunto diferenca(Conjunto *a, Conjunto *b);

/**
 * Calcula a união entre os dois conjuntos
 * @param a ponteiro para o primeiro conjunto
 * @param b ponteiro para o segundo conjunto
 * @return conjunto contendo todos os elementos de a e b (sem repetições)
 */
Conjunto uniao(Conjunto *a, Conjunto *b);

/**
 * Retorna o maior valor do conjunto
 * @param c ponteiro para o conjunto
 * @return int maior valor contido no conjunto
 */
int maior_valor(Conjunto *c);

/**
 * Retorna o menor valor do conjunto
 * @param c ponteiro para o conjunto
 * @return int menor valor contido no conjunto
 */
int menor_valor(Conjunto *c);

/**
 * Verifica se dois conjuntos são iguais
 * @param a ponteiro para o primeiro conjunto
 * @param b ponteiro para o segundo conjunto
 * @return int 1 se os conjuntos possuem os mesmos elementos, 0 caso contrario
 */
int sao_iguais(Conjunto *a, Conjunto *b);

/**
 * Retorna o tamanho (quantidade de elementos) do conjunto
 * @param c ponteiro para o conjunto
 * @return int quantidade de elementos no conjunto
 */
int tamanho(Conjunto *c);

/**
 * Verifica se o conjunto está vazio
 * @param c ponteiro para o conjunto
 * @return int 1 se o conjunto estiver vazio, 0 caso contrario
 */
int esta_vazio(Conjunto *c);


#endif