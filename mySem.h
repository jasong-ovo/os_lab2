#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define SHMKEY_mem 1234
#define SHMKEY_read 5678
#define SHMKEY_write 6789

union semun {   /* 如sem.h中已定义，则省略 */
          int val;
          struct semid_ds *buf;
          ushort *array;
     } ;

// #ifndef sembuf
// struct sembuf
// {
//     short sem_num;
//     short sem_op;
//     short sem_flg;
// };
// #endif


int createsem(key_t key);
void P(int sid);
void V(int sid);
static void semcall(int sid, int op);
void test();