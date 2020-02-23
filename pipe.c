#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 255

char* msg = "Hello Child Process!";

int main(){
        char buf[255];
        int fd[2], pid, nbytes;

        if (pipe(fd) < 0) exit(1);//create pipe by using pipe(fd)

        pid=fork();//after this line, child/parent process differs

        if (pid > 0){//at parent process, pid==child process's pid
                printf("parent PID:%d, child PID:%d\n",getpid(), pid);
                write(fd[1], msg, MSGSIZE);//write at fd[1]
                exit(0);
        }

        else{//at child process, pid==0
                printf("child PID:%d\n", getpid());
                nbytes = read(fd[0], buf, MSGSIZE);//read by fd[0]
                printf("%d %s\n", nbytes, buf);
                exit(0);
        }

        return 0;
}
