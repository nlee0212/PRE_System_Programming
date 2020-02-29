#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
        int shmid,pid;
        char *shmaddr_parent, *shmaddr_child;
        shmid = shmget((key_t)1234,10,IPC_CREAT|0644);//generate shared memory

        if(shmid == -1){
                perror("shmget error\n");
                exit(1);
        }

        pid=fork();

        if(pid>0){      //parent process
                wait(0);//wait until child process finishes
                shmaddr_parent = (char*)shmat(shmid,(char*)NULL,0);//links to the shared memory
                printf("%s\n",shmaddr_parent);//can read from the shared memory
                shmdt((char*)shmaddr_parent);//free shmaddr_parent from the shared memory
        }
        else{   //child process
                shmaddr_child=(char*)shmat(shmid,(char*)NULL,0);//links to the shared memory
                strcpy((char*)shmaddr_child,"Hello Parent!");//can write at the shared memory
                shmdt((char*)shmaddr_child);//free shmaddr_child from the shared memory
                exit(0);
        }

        shmctl(shmid,IPC_RMID,(struct shmid_ds *)NULL);//delete the shared memory

        return 0;
}
