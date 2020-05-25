#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>



int main() {
    int p1[2];
    int p2[2];
    int pid;

    pipe(p1);
    pipe(p2);

    pid = fork();    
    
    if((pid == 0) {
        
        if(close(1) == -1){
          printf("Error al cerrar el canal 1.\n");
        }
        if(dup(p1[1]) == -1){
          printf("Error dup.\n");
          
        }
        if((close(p1[1])) == -1){ 
            printf("Error al cerrar pfd[1].\n");
        }
        if((close(p1[0])) == -1){
          printf("Error al cerrar pfd[0].\n");
        }
        if((close(p2[0])) == -1){
          printf("Error al cerrar pfd2[0].\n");
        }
        if((close(p2[1])) == -1){
          printf("Error al cerrar pfd2[1].\n");
        }

        execlp("who", "who", NULL);
        error("Error execlp.\n");

    } else if(pid == -1) {
    printf("No ha sido posible crear el primer hijo.\n");
    }
  
    if((pid == 0) {
        if(close(0) == -1){ printf ("Error al cerrar el canal 0.\n"); 
        }

        if(dup(p1[0]) == -1){ printf("Error dup.\n"); 
        }

        if((close(p1[0])) == -1){ printf("Error al cerrar pfd[0].\n");
        }

        if((close(p1[1])) == -1){ printf("Error al cerrar pfd[1].\n");
        }

        if(close(1) == -1){ printf("Error al cerrar el canal 1.\n");
        }

        if(dup(p2[1]) == -1){ printf("Error dup.\n");}

        if((close(p2[1])) == -1){ printf("Error al cerrar pfd2[1].\n");
        }

        if((close(p2[0])) == -1){ printf("Error al cerrar pfd2[0].\n");
        }

        execlp("grep", "grep", "acaf00", NULL);

    } else{ if(pid == -1){ printf("No ha sido posible crear el segundo hijo.\n");}

    if((pid = fork()) == 0){
        if(close(0) == -1){ printf("Error al cerrar el canal 0.\n");}

        if(dup(p2[0]) == -1){ error("Error dup.\n");}

        if((close(p2[0])) == -1){ printf("Error al cerrar pfd2[0].\n");
        }

        if((close(p2[1])) == -1){ printf("Error al cerrar pfd2[1].\n");
        }

        if((close(p1[0])) == -1){ printf("Error al cerrar pfd[0].\n");
        }

        if((close(p1[1])) == -1){ printf("Error al cerrar pfd[1].\n");
        }

        execlp("sort", "sort", NULL);
        

    } else if(pid == -1){ error("No ha sido posible crear el tercer hijo.\n");
    }

    wait(NULL);

    if((close(p1[0])) == -1){ printf("Error al cerrar pfd[0].\n");
    }

    if((close(p1[1])) == -1){ printf("Error al cerrar pfd[1].\n");
    }
   
    if((close(p2[0])) == -1){ printf("Error al cerrar pfd2[0].\n");
    }

    if((close(p2[1])) == -1){ printf("Error al cerrar pfd2[1].\n");
    }

    return 0;
}
}
