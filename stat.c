#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
int main() {
  //printf("FD: %d\n", a);

  struct stat * statpointer;

  int b = stat("/README.md", statpointer);

  //char * stringbean[256];

  printf(": %d\n", b);
  printf("Size: %d\n", statpointer->st_size);
  printf("Size: %dMB\n", (statpointer->st_size)/1000);
  printf("UserID: %d\n", statpointer->st_uid);
  printf("GroupID: %d\n", statpointer->st_gid);
  printf("Mode: %o\n", statpointer->st_mode);
  printf("Time last accessed:%s", ctime(&(statpointer->st_atime)) );
  printf("Time last accessed:%d\n", statpointer->st_atime );

  return 0;
}
