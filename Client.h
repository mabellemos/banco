struct Client
{
    char name[100];
    char operation[100];
    int waiting_time;
};

typedef struct Queue Queue;
typedef struct Element Eleme;

Queue *create_queue();
void create_client();
void release_queue(Queue *fi);
int consult_queue(Queue *fi, struct Client *cl);
Eleme *linear_name_search(struct Queue *q, char* name);
int insert_queue(Queue *fi, struct Client *cl);
int remove_queue(Queue *fi);
int size_queue(Queue *fi);
int null_queue(Queue *fi);
int full_queue(Queue *fi);
void display_queue(Queue *fi);
void bank_withdrawal(float value);
float bank_deposit();
float bank_payment();
float bank_transfer();