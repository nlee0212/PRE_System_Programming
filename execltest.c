#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
        printf("execute ls\n");
        execl("/bin/ls","ls","-al",NULL);//MUST include the directory
        perror("execl failed\n");//if execl not fails, then this line does not proceed.
        exit(1);
}
