#define MAX 100

typedef struct QueuePrio QueuePrio;

QueuePrio *create_queuePrio();
void release_queuePrio(QueuePrio *fp);
int consult_queuePrio_name(QueuePrio *fp, char *name);
int insert_queuePrio(QueuePrio *fp, char *name, int priority);
int remove_queuePrio(QueuePrio *fp);
int size_queuePrio(QueuePrio *fp);
int full_queuePrio(QueuePrio *fp);
int null_queuePrio(QueuePrio *fp);
void display_queuePrio(QueuePrio *fp);