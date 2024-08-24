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

int main()
{
    int opc;
    int resp;

    do
    {
        printf("\n---------ATENDIMENTO BANCÁRIO----------\n\n");
        printf("\nQual opção deseja realizar?\n\n1 - Formar fila\n2 - Formar fila prioritária\n3 - Criar usuário\n4 - Criar COnta Bancária\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
        {
            FILE *file = fopen("fila.txt", "w");
            if (file == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            int num_clients;
            printf("\nQuantos clientes deseja inserir na fila?\n");
            scanf("%d", &num_clients);

            struct Client cl;
            Queue *fi = create_queue();

            printf("\nTamanho da fila inicialmente: %d\n\n", size_queue(fi));

            for (int i = 0; i < num_clients; i++)
            {
                printf("\nDigite o nome do cliente %d: ", i + 1);
                scanf("%s", cl.name);
                printf("Digite a operação do cliente %d (ex: Saque, Depósito): ", i + 1);
                scanf("%s", cl.operation);
                printf("Digite o valor da operação do cliente %d: ", i + 1);
                scanf("%d", &cl.amount);

                insert_queue(fi, &cl);

                if (null_queue(fi))
                    printf("Erro!!!!!!\n");

                consult_queue(fi, &cl);
                printf("Consulta: %s\n", cl.name);

                fprintf(file, "Nome: %s, Operação: %s, Valor: %d\n", cl.name, cl.operation, cl.amount);
            }

            printf("\nTamanho da fila após inserção: %d\n\n", size_queue(fi));
            display_queue(fi);

            release_queue(fi);
            fclose(file);
            break;
        }
        case 2: 
        {
            FILE *file = fopen("fila_prioritaria.txt", "w");
            if (file == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            int num_clients;
            printf("\nQuantos clientes prioritários deseja inserir na fila?\n");
            scanf("%d", &num_clients);

            struct ClientPrio cl_prio;
            QueuePrio *fp = create_queuePrio();

            printf("=================================\n");

            for (int i = 0; i < num_clients; i++)
            {
                printf("Digite o nome do cliente %d: ", i + 1);
                scanf("%s", cl_prio.name);
                printf("Digite a prioridade do cliente %d (número inteiro): ", i + 1);
                scanf("%d", &cl_prio.prio);

                insert_queuePrio(fp, cl_prio.name, cl_prio.prio);

                fprintf(file, "Nome: %s, Prioridade: %d\n", cl_prio.name, cl_prio.prio);
            }

            printf("\nFila prioritária:\n\n");
            display_queuePrio(fp);

            release_queuePrio(fp);
            fclose(file);
            break;
        case 3:
            createUser();
            break;
        }
        case 4:
        {
            FILE *file = fopen("contas.txt", "w");
            if (file == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            int num_accounts;
            printf("\nQuantas contas bancárias deseja criar?\n");
            scanf("%d", &num_accounts);

            struct Account ac;
            List *li = create_list_account();

            printf("\nTamanho da lista de contas inicialmente: %d\n", size_list(li));

            int i;
            for (i = 0; i < 4; i++)
                insert_list_ordered(li, ac[i]);

            display_list(li);
            printf("\nTamanho da lista de contas: %d\n", size_list(li));

            for (i = 0; i < 4; i++)
            {
                remove_list_end(li);
                display_list(li);
                printf("\nTamanho da conta após a remoção: %d\n\n\n", size_list(li));
            }

            printf("\nTamanho da lista de contas após a inserção: %d\n", size_list(li));
            display_list(li);

            release_list_account(li);
            fclose(file);
            break;
        }
        default:
            printf("\nOpção inválida!\n");
            break;
        }

        printf("\nDeseja realizar outra operação? (1 - Sim | 2 - Não)\n");
        scanf("%d", &resp);
    } while (resp == 1);

    system("pause");

    return 0;
}
