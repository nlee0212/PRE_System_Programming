#include <stdlib.h>
#include <stdio.h>

int main(void){
        void exithandling(void);
        void goodbyemsg(void);
        int ret;

        ret=atexit(exithandling);
        if (ret!=0) perror("Error in atexit\n");
        ret=atexit(goodbyemsg);
        if (ret!=0) perror("Error in atexit\n");
        exit(EXIT_SUCCESS);
}

void exithandling(void){
        printf("exit handling\n");
}

void goodbyemsg(void){
        printf("see you again!\n");
}

/*
등록순서: exithandling -> goodbyemsg
출력숙서: see you again! -> exit handling
=> 출력순서는 등록순서의 반대!
*/
