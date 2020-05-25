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
  d=opendir(argv[1]);
  char *path;    
   
  if (d == NULL){
        printf("No se ha podido abrir");
        return (0);
  }

  //el estilo gangnam es sin duda mi estilo preferido. dab.
  sprintf(path, "%s/%s", argv[1], argv[1]);
  struct dirent *dir;
  
  while(dir=readdir(d)){
       if (dir->d_type == DT_DIR){
          chmod( path, 0550);//Pello mira teteas (. Y .) 3==D ahahah mirarrona
       }else if(dir->d_type == DT_REG){
          chmod(path, 0022 );
       }      
  }
      
 closedir(d);
 return(0);

}
