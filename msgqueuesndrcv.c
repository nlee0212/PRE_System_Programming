#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

//A file that can send and receive a message in a single process

typedef struct msgbuf{
        long type;
        char text[50];
}MsgBuf;

int main(void){
        int msgid, len;
        MsgBuf msg;
        key_t key=1234;

        msgid = msgget(key, IPC_CREAT|0644);

        if(msgid == -1){
                perror("msgget");
                exit(1);
        }

        msg.type=1;
        strcpy(msg.text, "Hello Message Queue\n");

        if(msgsnd(msgid, (void*)&msg, 50, IPC_NOWAIT) == -1){
                perror("msgsnd");
                exit(1);
        }

        len=msgrcv(msgid, &msg, 50, 0, 0);
        printf("Received Message is '%s' [%d]\n",msg.text, len);

        return 0;
}

/*
This code is just to show that 'message queue' can work in a single process.
Pipe can only send data from a parent process to a child process, 
but 'Message Queue' can do it both ways, or even in a single process.
*/
