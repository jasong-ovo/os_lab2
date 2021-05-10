#include "mySem.h"
#include "stdio.h"


int createsem(key_t key){
    int sid;
    if ((sid=semget(key, 1, 0666|IPC_CREAT)) == -1)
        printf("semget failed\n");
    else {
        union semun arg;
        arg.val = 1;
        if ((semctl(sid, 0, SETVAL, arg))==-1 )
        printf("semctl setVAL failed");
        else return sid;
    }
    return sid;
}


static void semcall(int sid, int op){
    struct sembuf sb;
    sb.sem_flg = 0;
    sb.sem_num = 0;
    sb.sem_op = op;
    if (semop(sid, &sb, 1) == -1)
    printf("semop failed");
}


void P(int sid){
    // static void semcall();
    semcall(sid, -1);
}


void V(int sid){
    // static void semcall();
    semcall(sid, 1);
}


void test(){
    printf("test\n");
}