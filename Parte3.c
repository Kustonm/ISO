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

  pid_t pid;
  int my_pipe[2];
  int ret;
  char BUFFER_1[512];  
  
  int prog1 = system(argv[1]);
  
  int prog2 = system(argv[1]);
  int s_fd = open(argv[3], O_WRONLY | O_CREAT, 0664);
    
  if (ret == -1 ){
      perror("pipe");
      exit(1);
  }
  
  
  close(my_pipe[1]);
  dup(my_pipe[0],STDOUT_FILENO);
  close(my_pipe[0]);
  
  if(pid == 0){     
    
  

   
}
