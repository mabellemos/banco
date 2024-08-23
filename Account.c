#include <stdio.h>
#include <stdlib.h>
#include "Account.h"

struct elem
{
    struct Account info;
    struct elem *next;
};

typedef struct elem Elem;

// Criação de uma lista encadeada de contas
List *create_list_account()
{
    List *li = (List *)malloc(sizeof(List));

    if (li != NULL)
        *li = NULL;

    return li;
}

// Liberar uma conta da lista
void release_list_account(List *li)
{
    if (li != NULL)
    {
        Elem *no;

        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->next;

            free(no);
        }

        free(li);
    }
}

// Consulta a lista de contas a partir de uma posição
int consult_list_pos(List *li, int pos, struct Account *ac)
{
    if (li == NULL || pos <= 0)
        return 0;

    Elem *no = *li;
    int i = 1;

    while (no != NULL && i < pos)
    {
        no = no->next;
        i++;
    }

    if (no == NULL)
        return 0;
    else
    {
        *ac = no->info;
        return 1;
    }
}

// Consultar uma conta a partir do número da conta
int consult_list_number(List *li, int number, struct Account *ac)
{
    if (li == NULL)
        return 0;

    Elem *no = *li;

    while (no != NULL && no->info.number != number)
    {
        no = no->next;
    }

    if (no == NULL)
        return 0;
    else
    {
        *ac = no->info;
        return 1;
    }
}

// Inserir conta no final da lista
int insert_list_end(List *li, struct Account ac)
{
    if (li == NULL)
        return 0;

    Elem *no;

    no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->info = ac;
    no->next = NULL;

    if ((*li) == NULL)
    {
        *li = no;
    }
    else
    {
        Elem *aux;
        aux = *li;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = no;
    }
    return 1;
}

// Inserir conta no começo da lista
int insert_list_start(List *li, struct Account ac)
{
    if (li == NULL)
        return 0;

    Elem *no;

    no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->info = ac;
    no->next = (*li);
    *li = no;

    return 1;
}

// Inserir conta de forma ordenada
int insert_list_ordered(List *li, struct Account ac)
{
    if (li == NULL)
        return 0;

    Elem *no = (Elem *)malloc(sizeof(Elem));

    if (no == NULL)
        return 0;

    no->info = ac;

    if ((*li) == NULL)
    {
        no->next = NULL;
        *li = no;
        return 1;
    }
    else
    {
        Elem *ant, *atual = *li;

        while (atual != NULL && atual->info.number < ac.number)
        {
            ant = atual;
            atual = atual->next;
        }

        if (atual == *li)
        {
            no->next = (*li);
            *li = no;
        }
        else
        {
            no->next = atual;
            ant->next = no;
        }

        return 1;
    }
}

// Remover conta da lista através do número da conta
int remove_list_number(List *li, int number)
{
    if (li == NULL)
        return 0;

    if ((*li) == NULL)
        return 0;

    Elem *ant, *no = *li;

    while (no != NULL && no->info.number != number)
    {
        ant = no;
        no = no->next;
    }

    if (no == NULL)
        return 0;

    if (no == *li)
        *li = no->next;
    else
        ant->next = no->next;

    free(no);
    return 1;
}

// Remover conta pelo começo da lista
int remove_list_start(List *li)
{
    if (li == NULL)
        return 0;

    if ((*li) == NULL)
        return 0;

    Elem *no = *li;

    *li = no->next;
    free(no);

    return 1;
}

// Remover conta pelo final da lista
int remove_list_end(List *li)
{
    if (li == NULL)
        return 0;

    if ((*li) == NULL)
        return 0;

    Elem *ant, *no = *li;

    while (no->next != NULL)
    {
        ant = no;
        no = no->next;
    }

    if (no == (*li))
        *li = no->next;
    else
        ant->next = no->next;

    free(no);

    return 1;
}

// Verificar tamanho da lista
int size_list(List *li)
{
    if (li == NULL)
        return 0;

    int count = 0;

    Elem *no = *li;

    while (no != NULL)
    {
        count++;
        no = no->next;
    }

    return count;
}

// Verificar se a lista está cheia
int list_full(List *li)
{
    return 0;
}

// Verificar se a lista está vazia
int list_null(List *li)
{
    if (li == NULL)
        return 1;

    if (*li == NULL)
        return 1;

    return 0;
}

// Imprimir lista de contas
void display_list(List *li)
{

    if (li == NULL)
        return;

    Elem *no = *li;

    while (no != NULL)
    {
        printf("Número da Conta: %d\n", no->info.number);
        printf("Nome: %s\n", no->info.name);
        printf("Saldo: %f\n", no->info.balance);
        printf("-------------------------------\n");

        no = no->next;
    }
}

// Recursividade
// Calcular juros composto aplicadas a conta
float calculate_compound_interest(float principal, float rate, int periodos)
{
    if (periodos == 0)
    {
        return principal;
    }

    return calculate_compound_interest(principal * (1 + rate), rate, periodos - 1);
}

void menu()
{
    int opc, resp;

    do
    {
        printf("\n=========================================\n");
        ;
        printf("        ATENDIMENTO BANCÁRIO");
        printf("\n=========================================\n");

        printf("\nEscolha uma das opções abaixo para iniciar o atendimento:\n\n1 - Saque\n2 - Depósito\n3 - Pagamento\n4 - Transferência\n5 - Sair\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("\nTchauu!!\n");
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }

        printf("\nDeseja realizar outra operação? (1 - Sim | 2 - Não)");
        scanf("%d", &resp);
    } while (resp == 1);
}