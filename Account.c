#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Client.h"
#include "ClientPriority.h"
#include "User.h"
#include "Account.h"

struct ClientPrio
{
    char name[30];
    int prio;
};

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
        printf("\n-------------------------------\n");
        printf("Número da Conta: %d\n", no->info.number);
        printf("Tipo de conta: %s\n", no->info.type);
        printf("Saldo: %2.f\n", no->info.balance);
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

void menu(int *time, int *operation)
{
    int opc, resp, total_time = 0;

    do
    {
        printf("\nEscolha uma das opções abaixo para iniciar o atendimento:\n\n1 - Saque\n2 - Depósito\n3 - Pagamento\n4 - Transferência\n5 - Sair\n");
        scanf("%d", &opc);

        *operation = opc;

        switch (opc)
        {
        case 1:
            total_time += 50;
            break;
        case 2:
            total_time += 70;
            break;
        case 3:
            total_time += 100;
            break;
        case 4:
            total_time += 60;
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

    *time = total_time;
}

int service()
{
    int opc;
    int resp;

    do
    {
        printf("\n---------ATENDIMENTO BANCÁRIO----------\n\n");
        printf("\nQual opção deseja realizar?\n\n1 - Entrar na Fila\n2 - Entrar na Fila prioritária\n3 - Conta Bancária\n4 - Gerar relatórios\n\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            int resp1;

            printf("\n--------- FILA ---------\n");
            Queue *fi = create_queue();
            printf("\nTamanho da fila inicialmente: %d\n", size_queue(fi));

            struct Client cl, c[4] = {{"Maria", "Saque", 50},
                                      {"Ricardo", "Depósito", 70},
                                      {"Bianca", "Saque", 50},
                                      {"Ana", "Pagamento", 100}};

            int num_clients;

            printf("\nQuantos clientes entrarão na fila? (informe números inteiros)\n");
            scanf("%d", &num_clients);

            FILE *file_fila = fopen("db/fila.txt", "w");

            if (file_fila == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            for (int i = 0; i < num_clients; i++)
            {
                printf("\nDigite o nome do cliente: ");
                scanf("%s", cl.name);

                int oper;
                menu(&cl.waiting_time, &oper);

                if (oper == 1)
                {
                    strcpy(cl.operation, "Saque");
                }
                else if (oper == 2)
                {
                    strcpy(cl.operation, "Depósito");
                }
                else if (oper == 3)
                {
                    strcpy(cl.operation, "Pagamento");
                }
                else if (oper == 4)
                {
                    strcpy(cl.operation, "Transferência");
                }
                else
                {
                    strcpy(cl.operation, "Falha!");
                }

                insert_queue(fi, &cl);

                if (null_queue(fi))
                    printf("Erro!!!!!!\n");

                consult_queue(fi, &cl);

                fprintf(file_fila, "%s, %s, %d\n", cl.name, cl.operation, cl.waiting_time);
            }

            for (int i = 0; i < 4; i++)
            {
                insert_queue(fi, &c[i]);
                fprintf(file_fila, "%s, %s, %d\n", c[i].name, c[i].operation, c[i].waiting_time);
            }

            printf("\nTamanho da fila após inserção: %d\n", size_queue(fi));
            display_queue(fi);

            do
            {
                int opc;

                printf("\n---- Fila bancária ----\n");
                printf("\n1 - Visualizar fila\n2 - Localizar cliente na fila\n3 - Fazer fila andar\n");
                scanf("%d", &opc);

                switch (opc)
                {
                case 1:
                    display_queue(fi);
                    break;

                case 2:

                    char nameLoc[100];

                    printf("\nInforme o nome do cliente que deseja localizar: ");
                    scanf("%s", nameLoc);

                    Eleme *el = linear_name_search(fi, nameLoc);

                    if (el == NULL)
                    {
                        printf("\nO cliente %s não está na fila!\n", nameLoc);
                    }
                    else
                    {
                        printf("\nO cliente %s está na fila!\n", nameLoc);
                    }

                    break;

                case 3:
                    remove_queue(fi);
                    printf("\n---- Fila após remoção ----\n");
                    display_queue(fi);
                    break;

                default:
                    printf("\nOpção inválida!\n");
                    break;
                }

                printf("\nDeseja realizar outra operação? (1 - Sim | 2 - Não)");
                scanf("%d", &resp1);
            } while (resp1 == 1);

            release_queue(fi);
            fclose(file_fila);

            break;

        case 2:
            printf("\n------- Fila prioritária ------\n\n");
            FILE *file_fila_prioritaria = fopen("db/fila_prioritaria.txt", "w");

            if (file_fila_prioritaria == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            struct ClientPrio itens[6] = {{"Ray", 1},
                                          {"Antoniel", 2},
                                          {"Izabel", 5},
                                          {"Maria", 10},
                                          {"Cledja", 9},
                                          {"Juju", 2}};

            struct ClientPrio cl_prio;
            QueuePrio *fp = create_queuePrio();

            int num_clients_prio;
            printf("\nQuantos clientes entrarão na fila? (informe números inteiros)\n");
            scanf("%d", &num_clients_prio);

            for (int i = 0; i < num_clients_prio; i++)
            {
                printf("\nDigite o nome do cliente: ");
                scanf("%s", cl_prio.name);

                printf("\nDigite a prioridade do cliente (número inteiro): ");
                scanf("%d", &cl_prio.prio);

                insert_queuePrio(fp, cl_prio.name, cl_prio.prio);

                fprintf(file_fila_prioritaria, "%s, %d\n", cl_prio.name, cl_prio.prio);
            }

            for (int i = 0; i < 6; i++)
            {
                insert_queuePrio(fp, itens[i].name, itens[i].prio);
            }

            display_queuePrio(fp);

             do
            {
                int opc;

                printf("\n---- Fila bancária Prioritária ----\n");
                printf("\n1 - Visualizar fila\n2 - Fazer fila andar\n");
                scanf("%d", &opc);

                switch (opc)
                {
                case 1:
                    display_queuePrio(fp);
                    break;

                case 2:
                    remove_queuePrio(fp);
                    printf("\n---- Fila após remoção ----\n");
                    display_queuePrio(fp);
                    break;

                default:
                    printf("\nOpção inválida!\n");
                    break;
                }

                printf("\nDeseja realizar outra operação? (1 - Sim | 2 - Não)");
                scanf("%d", &resp1);
            } while (resp1 == 1);


            release_queuePrio(fp);
            fclose(file_fila_prioritaria);
            break;

        case 3:
            struct Account ac;
            List *li = create_list_account();

            printf("\nTamanho da lista de contas inicialmente: %d\n", size_list(li));

            FILE *file_contas = fopen("db/contas.txt", "w");

            if (file_contas == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            int num_accounts;
            printf("\nQuantas contas bancárias deseja criar?\n");
            scanf("%d", &num_accounts);

            for (int i = 0; i < num_accounts; i++)
            {
                printf("\n-------- Criação de Conta --------\n");

                printf("\nInforme o número da conta: ");
                scanf("%d", &ac.number);

                printf("\nInforme o tipo da conta: ");
                scanf("%s", ac.type);

                printf("\nInforme o saldo em conta: ");
                scanf("%f", &ac.balance);

                insert_list_ordered(li, ac);
                fprintf(file_contas, "%d, %s, %2.f\n", ac.number, ac.type, ac.balance);
            }

            display_list(li);
            printf("\nTamanho da lista de contas: %d\n", size_list(li));

            do
            {
                printf("\n---- Lista de Contas ----\n");
                printf("\n1 - Inserir Conta\n2 - Remover conta\n3 - Listar Contas\n");
                scanf("%d", &opc);

                switch (opc)
                {
                case 1:
                    printf("\n-------- Criação de Conta --------\n");

                    printf("\nInforme o número da conta: ");
                    scanf("%d", &ac.number);

                    printf("\nInforme o tipo da conta: ");
                    scanf("%s", ac.type);

                    printf("\nInforme o saldo em conta: ");
                    scanf("%f", &ac.balance);

                    insert_list_ordered(li, ac);
                    fprintf(file_contas, "%d, %s, %2.f\n", ac.number, ac.type, ac.balance);
                    printf("\nConta criada com sucesso!\n");

                    display_list(li);
                    break;
                case 2:
                    remove_list_end(li);

                    printf("\nTamanho da lista após a remoção: %d\n", size_list(li));
                    display_list(li);
                    break;

                case 3:
                    display_list(li);
                    break;

                default:
                    printf("\nOpção inválida!");
                    break;
                }

                printf("\nDeseja realizar outra operação? (1 - Sim | 2 - Não)");
                scanf("%d", &resp);
            } while (resp == 1);

            display_list(li);
            printf("\nTamanho da conta após a remoção: %d\n", size_list(li));

            release_list_account(li);
            fclose(file_contas);

            break;
        case 4:
            printf("\n------- Relatório final -------\n");
            printf("\nQuantidade de clientes atendidos: %d", (size_queue(fi) + size_queuePrio(fp)));

            printf("\n------ Clientes e tempo gasto ------ ");
            display_queue(fi);

            printf("\nClientes atendidos por prioridade:\n");
            display_queuePrio(fp);
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }

        printf("\nDeseja realizar outra operação? (1 - Sim | 2 - Não)\n");
        scanf("%d", &resp);
    } while (resp == 1);
}