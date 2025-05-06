#include "racional.h"
#include <stdio.h>

Racional criar_racional(int num, int den){
    Racional raci;
    raci.numerador = num;
    raci.denominador = den;
    return raci;
}

Racional somar(Racional a, Racional b){
    Racional resultado;
    resultado.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

Racional multiplicar(Racional a, Racional b){
    Racional resultado;
    resultado.numerador = a.numerador * b.numerador;
    resultado.denominador = a.denominador * b.denominador;
    return resultado;
}

int sao_iguais(Racional a, Racional b){
    return (a.numerador * b.denominador == b.numerador * a.denominador);
}

void imprimir(Racional raci){
    printf("%d/%d\n", raci.numerador, raci.denominador);
}