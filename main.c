#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Client.h"
#include "ClientPriority.h"

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
        printf("\nQual opção deseja realizar?\n\n1 - Formar fila\n2 - Formar fila prioritária\n");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            struct Client cl, c[4] = {{"Maria", "Saque", 50},
                                      {"Ricardo", "Depósito", 70},
                                      {"Bianca", "Saque", 50},
                                      {"Ana", "Pagamento", 100}};

            Queue *fi = create_queue();

            printf("\nTamanho da fila inicialmente: %d\n\n", size_queue(fi));

            for (int i = 0; i < 4; i++)
            {

                insert_queue(fi, &c[i]);

                if (null_queue(fi))
                    printf("Erro!!!!!!\n");

                consult_queue(fi, &cl);

                printf("Consulta: %s\n", c[i].name);
            }

            printf("\nTamanho da fila após inserção: %d\n\n", size_queue(fi));
            display_queue(fi);

            for (int i = 0; i < 4; i++)
            {
                remove_queue(fi);
                release_queue(fi);

                consult_queue(fi, &cl);

                printf("Consulta: %s\t %s\n", cl.name, cl.operation);
            }

            printf("\nTamanho da fila após remoção: %d\n\n", size_queue(fi));
            display_queue(fi);

            for (int i = 0; i < 4; i++)
                insert_queue(fi, &c[i]);

            printf("\nTamanho da fila após inserção 2: %d\n\n\n\n", size_queue(fi));
            display_queue(fi);

            release_queue(fi);

            break;
        case 2:
            struct ClientPrio itens[6] = {{"Ray", 1},
                                          {"Antoniel", 2},
                                          {"Izabel", 5},
                                          {"Maria", 10},
                                          {"Cledja", 9},
                                          {"Juju", 2}};

            QueuePrio *fp;
            fp = create_queuePrio();
            
            printf("=================================\n");
            printf("\n             Fila\n\n");
            for (int i = 0; i < 6; i++)
            {
                printf("%d), Prio: %d, %s\n", i, itens[i].prio, itens[i].name);
                insert_queuePrio(fp, itens[i].name, itens[i].prio);
            }

            printf("=================================\n");

            printf("\nFila prioritária:\n\n");
            display_queuePrio(fp);

            printf("=================================\n");

            printf("\nFila após remoção:\n\n");
            for (int i = 0; i < 6; i++)
            {
                remove_queuePrio(fp);
                display_queuePrio(fp);

                printf("=================================\n");
            }

            release_queuePrio(fp);

            break;
        default:
            printf("\nOpção inválida!");
            break;
        }

        printf("\nDeseja realizar outra operação? (1 - Sim/2 - Não)\n");
        scanf("%d", &resp);
    } while (resp == 1);

    system("pause");

    return 0;
}