/*
** filename: pinfo.c
** created: 11/10/26
** author: noah rethwisch
** description: demonstrate process control system calls
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sched.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int pid;
    // getting pid number
    if(argc == 2){
        pid = atoi(argv[1]);
    }else{
        pid = getpid();
    }
    // find priority
    if(getpriority(PRIO_PROCESS, (id_t)pid) != -1){
        printf("The priority of this PID is %d\n", getpriority(PRIO_PROCESS, (id_t)pid));
    }else{
        printf("invalid input\n");
        return -1;
    }
    // find scheduling method
    switch(sched_getscheduler((pid_t)pid)){
        case 0:
            printf("The scheduling method is SCHED_OTHER\n");
            break;
        case 1:
            printf("The scheduling method is SCHED_FIFO\n");
            break;
        case 2: 
            printf("The scheduling method is SCHED_RR\n");
            break;
        case 3:
            printf("The scheduling method is SCHED_BATCH\n");
            break;
        case 4:
            printf("The scheduling method is SCHED_ISO\n");
            break;
        case 5:
            printf("The scheduling method is SCHED_IDLE\n");
            break;
        case 6:
            printf("The scheduling method is SCHED_DEADLINE\n");
            break;
        default:
            printf("invalid input\n");
            return -1;
    }

    return 0;
}
