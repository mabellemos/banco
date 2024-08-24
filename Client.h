struct Client
{
    char name[100];
    char operation[100];
    int amount;
    double waiting_time;
};

typedef struct Queue Queue;

Queue *create_queue();
void release_queue(Queue *fi);
int consult_queue(Queue *fi, struct Client *cl);
int insert_queue(Queue *fi, struct Client *cl);
int remove_queue(Queue *fi);
int size_queue(Queue *fi);
int null_queue(Queue *fi);
int full_queue(Queue *fi);
void display_queue(Queue *fi);