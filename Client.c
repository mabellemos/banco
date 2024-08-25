#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Client.h"
#include "Account.h"

#define MAX 100

struct Element
{
    struct Client data;
    struct Element *next;
};

typedef struct Element Elem;

struct Queue
{
    struct Element *start;
    struct Element *end;
    int amount;
};

// Criar cliente
void create_client()
{
    int resp, opc, time, oper;
    char name[MAX], operation[MAX];

    printf("\n--------------- Clientes -----------------\n");
    printf("\nInforme o nome: ");
    scanf("%s", name);

    menu(&time, &oper);

    if (oper == 1)
    {
        strcpy(operation, "Saque");
    }
    else if (oper == 2)
    {
        strcpy(operation, "Depósito");
    }
    else if (oper == 3)
    {
        strcpy(operation, "Pagamento");
    }
    else if (oper == 4)
    {
        strcpy(operation, "Transferência");
    }
    else
    {
        strcpy(operation, "Falha!");
    }
}

// Criar fila dinâmica de clientes
Queue *create_queue()
{
    Queue *fi = (Queue *)malloc(sizeof(Queue));

    if (fi != NULL)
    {
        fi->end = NULL;
        fi->start = NULL;
        fi->amount = 0;
    }

    return fi;
}

// Libera fila
void release_queue(Queue *fi)
{
    if (fi != NULL)
    {
        Elem *no;

        while (fi->start != NULL)
        {
            no = fi->start;
            fi->start = fi->start->next;

            free(no);
        }

        free(fi);
    }
}

// Consulta os clientes da fila
int consult_queue(Queue *fi, struct Client *cl)
{
    if (fi == NULL)
        return 0;
    if (fi->start == NULL)
        return 0;

    *cl = fi->start->data;

    return 1;
}

// Busca linear
// Localizar um cliente específico na fila a partir do nome
Elem *linear_name_search(struct Queue *q, char *name)
{
    Elem *current = q->start;

    while (current != NULL)
    {
        if (strcmp(current->data.name, name) == 0)
        {
            return current; // Cliente encontrado
        }
        current = current->next;
    }

    return NULL; // Cliente não encontrado
}

// Insere clientes na fila
int insert_queue(Queue *fi, struct Client *cl)
{
    if (fi == NULL)
        return 0;

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->data = *cl;

    no->next = NULL;

    if (fi->end == NULL)
        fi->start = no;
    else
        fi->end->next = no;

    fi->end = no;

    fi->amount++;

    return 1;
}

// Remove clientes da fila
int remove_queue(Queue *fi)
{
    if (fi == NULL)
        return 0;
    if (fi->start == NULL)
        return 0;

    Elem *no = fi->start;

    fi->start = fi->start->next;

    if (fi->start == NULL)
        fi->end = NULL;

    free(no);

    fi->amount--;

    return 1;
}

// Verifica o tamanho da fila de clientes
int size_queue(Queue *fi)
{
    if (fi == NULL)
        return 0;
    return fi->amount;
}

// Verifica se a fila está vazia
int null_queue(Queue *fi)
{
    if (fi == NULL)
        return 1;
    if (fi->start == NULL)
        return 1;

    return 0;
}

// Verifica se a fila está cheia
int full_queue(Queue *fi)
{
    return 0;
}

// Imprime os clientes que estão na fila
void display_queue(Queue *fi)
{
    if (fi == NULL)
        return;

    Elem *no = fi->start;

    while (no != NULL)
    {
        printf("\n----------Cliente-------------\n");
        printf("Nome: %s\n", no->data.name);
        printf("Operação realizada: %s\n", no->data.operation);
        printf("Tempo gasto nas operações: %d\n", no->data.waiting_time);
        printf("-------------------------------\n");

        no = no->next;
    }
}

/*void bank_withdrawal(float value)
{
    Account *ac;

    if (value <= 0)
    {
        printf("\nValor de saque inválido.\n");
    }
    else if (ac->balance < value)
    {
        printf("\nSaldo insuficiente.\n");
    }
    else
    {
        ac->balance -= value;

        printf("\nSaque realizado com sucesso.\nNovo saldo: %.2f\n", ac->balance);
    }

    free(ac);
}*/