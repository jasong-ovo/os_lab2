//comm
#include "mySem.h"
#include "msgCom.h"
#include <memory.h>
#include <stdio.h>

int main(){
    struct msgtype buf;
    int qid;
    if((qid = msgget(MSGKEY, 0666|IPC_CREAT)) == -1)
        {printf("init failed\n");return -1;}
    printf("start to listen at %d!\n", qid);
    while(1) {
        msgrcv(qid, &buf, 512, 1, MSG_NOERROR);
        printf("recv:%s\n", buf.text);
        memset(buf.text, 0, 100);
    }
    return 0;
}