#include <stdio.h>
#include "racional.h"

int main() {
    Racional raci1 = criar_racional(2, 2);
    Racional raci2 = criar_racional(3, 4);

    Racional soma = somar(raci1, raci2);
    Racional produto = multiplicar(raci1, raci2);

    printf("raci1 = ");
    imprimir(raci1);
    
    printf("raci2 = ");
    imprimir(raci2);

    printf("Soma: ");
    imprimir(soma);

    printf("Multiplicacao: ");
    imprimir(produto);

    if(sao_iguais(raci1, raci2)){
        printf("Sao iguais\n");
    }else{
        printf("Sao diferentes\n");
    }

    return 0;
}