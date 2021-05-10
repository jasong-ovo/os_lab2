#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "mySem.h"
#include <stdio.h>
#include <unistd.h>
#include <memory.h>


int main(){
    int sid_mlock, sid_write, sid_read;
    int pid;
    int file1, file2;
    int segid;
    char *addr;
    sid_read = createsem(SHMKEY_read);
    sid_write = createsem(SHMKEY_write);

    //缓冲区空
    P(sid_read);

    //创建共享内存段
    if ((segid=shmget(12334, 128, IPC_CREAT|0666))==-1) printf("share memory's initialing failed\n");

    if ((pid=fork()) > 0){
        //父进程读缓冲区写入文件
        addr = shmat(segid, 0, 0);
        memset(addr, 0, 128);
        // printf("%s\n", addr);
        // printf("########\n");
        freopen("shmOut.txt", "w", stdout);
        while(1){
        P(sid_read);
        printf("%s", addr);
        fflush(stdout);
        memset(addr, 0, 128);      
        V(sid_write);
        }
    }
    else if ((pid==0)) {
        //子进程读文件写缓冲区
        freopen("shmIn.txt", "r", stdin);
        addr = shmat(segid, 0, 0);
        while(1){
        P(sid_write);
        // scanf("%s", addr);
        fgets(addr, 129, stdin);
        V(sid_read);
        }
    }

    return 0;
}

