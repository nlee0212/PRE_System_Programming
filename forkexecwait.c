#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
        int pid;
        int child_pid;
        int status;

        pid=fork();//new process made based on the parent process

        switch(pid){
                case -1:
                        perror("Fork failed.\n");
                        break;
                case 0://child process
                        execl("/bin/ls","ls","-al",NULL);
                        perror("execl failed.\n");//ls binary inserted instead
                        break;
                default: //parent process
                        child_pid=wait(NULL);//when the child process ends, it sends the SIGCHILD signal. after the signal, the lines under proceeds.
                        printf("ls completed\n");
                        printf("Parent PID (%d), Child PID (%d)\n",getpid(),child_pid);
                        exit(0);
        }
        return 0;
}
