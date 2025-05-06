#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

#define MAX_CONTATOS 50
#define MAX_NOME 128
#define MAX_TELEFONE 15
#define ARQUIVO "agenda.csv"

typedef struct {
    char nome[MAX_NOME];
    char telefone[MAX_TELEFONE];
} Contato;

struct _no {
    Contato info;
    struct _no* prox;
};

struct _agenda {
    No* head;
};

static int alterado = 0;

Agenda* criar_agenda() {
    Agenda* nova = malloc(sizeof(Agenda));
    if (nova) {
        nova->head = NULL;
    }
    return nova;
}

void carregar_contatos(Agenda* agenda) {
    FILE* file = fopen(ARQUIVO, "r");
    if (!file) 
    return;

    char nome[MAX_NOME], telefone[MAX_TELEFONE];
    while (fscanf(file, " %127[^,],%14[^\n]\n", nome, telefone) == 2) {
        adicionar_contato(agenda, nome, telefone);
    }
    fclose(file);
}

void salvar_contatos(Agenda* agenda) {
    FILE* file = fopen(ARQUIVO, "w");
    if (!file) {
        puts("Erro ao salvar");
        return;
    }

    for (No* atual = agenda->head; atual != NULL; atual = atual->prox) {
        fprintf(file, "%s,%s\n", atual->info.nome, atual->info.telefone);
    }

    fclose(file);
    alterado = 0;
    puts("Seus contatos foram salvos");
}

void adicionar_contato(Agenda* agenda, const char* nome, const char* telefone) {
    No* novo = malloc(sizeof(No));
    if (!novo) {
        puts("Erro de memória");
        return;
    }
    strcpy(novo->info.nome, nome);
    strcpy(novo->info.telefone, telefone);
    novo->prox = agenda->head;
    agenda->head = novo;
    alterado = 1;
}

void imprimir_agenda(Agenda* agenda) {
    if (!agenda->head) {
        puts("Agenda vazia");
        return;
    }
    puts("Contatos na agenda:");
    No* atual = agenda->head;
    int i = 1;
    while (atual) {
        printf("%d %s - %s\n\n", i++, atual->info.nome, atual->info.telefone);
        atual = atual->prox;
    }
}

void deletar_contato(Agenda* agenda, const char* nome) {
    No* atual = agenda->head;
    No* anterior = NULL;

    while (atual) {
        if (strcmp(atual->info.nome, nome) == 0) {
            if (anterior) {
                anterior->prox = atual->prox;
            } else {
                agenda->head = atual->prox;
            }
            free(atual);
            alterado = 1;
            puts("Contato removido");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    puts("Contato não encontrado");
}

void liberar_agenda(Agenda* agenda) {
    No* atual = agenda->head;
    while (atual) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(agenda);
}

int agenda_foi_alterada() {
    return alterado;
}

void set_agenda_alterada(int valor) {
    alterado = valor;
}