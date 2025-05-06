#ifndef CONTATO_H
#define CONTATO_H

#define MAX_NOME 128
#define MAX_TELEFONE 15
#define ARQUIVO "agenda.csv"

/**
 * Estrutura que representa a agenda de contatos
 * Ela contem um ponteiro para o primeiro nó da lista de contatos
 */
typedef struct _agenda Agenda;

/**
 * Estrutura que representa um nó de contato na lista encadeada
 * Cada nó contem um contato e um ponteiro para o próximo nó da lista
 */
typedef struct _no No;

/**
 * Função que cria uma nova agenda, alocando memória para ela e inicializando a lista de contatos
 */
Agenda* criar_agenda();

/**
 * Função que carrega os contatos de um arquivo CSV para a agenda
 * Ela lê o arquivo "agenda.csv" e adiciona os contatos à lista encadeada
 */
void carregar_contatos(Agenda* agenda);

/**
 * Função que salva os contatos da agenda no arquivo CSV "agenda.csv"
 * Ela percorre a lista de contatos e escreve os dados no arquivo
 */
void salvar_contatos(Agenda* agenda);

/**
 * Função que adiciona um novo contato à agenda
 * O contato é inserido no início da lista encadeada
 */
void adicionar_contato(Agenda* agenda, const char* nome, const char* telefone);

/**
 * Função que imprime todos os contatos da agenda
 * Ela percorre a lista e exibe cada contato no console
 */
void imprimir_agenda(Agenda* agenda);

/**
 * Função que remove um contato da agenda pelo nome
 * Ela percorre a lista de contatos e remove o nó correspondente ao nome fornecido
 */
void deletar_contato(Agenda* agenda, const char* nome);

/**
 * Função que libera a memória alocada para a agenda e seus nós
 * Ela percorre a lista e libera a memória de cada nó, finalizando a agenda
 */
void liberar_agenda(Agenda* agenda);

/**
 * Função que retorna um valor indicando se a agenda foi alterada (se houve inserções ou remoções)
 */
int agenda_foi_alterada();

/**
 * Função que define o estado de alteração da agenda
 * Se o valor fornecido for 1, significa que a agenda foi alterada, se for 0, não foi
 */
void set_agenda_alterada(int valor);

#endif
