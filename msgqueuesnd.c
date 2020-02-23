#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

//A file to send a message

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

        return 0;
}

//The message will be saved at a certain msgid (key 1234) at the kernel
