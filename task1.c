#include "mySem.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define SIGUSR_1 16

extern int createsem();
void sig_load_children();

int main(){
    pid_t pid;
    int s = 0;
    int sid1, sid2;
    sid1 = createsem(0);
    sid2 = createsem(0);
    P(sid1);
 

    //print module
    int i = 5;
    if ((pid = fork()) > 0) {
        while(i>0){
        sleep(1);
        kill(pid, SIGUSR_1);
        P(sid1);
        printf("world!\n");
        V(sid2);
        i --;
        }
        time_t t;
        time(&t);
        printf("parent wakes at:%ld\n", t);
        wait(&s);
    }
    else if(pid == 0) {
        signal(SIGUSR_1, sig_load_children);
        while (i>0) {
        P(sid2);
        sleep(100);
        V(sid1);
        i--;
        }
        sleep(5);
        printf("child wakes at:");
        fflush(stdout);
        execl("/bin/date", "date", "+%s", NULL);
        exit(1);
    }
    printf("it's time to finish!!!");

    return 0;
}


void sig_load_children(){
    printf("hello, ");
    fflush(stdout);
}