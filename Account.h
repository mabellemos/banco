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