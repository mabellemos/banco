# Sistema de Banco

## Objetivo

Repositório criado com o objetivo de realizar a implementação de um sistema na linguagem de programação C, que simula um atendimento bancário, para a fixação dos conteúdos abordados na disciplina de Estrutura de Dados do curso de **bacharelado em Sistemas de Informação** do **IFAL - Instituto Federal de Educação, Ciência e Tecnologia de Alagoas**.

### Alunos:

Maria Izabel Lemos da Silva

Ray Antoniel da Silva Santos

## Descrição

Situação 3: Simulação de atendimento bancário. Além de fazer o gerenciamento da fila, o sistema deve exibir o tempo que o cliente permaneceu na fila. Quando o cliente entra na fila o tempo é registrado para ser adicionado no tempo final que ele ficou. O cliente pode fazer uma ou várias das transações abaixo:

**Tabela 1: Orientação de transações bancárias**

|Código|Transação|Duração
|-|-|-
|1|Saque|50s
|2|Depósito|70s
|3|Pagamento|100s
|4|Transferência|60s

No final do expediente, há um relatório que a gerência analisa sobre o atendimento, como quantidade de clientes, tempo total, tempo de cada cliente, atendimento por prioridade, etc.
## Estruturas de Dados utilizadas

### Filas dinâmicas
As filas dinâmicas tratam de formas de organização de filas em que não se tem uma determinação estáticas, elas são adaptadas de maneira mais fluida e sem, necessariamente, uma delimitação prévia. No nosso código nós utilizamos as filas dinâmicas para implementar a organização dos clientes na fila de atendimento, por exemplo:

```
Queue *create_queue()
{
    Queue *fi = (Queue *)malloc(sizeof(Queue));

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
```

Este é um trecho do nosso código onde utilizamos os conceitos de filas dinâmicas para criar a fila de atendimento e para fazer a liberação dela.

### Filas prioritárias
As filas prioritárias se assemelham ao conceito de filas dinâmicas. No entanto, a diferença é a formação da segunda é direcionada a uma fator de prioridade, ou seja, o fator de momento de chegada na fila não é o principal, mas a prioridade daquele cliene ao ser inserido na fila.
```
QueuePrio *create_queuePrio()
{
    QueuePrio *fp;

    fp = (QueuePrio *)malloc(sizeof(struct QueuePrio));

    if (fp != NULL)
        fp->amount = 0;

    return fp;
}

void release_queuePrio(QueuePrio *fp)
{
    free(fp);
}

int consult_queuePrio_name(QueuePrio *fp, char *nome)
{
    if (fp == NULL || fp->amount == 0)
        return 0;

    strcpy(nome, fp->data[fp->amount - 1].name);

    return 1;
}

```
Nesse caso, utilizamos funcionalidades muito parecidas com o caso anterior, mas destacando a prioridade dessa vez.

### Recursividade
A recursividade é um dos recursos importantes quando se trata de repetição em determinados termos. Nesse caso, utilizamos para o cálculo:

```
float calculate_compound_interest(float principal, float rate, int periodos)
{
    if (periodos == 0)
    {
        return principal;
    }

    return calculate_compound_interest(principal * (1 + rate), rate, periodos - 1);
}
```
Usamos recusividade para realizar o cálculo dos juros compostos.

### Busca binária
Em busca binária o algoritmo funciona dividindo repetidamente o intervalo de pesquisa ao meio, até localizar o elemento desejado ou determinar que ele não está presente na lista.
```
 int consult_queue_client(int *V, int N, int elem)
{
    int i, start = 0, quite, end = N - 1;

    while (start <= end)
    {
        quite = (start + end) / 2;

        if (elem < V[quite])
            end = quite - 1;
        else if (elem > V[quite])
            start = quite + 1; 
        else
            return quite;
    }

    return -1;
}
```
Nesse contexto, utilizamos busca binária para localizar se determinado cliente já está na fila.

### TAD (Tipos Abstratos de Dados)
A utilização dos TAD's para obter uma interface externa foi fundamental para a organização da nossa implementação, além de tornar o entendimento mais prático. Usamos os arquivos ".h".
```
struct Account
{
    int number;
    char name[30];
    float balance;
};

typedef struct elem *List;

List *create_list_account();
void release_list_account(List *li);
int insert_list_end(List *li, struct Account ac);
int insert_list_start(List *li, struct Account ac);
int insert_list_ordered(List *li, struct Account ac);
int remove_list_number(List *li, int number);
int remove_list_start(List *li);
int remove_list_end(List *li);
int size_list(List *li);
int list_null(List *li);
int list_full(List *li);
void display_list(List *li);
int consult_list_number(List *li, int number, struct Account *ac);
int consult_list_pos(List *li, int pos, struct Account *ac);
void menu();
```
Este é o código presente no nosso arquico Account.h, usado para a criação da interface de criação de conta.
### Lista SImplesmente Encadeadas
As listas simplesmente encadeadas são fundamentais para casos que não se ter uma definição prévia de itens a ser adicionados, principalmente pelo fato de não ter uma ordenação implicita de entrada e saída.
```
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
```
No código acima nós utilizamos as listas simplesmente encadeadas para fazer a criação de contas.

## Considerações finais
Por fim, gostariamos de agrecer à nossa professora [Cledja Karina Rolim da Silva](https://buscatextual.cnpq.br/buscatextual/visualizacv.do;jsessionid=1ECD0AF3A0904BCEA98A829BAA982CE4.buscatextual_0) pela oportunidade de desenvolvermos melhor as nossas habilidades na disciplina de Estrutura de Dados.
