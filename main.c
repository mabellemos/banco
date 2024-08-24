#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"

int main()
{
    int opc; 

    printf("\n================= BANCO ===================\n\n");
    printf("1 - Logar\n2 - Cadastrar\n");
    scanf("%d", &opc);

    if (opc == 1)
    {
        loginUser();
    } else if (opc == 2){
        createUser();
    } else {
        printf("\nOPção inválida!");
    }

    system("pause");

    return 0;
}
