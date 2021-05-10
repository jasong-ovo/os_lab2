#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>
#define MSGKEY 9816
struct msgtype{
    long mtype;
    char text[100];
};