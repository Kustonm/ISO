#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>



int main() {
    int pfd[2];
    int pfd2[2];
    int pid;

    pipe(pfd);
    pipe(pfd2);

    if((pid = fork()) == 0) {
        
        if(close(1) == -1){
          printf("Error al cerrar el canal 1.\n");
        }
        if(dup(pfd[1]) == -1){
          printf("Error dup.\n");
          
        }
        if((close(pfd[1])) == -1){ 
            printf("Error al cerrar pfd[1].\n");
        }
        if((close(pfd[0])) == -1){
          printf("Error al cerrar pfd[0].\n");
        }
        if((close(pfd2[0])) == -1){
          printf("Error al cerrar pfd2[0].\n");
        }
        if((close(pfd2[1])) == -1){
          printf("Error al cerrar pfd2[1].\n");
        }

        execlp("who", "who", NULL);
        error("Error execlp.\n");

    } else if(pid == -1) {
    printf("No ha sido posible crear el primer hijo.\n");
    }
  
    if((pid = fork()) == 0) {
        if(close(0) == -1){ error("Error al cerrar el canal 0.\n"); 
        }

        if(dup(pfd[0]) == -1){ printf("Error dup.\n"); 
        }

        if((close(pfd[0])) == -1){ printf("Error al cerrar pfd[0].\n");
        }

        if((close(pfd[1])) == -1){ printf("Error al cerrar pfd[1].\n");
        }

        if(close(1) == -1){ printf("Error al cerrar el canal 1.\n");
        }

        if(dup(pfd2[1]) == -1){ printf("Error dup.\n");}

        if((close(pfd2[1])) == -1){ printf("Error al cerrar pfd2[1].\n");
        }

        if((close(pfd2[0])) == -1){ printf("Error al cerrar pfd2[0].\n");
        }

        execlp("grep", "grep", "acaf00", NULL);

    } else{ if(pid == -1){ printf("No ha sido posible crear el segundo hijo.\n");}

    if((pid = fork()) == 0){
        if(close(0) == -1){ printf("Error al cerrar el canal 0.\n");}

        if(dup(pfd2[0]) == -1){ error("Error dup.\n");}

        if((close(pfd2[0])) == -1){ printf("Error al cerrar pfd2[0].\n");
        }

        if((close(pfd2[1])) == -1){ printf("Error al cerrar pfd2[1].\n");
        }

        if((close(pfd[0])) == -1){ printf("Error al cerrar pfd[0].\n");
        }

        if((close(pfd[1])) == -1){ printf("Error al cerrar pfd[1].\n");
        }

        execlp("sort", "sort", NULL);
        

    } else if(pid == -1){ error("No ha sido posible crear el tercer hijo.\n");
    }

    wait(NULL);

    if((close(pfd[0])) == -1){ printf("Error al cerrar pfd[0].\n");
    }

    if((close(pfd[1])) == -1){ printf("Error al cerrar pfd[1].\n");
    }
   
    if((close(pfd2[0])) == -1){ printf("Error al cerrar pfd2[0].\n");
    }

    if((close(pfd2[1])) == -1){ printf("Error al cerrar pfd2[1].\n");
    }

    return 0;
}
}
