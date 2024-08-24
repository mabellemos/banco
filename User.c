#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "User.h"
#include "Account.h"

FILE *file;

void createUser()
{
    int resp, i = 0, pass;
    char name[100];
    User user[MAX];

    do
    {
        printf("\n======== Cadastro de Usuário ========\n\n");

        printf("\nInforme o nome de usuário: ");
        scanf("%s", user[i].userName);

        printf("\nInforme uma senha: ");
        scanf("%s", user[i].pass);

        file = fopen("db/users.txt", "a");

        if (file == NULL)
        {
            printf("\nERRO NA ABERTURA DO ARQUIVO!\n");
        }

        fprintf(file, "%s,%s\n", user[i].userName, user[i].pass);

        fclose(file);

        printf("\nDeseja cadastrar outro usuário? (1 - Sim | 2 - Não)\n");
        scanf("%d", &resp);

        i++;
    } while (resp == 1);

    printf("\nUsuário salvo com sucesso!\n");
}

int loginUser()
{

    char userName[MAX];
    char pass[MAX];
    char buffer[MAX * 2];

    printf("\n================= login ===================\n\n");
    printf("Login: ");
    scanf("%s", userName);
    printf("Senha: ");
    scanf("%s", pass);

    file = fopen("db/users.txt", "r");

    if (file == NULL)
    {
        printf("\nERRO NA ABERTURA DO ARQUIVO!\n");
        return 0;
    }

    char *stored_userName[MAX];
    char *stored_pass[MAX];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = 0;

        *stored_userName = strtok(buffer, ",");
        *stored_pass = strtok(NULL, ",");

        if (stored_userName != NULL && stored_pass != NULL)
        {
            if (strcmp(userName, *stored_userName) == 0 && strcmp(pass, *stored_pass) == 0)
            {
                fclose(file);

                printf("\nLogin realizado com sucesso!\n");

                service();
                return 1;
            }
        }
    }

    fclose(file);

    printf("\nLogin falhou! Usuário ou senha incorretos.\n");
    return 0;
}