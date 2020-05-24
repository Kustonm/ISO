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

while((dir =readdir(d) != NULL)){
	if (dir -> d_type == 8){
		sprintf(path,"./%s/%s", argv[1], dir->d_name);
		if (open(path, O_RDONLY) == -1){
			sprintf(error, "No se puede abiri el fichero\n",dir->d_name); 
			perror(error);
		}
		if(lseek(open(path, O_RDONLY), 0, SEEK_END)){
			sprint(error, "Fuera del limite %d.\n",dir->d_name);
			perror(error);
		}
		 if ((lseek(open(path, O_RDONLY), 0, SEEK_END) < Pos2)){
		 	if ((lseek(open(path, O_RDONLY), 0, SEEK_END) - Pos1 > 512)){
				while((open(path, O_RDONLY)) - Pos1  > 512){
					lseek(open(path, O_RDONLY),Pos1,SEEK_SET);
					read(open(path, O_RDONLY),aux,512);
					write(fich,aux,512);
				}
				lseek(open(path, O_RDONLY),Pos1,SEEK_SET);
				read(open(path, O_RDONLY), 0, SEEK_END),aux,((lseek(open(path, O_RDONLY), 0, SEEK_END) - Pos1));
				write(fich,aux,(lseek(open(path, O_RDONLY), 0, SEEK_END)- Pos1));
		}else{
			if ((Pos2 - Pos1) > 512 ){
				while( Pos2 - Pos1 > 512){
					lseek(open(path, O_RDONLY), Pos1 ,SEEK_SET);
					read(open(path, O_RDONLY), aux, 512);
					write(fich,aux,512);
				}
				lseek((open(path, O_RDONLY)),Pos1,SEEK_SET);
				read(open(path, O_RDONLY),aux,(Pos2 -Pos1));
				write(fich,aux,(Pos2 -Pos1));
		      }else{
		      		lseek(open(path, O_RDONLY),Pos1,SEEK_SET);
				read(open(path, O_RDONLY),aux,Pos2);
				write(fich,aux,Pos2);
	}
	}

}

close(d);
close(fich);
return(0);
}
}
}
