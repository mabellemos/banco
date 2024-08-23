#include <stdio.h>
#include <stdlib.h>
#include "Account.h"

struct elem
{
    struct Account info;
    struct elem *next;
};

typedef struct elem Elem;

List *create_list_account()
{
    List *li = (List *)malloc(sizeof(List));

    if (li != NULL)
        *li = NULL;

    return li;
}

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

int remove_list(List *li, int number)
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

int list_full(List *li)
{
    return 0;
}

int list_null(List *li)
{
    if (li == NULL)
        return 1;

    if (*li == NULL)
        return 1;

    return 0;
}

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