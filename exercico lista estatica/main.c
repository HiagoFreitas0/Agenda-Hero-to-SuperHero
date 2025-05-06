#include "LISTA_ESTATICA.h"
#include <stdio.h>

int main(){
    listaEstatica *l1 = criar_lista();
    listaEstatica *l2 = criar_lista();
    listaEstatica *resultado;
    int pos,val;

    for (int i=1; i<=5; i++){
        inserir(l1,i);
    }
    for (int i=3; i<=8; i++){
        inserir(l2,i);
    }

    puts("lista 1: ");
    imprimir_lista(l1);
    puts("lista 2: ");
    imprimir_lista(l2);

    puts("(teste com sucesso) concatenar usando funcoes: ");
    resultado=concatenar_usando_funcoes(l1,l2);
    if(resultado != NULL && tamanho_lista(resultado) == tamanho_lista(l1) + tamanho_lista(l2)){
        puts("Passou no teste de sucesso");
    }else{
        puts("Erro: falha no teste de sucesso");
    }
    imprimir_lista(resultado);
    liberar_lista(resultado);

    puts("(teste com falha) concatenar usando funcoes: ");
    resultado=concatenar_usando_funcoes(NULL,l2);
    if(resultado == NULL){
        puts("Passou no teste de falha com l1 NULL");
    }else{
        puts("Erro: deveria ter retornado NULL com l1 NULL");
        liberar_lista(resultado);
    }

    resultado=concatenar_usando_funcoes(l1,NULL);
    if(resultado == NULL){
        puts("Passou no teste de falha com l2 NULL");
    }else{
        puts("Erro: deveria ter retornado NULL com l2 NULL");
        liberar_lista(resultado);
    }

    resultado=concatenar_usando_funcoes(NULL,NULL);
    if(resultado == NULL){
        puts("Passou no teste de falha com ambas NULL");
    }else{
        puts("Erro: deveria ter retornado NULL com ambas NULL");
        liberar_lista(resultado);
    }

    puts("concatenar sem usar funcoes: ");
    resultado = concatenar_sem_funcoes(l1,l2);
    imprimir_lista(resultado);
    liberar_lista(resultado);

    puts("remover os 2 primeiros elemenstos do l1: ");
    if(remover_valor(l1,2)){
        puts("removido com sucesso");
    }else{
        puts("valor nao encontrado");
    }
    imprimir_lista(l1);
    
    puts("maior elemento de l2: ");
    if(valor_maior(l2,&pos,&val)){
        printf("maior: %d naposicao %d\n",val,pos);
    }else{
        puts("lista vazia");
    }

    puts("filtar pares de l2: ");
    resultado = filtrar_numero_pares(l2);
    imprimir_lista(resultado);
    liberar_lista(resultado);

    puts("copiar l2 sem repetidos: ");
    resultado = copiar_lista(l2);
    imprimir_lista(resultado);
    liberar_lista(resultado);

    puts("merge ordenado de l1 e l2 sem repeticao: ");
    resultado = merge_ordenada(l1,l2);
    imprimir_lista(resultado);
    liberar_lista(resultado);
    
    puts("intersecao de l1 e l2: ");
    resultado = intersecao_ordenada(l1,l2);
    imprimir_lista(resultado);
    liberar_lista(resultado);

    liberar_lista(l1);
    liberar_lista(l2);

    return 0;

}