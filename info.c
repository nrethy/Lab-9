/*
** filename: info.c
** created: 11/10/26
** author: noah rethwisch
** description: demonstrate information maintenance system calls
** assignment name: Lab 9 System Calls
** section number: 111
*/

#include <stdio.h>
#include <time.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[]){
    // finding the time with clock_gettime
    struct timespec time;
    if(clock_gettime(CLOCK_REALTIME, &time) == 0){
        printf("The current time in nanoseconds is %lldns\n", (long long) time.tv_sec*1000000000 + time.tv_sec);
    }
    // getting hostname
    char host[100];
    if(gethostname(host, sizeof host) != -1){
        printf("The network's name is %s\n", host);
    }
    // finding the system information
    struct utsname info;
    if(uname(&info) == 0){
        printf("The operating system being run is %s\n", info.sysname);
        printf("The release of the operating system is %s\n", info.release);
        printf("The version of the operating system is %s\n", info.version);
        printf("The architecture is %s\n", info.machine);
    }
    if(get_nprocs() != -1){
        printf("The number of processors we have is %d\n", get_nprocs());
    }
    if(sysconf(_SC_PHYS_PAGES) != -1 && sysconf(_SC_PAGESIZE) != -1){
        printf("The amount of physical memory we have is %ld bytes\n", sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE));
    }
    if(sysconf(_SC_AVPHYS_PAGES) != -1 && getpagesize() != -1){
    printf("The amount of free bytes we have is %ld bytes\n", sysconf(_SC_AVPHYS_PAGES) * getpagesize());
    }
    return 0;
}
