
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(){
        int pid;
        int child_pid;
        int status;
        int ret;

        pid=fork();

        switch(pid){
                case -1://fork fail
                        perror("fork failed\n");
                        break;

                case 0://at child process
                        execl("/bin/ls","ls","-al",NULL);
                        perror("execl failed\n");//if execl fails, this line would be overwritten by 'ls -al' from execl.
                        break;

                default://pid(parent)
                        child_pid=wait(&status);//waits for the child process to end, returns pid(child)
                        printf("Parent PID (%d), Child PID (%d)\n",getpid(),child_pid);
                        ret=WIFEXITED(status);//if not 0, child process normally ended
                        if(ret!=0){
                                printf("Child process normally terminated\n");
                        } else{
                                printf("Child process abnormally terminated\n");
                        }
                        exit(0);
        }
}
