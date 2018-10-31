#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

int main() {
    char * path = "hello.txt";
    struct stat * statpointer = malloc(sizeof(struct stat *));

    int b = stat(path, statpointer);

    printf("Value of pointer: %d\n", b);
    printf("Size: %ld\n", statpointer->st_size);
    
    /* WEIRD NUMBERS
    printf("==============================\n");
    printf("Size:\n");
    printf("In B: %ld\n", statpointer->st_size);
    printf("In KB: %ld\n", statpointer->st_size/1000);
    printf("In MB: %ld\n", statpointer->st_size/1000000);
    printf("In GB: %ld\n", statpointer->st_size/1000000000);
    printf("==============================\n");
    */
    printf("UserID: %d\n", statpointer->st_uid);
    printf("GroupID: %d\n", statpointer->st_gid);
    printf("Mode: %o\n", statpointer->st_mode);
    printf("Time last accessed:%s", ctime(&(statpointer->st_atime)) );
    //printf("Time last accessed:%ld\n", statpointer->st_atime );
    

    free(statpointer);
    return 0;
}
