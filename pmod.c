/*
** filename: pmod.c
** created: 11/10/26
** author: noah rethwisch
** description: demonstrate altering processes in linux
*/

#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    struct timespec timer = {
        .tv_sec = 1,
        .tv_nsec = 837272638L};
    nice(10);
    nanosleep(&timer, NULL);
    printf("Bye\n");
    return 0;
}
