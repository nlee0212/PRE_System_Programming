#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
        int pid, result;
        int sig_num;

        if(argc !=3){//there has to be 2 arguments
                printf("usage %s [pid] [signum]\n",argv[0]);
                exit(1);
        }

        pid = atoi(argv[1]);
        sig_num = atoi(argv[2]);
        result = kill(pid, sig_num);//sends the signal number to the process

        if(result<0){//if the signal does not send, kill returns -1
                perror("Sending Signal failed!\n");
                exit(1);
        }

        return 0;
}

/*
by typing the line below at the command line
---------------------------------------------
./sigkill [pid of sigloop] 2(the signal number of SIGINT)
---------------------------------------------
this file sends SIGINT at the process.

However, the 'sigloop' file is running at the background, and has re-defined SIGINT by printing
'Catch SIGINT!, but no stop'
and does not kill the process.

after this command, if you type in 'ps' to see process lists, you would see that sigloop process has survived,
even though it received the SIGINT signal.

** you can find the pid of a certain process by typing in 'ps' at the command line.
*/
