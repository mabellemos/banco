#include <stdio.h>
#include <stdlib.h>
#include "client.h"

int main(){

    struct Client cl, c[4] = {{"Maria", "Saque", 50},
                         {"Ricardo", "Depósito", 70},
                         {"Bianca", "Saque", 50},
                         {"Ana", "Pagamento", 100}};

    Queue* fi = create_queue();

    printf("\nTamanho da fila inicialmente: %d\n\n", size_queue(fi));

    for(int i=0; i < 4; i++){

        insert_queue(fi, &c[i]);

        if(null_queue(fi))
            printf("Erro!!!!!!\n");

        consult_queue(fi,&cl);

        printf("Consulta: %s\n", c[i].name);
    }

    printf("\nTamanho da fila após inserção: %d\n\n", size_queue(fi));
    display_queue(fi);

    for(int i=0; i < 4; i++){
        remove_queue(fi);
        release_queue(fi);

        consult_queue(fi, &cl);

        printf("Consulta: %s\t %s\n", cl.name, cl.operation);
    }

    printf("\nTamanho da fila após remoção: %d\n\n", size_queue(fi));
    display_queue(fi);

    for(int i=0; i < 4; i++)
        insert_queue(fi, &c[i]);

    printf("\nTamanho da fila após inserção 2: %d\n\n\n\n", size_queue(fi));
    display_queue(fi);

    release_queue(fi);

    system("pause");

    return 0;
}