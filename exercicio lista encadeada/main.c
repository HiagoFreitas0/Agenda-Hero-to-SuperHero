#include <stdio.h>
#include "lista_encadeada.h"

int main() {
    ListaEncadeada* l1 = criar_lista();
    ListaEncadeada* l2 = criar_lista();

    inserir_lista(l1, 1);
    inserir_lista(l1, 2);
    inserir_lista(l1, 3);
    inserir_lista(l1, 4);
    
    inserir_lista(l2, 3);
    inserir_lista(l2, 4);
    inserir_lista(l2, 5);
    inserir_lista(l2, 6);

    puts("L1: ");
    imprimir_lista(l1);
    puts("L2: "); 
    imprimir_lista(l2);

    ListaEncadeada* concatenada = lista_concatenada(l1, l2);
    puts("Concatenada: "); 
    imprimir_lista(concatenada);

    ListaEncadeada* mesmo = filtrar_numeros_pares(l1);
    puts("Pares de L1: "); 
    imprimir_lista(mesmo);

    ListaEncadeada* unico = copiar_lista(l1);
    puts("Copia sem repetidos: "); 
    imprimir_lista(unico);

    ListaEncadeada* invertida = reverter_resultado(l1);
    puts("L1 invertida: "); 
    imprimir_lista(invertida);

    ListaEncadeada* merge = merge_ordenada(l1, l2);
    puts("Merge: "); 
    imprimir_lista(merge);

    ListaEncadeada* intersecao = intersecao_ordenada(l1, l2);
    printf("Intersecao: "); 
    imprimir_lista(intersecao);

    int pos, val;
    if(valor_maior(l1, &pos, &val)){
        printf("Maior de L1: %d na posicao %d\n", val, pos);
    }
    remover_primeiroN(l1, 2);
    puts("L1 apos remover 2 primeiros: "); 
    imprimir_lista(l1);

    liberar_lista(l1); 
    liberar_lista(l2); 
    liberar_lista(concatenada); 
    liberar_lista(mesmo);
    liberar_lista(unico); 
    liberar_lista(invertida);
    liberar_lista(merge); 
    liberar_lista(intersecao);

    return 0;
}