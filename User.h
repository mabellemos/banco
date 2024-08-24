#define MAX 100

struct user
{
    char userName[MAX];
    char pass[MAX];
};

typedef struct user User;

void createUser();
int loginUser();