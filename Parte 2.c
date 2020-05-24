#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>

int main (int argc , char *argv[]){

  DIR *d;
  
  struct dirent *dir;
  
  if (d == NULL){
    printf("No se a podido abrir");
    return (0);
  }
  
  while((dir == readdir(d) != NULL){
      if 
  }
      
 closedir(d);
 return(0);

}
