#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
        char* envp[]={"USER=NLEE0212",NULL};//if you don't include the PATH here, you should include it in the execve() function.
        char* arg[]={"ls", "-al", NULL};

        printf("execute ls\n");
        execve("/bin/ls",arg,envp);
        perror("execve failed\n");
        exit(1);
}
