#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

int main() {
    int opcao;
    Agenda* agenda = criar_agenda();

    carregar_contatos(agenda);

    do {
        printf("1 - adicionar novo contato\n");
        printf("2 - imprimir agenda\n");
        printf("3 - deletar contato\n");
        printf("4 - salvar contatos\n");
        printf("5 - sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: {
                char nome[MAX_NOME];
                char telefone[MAX_TELEFONE];

                puts("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                puts("Telefone (ex: 63 99999-9999): ");
                fgets(telefone, sizeof(telefone), stdin);
                telefone[strcspn(telefone, "\n")] = '\0';
                adicionar_contato(agenda, nome, telefone);
                break;
            }
            case 2:
                imprimir_agenda(agenda);
                break;

            case 3: {
                char nome[MAX_NOME];
                puts("Nome a deletar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                deletar_contato(agenda, nome);
                break;
            }
            case 4:
            salvar_contatos(agenda);
            break;
            case 5:
                if (agenda_foi_alterada()) {
                    puts("Deseja salvar suas alterações? (s/n): ");
                    char resposta;
                    scanf(" %c", &resposta);
                    if (resposta == 's' || resposta == 'S') {
                        salvar_contatos(agenda);
                    }
                }
                puts("Saindo...");
                break;
        }
    }while (opcao != 5);
    liberar_agenda(agenda);
    return 0;
}