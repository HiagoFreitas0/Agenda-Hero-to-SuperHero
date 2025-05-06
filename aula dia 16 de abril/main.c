#include "TDAlistConjunto.h"
#include <stdio.h>

int main() {
    Conjunto A = criar_conjunto();
    Conjunto B = criar_conjunto();

    // Inserção
    inserir(&A, 1);
    inserir(&A, 2);
    inserir(&A, 3);

    inserir(&B, 3);
    inserir(&B, 4);
    inserir(&B, 5);

    printf("Conjunto A: ");
    for (int i = 0; i < A.tamanho; i++)
        printf("%d ", A.elementos[i]);
    printf("\n");

    printf("Conjunto B: ");
    for (int i = 0; i < B.tamanho; i++)
        printf("%d ", B.elementos[i]);
    printf("\n");

    // Interseção
    Conjunto I = interseccao(&A, &B);
    printf("Interseção A ∩ B: ");
    for (int i = 0; i < I.tamanho; i++)
        printf("%d ", I.elementos[i]);
    printf("\n");

    // Diferença A - B
    Conjunto D = diferenca(&A, &B);
    printf("Diferença A - B: ");
    for (int i = 0; i < D.tamanho; i++)
        printf("%d ", D.elementos[i]);
    printf("\n");

    // União
    Conjunto U = uniao(&A, &B);
    printf("União A ∪ B: ");
    for (int i = 0; i < U.tamanho; i++)
        printf("%d ", U.elementos[i]);
    printf("\n");

    // Maior e menor
    printf("Maior de A: %d\n", maior(&A));
    printf("Menor de B: %d\n", menor(&B));

    // Igualdade
    printf("A e B são iguais? %s\n", iguais(&A, &B) ? "Sim" : "Não");

    // Tamanho e vazio
    printf("Tamanho de A: %d\n", tamanho(&A));
    printf("A está vazio? %s\n", vazio(&A) ? "Sim" : "Não");

    // Remoção
    printf("Removendo 2 de A...\n");
    remover(&A, 2);
    printf("Conjunto A: ");
    for (int i = 0; i < A.tamanho; i++)
        printf("%d ", A.elementos[i]);
    printf("\n");

    return 0;
}