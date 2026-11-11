/*
** filename: finfo.c
** created: 11/10/26
** author: noah rethwisch
** description: display file information about a provided file
** assignment name: Lab 9 System Calls
** section number: 111
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[]){
    mode_t perms[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
    const char *names[] = { "owner read",  "owner write", "owner execute", "group read",  "group write", "group execute", "others read", "others write", "others execute"};
    struct stat ft;
    lstat(argv[1], &ft);
    // what kind of file is this
    if(S_ISREG(ft.st_mode)) {
        printf("regular file\n");
    }else if(S_ISDIR(ft.st_mode)){
        printf("directory\n");
    }else{
        printf("error\n");
        return -1;
    }
    // what are the permissions here
    printf("Permissions:\n");
    for(int i=0; i<9; i++){
        if(ft.st_mode & perms[i]){
            printf("%s\n", names[i]);
        }
    }
    // userID
    printf("Owner userID; %u\n", ft.st_uid);
    // file size
    printf("Size: %lld bytes\n", (long long)ft.st_size);
    // getting time of last modification
    printf("Last modified %s", ctime(&ft.st_mtime));
    return 0;
}
