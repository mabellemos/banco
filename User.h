#define MAX 100

struct user
{
    int id;
    char userName[MAX];
    char pass[MAX];
};

typedef struct User User;

void createUser();
void login();
int validUserName(char userName[]);
int releaseUser(int id);
int validPass(char pass[]);
void updateUser(int id);
int deleteUser(int id);