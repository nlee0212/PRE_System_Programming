#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/types.h>

int main(){
        int which=PRIO_PROCESS;
        id_t pid;
        int ret;

        pid = getpid();
        ret = getpriority(which,0);//priority of current process
        printf("PID=%d, PRIORITY=%d\n",pid,ret);
        ret=nice(10);//change priority to 10
        ret=getpriority(which,0);//priority of current process
        printf("PID=%d, PRIORITY=%d\n",pid,ret);

        ret = setpriority(which, 0, 5);//set priority to 5
        ret = getpriority(which, 0);
        printf("PID=%d, PRIORITY=%d\n",pid,ret);

        return 0;
}
