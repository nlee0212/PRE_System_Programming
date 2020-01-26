#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAXLINE 64

int main(int argc, char **argv){
        char buf[MAXLINE];
        pid_t pid;
        printf("Na Yeon's Shell ver 1.0\n");

        while(1){
                memset(buf,0x00,MAXLINE);//initialize buffer
                fgets(buf,MAXLINE-1,stdin);

                if(strncmp(buf,"exit\n",5)==0){//if 'exit'
                        break;
                }
                buf[strlen(buf)-1]=0x00;//remove the '\n' character, leaving only the arg

                pid=fork();//new process made
                if(pid==0){//if this is a child process
                        if(execlp(buf,buf,NULL)==-1){
                                printf("Command execution failed\n");
                                exit(0);
                        }
                }
                if(pid>0) wait(NULL);//waits for the SIGCHILD signal, returns the PID of the child process
        }
        return 0;
}
