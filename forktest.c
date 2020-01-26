#include <sys/types.h>//for pid_t 
#include <unistd.h>//for fork() systemcall
#include <stdio.h>

int main(){
  pid_t pid;
  printf("Before fork() call\n");
  pid=fork();//after fork() call, two processes existing (1 parent 1 child) -> two lines printed
  
  if(pid==0) printf("This is Child process. PID is %d\n",pid);
  if(pid>0) printf("This is Parent process. PID is %d\n",pid);
  else printf("fork() failed.\n");
  
  return 0;
}
