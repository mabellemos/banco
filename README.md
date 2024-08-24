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
A utilização de filas dinâmicas é essencial para casos que não se tem previsibilidade da quantidade de itens a serem inseridos, por isso a fila estática acaba sendo sustituída pela dinâmica.
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

```
Nesse caso, utilizamos para criaar a fila de atendimento de clientes.
### Filas prioritárias
As filas prioritárias têm muita semelhança com as dinâmicas, porém se diferenciam pelo fato das prioritárias utilizarem o grau de necessidade/prioridade e não a ordem de chegada.
```
QueuePrio *create_queuePrio()
{
    QueuePrio *fp;

    fp = (QueuePrio *)malloc(sizeof(struct QueuePrio));

    if (fp != NULL)
        fp->amount = 0;

    return fp;
}
```
No exemplo nós utilizamos filas prioritárias para criar uma fila de atendimento especial.

### Recursividade
A recursividade é importante para casos de repetição. Incluse cálculos frequentes.
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
Nessa parte do código nós a utilizamos para realizar o cálculo de juros compostos.

### Busca binária
A busca binária é muito frequente em ferramentas de consulta. 
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
Por isso, utilizamos a busca para localizar se determinado cliente está inserido na fila de atendimento.

### TAD (Tipos Abstratos de Dados)
Os TADS são fatores organizacionais necessários quando se trata de legibilidade e segmentação. Principalmente na criação de interfaces utilizadas.
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
No código acima está a interface criada para a implementação da conta através do arquivo .h.

### Lista Simplesmente Encadeadas
A lista é "simplesmente encadeada" porque cada nó tem um ponteiro apenas para o próximo nó, não para o nó anterior.
```
List *create_list_account()
{
    List *li = (List *)malloc(sizeof(List));

    if (li != NULL)
        *li = NULL;

    return li;
}

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
Utilizamos a prática de listas simplesmente encadeadas para a lista de criação de contas

## Mini tutorial
Bastas [clicar aqui](https://drive.google.com/file/d/1oZharloQGGI_K-7f6nZA2D6hJtHXNOQG/view?usp=sharing) para ter acesso ao vídeo do nosso mini tutorial do projeto. Lembrando que o acesso é restrito para o email institucional do IFAL.

## Considerações finais
Por fim, gostaríamos de agrecer à professora [Cledja Karina Rolim da Silva](https://buscatextual.cnpq.br/buscatextual/visualizacv.do;jsessionid=1ECD0AF3A0904BCEA98A829BAA982CE4.buscatextual_0) pela opotunidade de desenvolvimento de habilidades práticas na disciplina de Estrutura de Dados.
