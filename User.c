#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"

/*int validUserName(char name[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(name[i], name[i]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}*/

/*int validPass(char pass[])
{

    if (lenght(pass) >= 8)
    {
        if ()
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}*/
typedef struct User
{
    int id;
    char name[MAX];
    char pass[MAX];
} User;

void createUser()
{
    int resp, i, pass;
    char name[100];
    FILE *file;
    User user[MAX];

    do
    {
        file = fopen("users.txt", "a");
        if (file == NULL)
        {
            printf("\nERRO NA ABERTURA DO ARQUIVO!\n");
        }

        printf("\n======== Cadastro de Usuário ========\n\n");
        user[i].id++;

        printf("\nInforme o nome de usuário: ");
        scanf("%s", name);
        fprintf(file, "%s,", name);

        printf("\nInforme uma senha: ");
        scanf("%d", &pass);
        /*fflush(stdin);
        int senha;

        for (i = 0; i <= 7; i++)
        {

            scanf("%d", &pass[i]);

            putchar('*');
        }*/

        fprintf(file, "%d\n", pass);
        /*fgets(pass, 10, stdin);
        getchar();
        fprintf(file, "%s\n", pass);*/

        /*if (validUserName == 1)
        {
            printf("\nSenha inválida! Informe uma nova senha");
            scanf(" %c", &user[i].pass);

            validPass(user[i].pass);
        }*/

        fclose(file);

        printf("\nDeseja cadastrar outro usuário? (1 - Sim | 2 - Não)\n");
        scanf("%d", &resp);

        i++;
    } while (resp == 1);

    printf("\nUsuário salvo com sucesso!\n");
}

void login()
{
    // Verificar se os dados existem no arquivo
    char userName[100];
    int resp, opc, senha;

    printf("\n================= BANCO ===================\n\n");
    printf("Login: ");
    scanf("%s", userName);
    printf("Senha: ");
    scanf("%d", &senha);

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
        default:
            printf("\nOpção inválida!\n");
            break;
        }

        printf("\nDeseja realizar outra operação? (1 - Sim | 2 - Não)");
        scanf("%d", &resp);
    } while (resp == 1);
}
