#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClientPriority.h"

struct Client
{
    char name[30];
    int prio;
};

struct QueuePrio
{
    int amount;
    struct Client data[MAX];
};

//Cria uma fila prioritária para os clientes
QueuePrio *create_queuePrio()
{
    QueuePrio *fp;

    fp = (QueuePrio *)malloc(sizeof(struct QueuePrio));

    if (fp != NULL)
        fp->amount = 0;

    return fp;
}

//Libera a fila prioritária
void release_queuePrio(QueuePrio *fp)
{
    free(fp);
}

//Consulta um cliente pelo nome dentro da fila prioritária
int consult_queuePrio_name(QueuePrio *fp, char *nome)
{
    if (fp == NULL || fp->amount == 0)
        return 0;

    strcpy(nome, fp->data[fp->amount - 1].name);

    return 1;
}

int insert_queuePrio(QueuePrio *fp, char *name, int priority)
{
    if (fp == NULL)
        return 0;

    if (fp->amount == MAX)
        return 0;

    int i = fp->amount - 1;

    while (i >= 0 && fp->data[i].prio >= priority)
    {
        fp->data[i + 1] = fp->data[i];

        i--;
    }

    strcpy(fp->data[i + 1].name, name);

    fp->data[i + 1].prio = priority;

    fp->amount++;

    return 1;
}

int remove_queuePrio(QueuePrio *fp)
{
    if (fp == NULL)
        return 0;

    if (fp->amount == 0)
        return 0;

    fp->amount--;

    return 1;
}

int size_queuePrio(QueuePrio *fp)
{
    if (fp == NULL)
        return -1;
    else
        return fp->amount;
}

int full_queuePrio(QueuePrio *fp)
{
    if (fp == NULL)
        return -1;

    return (fp->amount == MAX);
}

int null_queuePrio(QueuePrio *fp)
{
    if (fp == NULL)
        return -1;

    return (fp->amount == 0);
}

void display_queuePrio(QueuePrio *fp)
{
    if (fp == NULL)
        return;

    for (int i = fp->amount - 1; i >= 0; i--)
    {
        printf("\nPrioridade: %d\n", fp->data[i].prio);
        printf("Nome: %s\n", fp->data[i].name);
    }
}