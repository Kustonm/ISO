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
int fich = open(argv[2], O_WRONLY|O_APPEND|O_CREAT, 0600);
int Pos1;
int Pos2;

char error[512];
struct dirent *dir;
char aux[512];
char path[512];
d = opendir(argv[1]);
dir =readdir(d);

while((dir != NULL)){
	if ((dir->d_type & DT_LNK == 0) && (dir->d_type & DT_REG != 0) ){
		sprintf(path,"./%s/%s", argv[1], dir->d_name);
		}
		int auxF  = open(path, O_RDONLY);
		
		if (auxF == -1){
			sprintf(error, "No se puede abiri el fichero\n",dir->d_name); 
			perror(error);
		}
	
		int lenght = lseek(auxF, 0, SEEK_END);
		
		if(lenght < Pos1){
			sprintf(error, "Fuera del limite %d.\n",dir->d_name);
			perror(error);
		}
		 if (lenght < Pos2){
		 	if ((lenght - Pos1) > 512){
				while(lenght - Pos1  > 512){
					lseek(auxF,Pos1,SEEK_SET);
					read(auxF,aux,512);
					write(fich,aux,512);
				}
				lseek(auxF,Pos1,SEEK_SET);
				read(auxF,aux,(lenght - Pos1));
				write(fich,aux,(lenght- Pos1));
		}else{
			if ((Pos2 - Pos1) > 512 ){
				while( Pos2 - Pos1 > 512){
					lseek(auxF, Pos1 ,SEEK_SET);
					read(auxF, aux, 512);
					write(fich,aux,512);
				}
				lseek(auxF,Pos1,SEEK_SET);
				read(auxF,aux,(Pos2 -Pos1));
				write(fich,aux,(Pos2 -Pos1));
		      }else{
		      		lseek(auxF,Pos1,SEEK_SET);
				read(auxF,aux,Pos2);
				write(fich,aux,Pos2);
	}
	}

}

closedir(d);
close(fich);
return(0);
}
}

