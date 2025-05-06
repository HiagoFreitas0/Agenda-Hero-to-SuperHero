#ifndef CONTATO_H
#define CONTATO_H

#define MAX_NOME 128
#define MAX_TELEFONE 15
#define ARQUIVO "agenda.csv"

typedef struct _agenda Agenda;
typedef struct _no No;

Agenda* criar_agenda();
void carregar_contatos(Agenda* agenda);
void salvar_contatos(Agenda* agenda);
void adicionar_contato(Agenda* agenda, const char* nome, const char* telefone);
void imprimir_agenda(Agenda* agenda);
void deletar_contato(Agenda* agenda, const char* nome);
void liberar_agenda(Agenda* agenda);
int agenda_foi_alterada();
void set_agenda_alterada(int valor);

#endif
