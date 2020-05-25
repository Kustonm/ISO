#include <stdio.h>
#include <iostream>
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

   char list[100];
   pid_t pid;
   int pipe[2];
    
  dup2(pipe[1],1);
  system("w");
  read(1,list,100);
  setbuf(stdout,list);
  
  int i = 0;
  for(i ; i < 100 ; i++){
     
  }
  dup2(list,1);
}

