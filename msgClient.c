#include "mySem.h"
#include "msgCom.h"
#include "memory.h"
#include <stdio.h>

int main(){
    struct msgtype content;
    content.mtype=1;
    int qid;
    int sid;
    qid = msgget(MSGKEY, IPC_CREAT|0666);
    printf("start to send at %d\n", qid);
    while(1){
        for (int i=0; ; i++){
            char c;
            if ((c=getchar())=='\n') break;
            content.text[i]=c;
        }
        msgsnd(qid, &content, sizeof(content.text), MSG_NOERROR);
        memset(content.text, 0, 100);
    }

    //debug
    // char text[100];
    // while(scanf("%s", text)){
    //     printf("%s", text);
    //     memset(text, 0, 100);
    // }
    
    return 0;
}