#ifndef RACIONAL_H
#define RACIONAL_H

/**
 * Struct que representa um número racional (fração)
 */
typedef struct {
    int numerador;    // Parte de cima da fração
    int denominador;  // Parte de baixo da fração
} Racional;

/**
 * Cria um número racional
 * @param num numerador
 * @param den denominador
 * @return racional número racional criado
 */
Racional criar_racional(int num, int den);


/**
 * Soma dois números racionais
 * @param a primeiro número racional
 * @param b segundo número racional
 * @return racional resultado da soma
 */
Racional somar(Racional a, Racional b);


/**
 * Multiplica dois números racionais
 * @param a primeiro número racional
 * @param b segundo número racional
 * @return racional resultado da multiplicação
 */
Racional multiplicar(Racional a, Racional b);


/**
 * Compara dois números racionais
 * @param a primeiro número racional
 * @param b segundo número racional
 * @return int 1 se forem iguais, 0 caso contrario
 */
int sao_iguais(Racional a, Racional b);


/**
 * Imprime um número racional
 * @param raci Número racional a ser impresso
 */
void imprimir(Racional raci);


#endif

