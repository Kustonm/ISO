#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main (int argc , char *argv[]){

  pid_t 
  int prog = system(argv[1]);
  int s_fd = open(argv[3], O_WRONLY | O_CREAT, 0664);

}
