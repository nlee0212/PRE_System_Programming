#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void signal_handler (int signo){
        printf("Catch SIGINT!, but no stop\n");
}

int main(void){
        if(signal (SIGINT, signal_handler) == SIG_ERR){//if SIGINT, show signal_handler instead
                printf("Can't catch SIGINT!\n");
                exit(1);
        }

        for(;;)//infinitely pause
                pause();//for executing this file at the background to send other signals from other processes
        return 0;
}

/*
by writing this line below at the command line,
-------------------------------------------------
./sigloop &
-------------------------------------------------
this file would be running at the background.

by using sigkill, we will send the SIGINT signal to this file to see if this file receives it or not.
*/
