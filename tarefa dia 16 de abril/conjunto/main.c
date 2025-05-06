#include <stdio.h>
#include "conjunto.h"

int main() {
    Conjunto A = criar_conjunto();
    Conjunto B = criar_conjunto();

    inserir(&A, 1);
    inserir(&A, 2);
    inserir(&A, 3);
    inserir(&B, 3);
    inserir(&B, 4);
    inserir(&B, 5);

    printf("Uniao: ");
    Conjunto Uni = uniao(&A,&B);
    for (int i=0; i<Uni.tamanho; i++){
        printf("%d ",Uni.elementos[i]);
    }
    printf("\n");

    printf("Intersecao: ");
    Conjunto Inter = intersecao(&A,&B);
    for (int i=0; i<Inter.tamanho; i++){
        printf("%d ",Inter.elementos[i]);
        printf("\n");
    }

    return 0;
}