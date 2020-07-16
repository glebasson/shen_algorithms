#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHM_KEY 54321

int main(int argc, char const* argv[]) {
    key_t key1, key2;
    sscanf(argv[1], "%d", &key1);
    sscanf(argv[2], "%d", &key2);
    int id1 = shmget(key1, 1000, 0);
    int id2 = shmget(key2, 1000, 0);
    int * addr1 = shmat(id1, 0, 0600);
    int * addr2 = shmat(id2, 0, 0600);
    int my_id = shmget(SHM_KEY, 1000, IPC_CREAT | 0666);
    int * my_addr = shmat(my_id, 0, 0);
    size_t i = 0;
    for (i = 0; i < 100; i++) {
        *(my_addr+i) = *(addr1+i) + *(addr2+i);
        // printf("%d+%d=%d\n",*addr1, *addr2, *my_addr);
    }
    printf("%d\n", SHM_KEY);
    shmdt((void *)addr1);
    shmdt((void *)addr2);
    shmdt((void *)my_addr);
    return(0);
}