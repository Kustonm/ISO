#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_BUF 512

int main (int argc , char *argv[]){

  DIR *d;
  d=opendir(argv[1]);


  if (argc != 2){
        fprintf(stderr, "Se esperaban 2 argumentos pero se recivieron %d\n", argc);
        exit(-1);
  }

  char buf1[MAX_BUF];
  char path[MAX_BUF];

  if (!d){
        printf("Error al abrir el directorio");
        perror(buf1);
        exit (-2);
  }

  struct dirent *dir;
  while(dir=readdir(d)){
        sprintf(path, "%s/%s", argv[1], dir->d_name);
        printf(path);
        if (dir->d_type == DT_DIR){
           chmod( path, 0550);
        }else if(dir->d_type == DT_REG){
           chmod(path, 0022);
        }
  }

 closedir(d);

 return(0);

}
