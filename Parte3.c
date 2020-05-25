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
  
  char buf1[512];
  char buf2[512];
  
  int s_fd = open(argv[3], O_WRONLY | O_CREAT, 0664);
    
  pid_t pid;
  int pipe[2];
  
  dup2(pipe[1],1);
    int prog1 = system(argv[1]);
    read(1, buf1, 512);
    int prog2 = system(argv[1]);
    read(1,buf2,512);
  
  if(strcmp(buf1,buf2) == 0 ){
      write(s_fd, buf1,512);
  }
  
  close(s_fd);
  close(pipe[1]);
  close(pipe[0]);
  return(0);
}
