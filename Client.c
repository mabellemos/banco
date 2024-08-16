#include <stdio.h>
#include <stdlib.h>
#include "Client.h"

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

Queue *create_queue()
{
    Queue *fi = (Queue*) malloc(sizeof(Queue));

    if (fi != NULL)
    {
        fi->end = NULL;
        fi->start = NULL;
        fi->amount = 0;
    }

    return fi;
}

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

int consult_queue(Queue *fi, struct Client *cl)
{
    if (fi == NULL)
        return 0;
    if (fi->start == NULL)
        return 0;

    *cl = fi->start->data;

    return 1;
}

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

int size_queue(Queue *fi)
{
    if (fi == NULL)
        return 0;
    return fi->amount;
}

int null_queue(Queue *fi)
{
    if (fi == NULL)
        return 1;
    if (fi->start == NULL)
        return 1;

    return 0;
}

int full_queue(Queue *fi)
{
    return 0;
}

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
        printf("Tempo de espera: %f\n", no->data.waiting_time);
        printf("-------------------------------\n");

        no = no->next;
    }
}