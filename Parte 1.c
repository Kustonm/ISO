#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define MAX_BUF 512

int main(int argc, char** argv){
	if (argc != 5){
		fprintf(stderr, "Se esperaban 4 argumentos pero se recivieron %d\n", argc);
		fprintf(stderr, "Modo de empleo: \"./util_1 dir1 resultado  pos1 pos2\"\n");
		exit(-1);
	}

	char buf1[MAX_BUF];
	char buf2[MAX_BUF*2];

	DIR *dir_stream = opendir(argv[1]);
	if (!dir_stream){
		sprintf(buf1,"Error al abrir el directorio \"%s\": ", argv[1]);
		perror(buf1);
		exit(-2);
	}	

	int result_fd = open(argv[2], O_WRONLY | O_CREAT, 0664);
	if (!result_fd){
		sprintf(buf1,"Error al crear y abrir el fichero \"%s\":", argv[2]);
		perror(buf1);
		exit(-3);
	}

	int i;
	int strlen_1 = strlen(argv[3]);
	for (i = 0 ; i < strlen_1 ; i++){
		if (!isdigit(argv[3][i])){
			fprintf(stderr,"El argumento 3 \"pos1\" ha de ser un numero.\n");
			exit(-4);
		}
	}
	int pos1 = atoi(argv[3]);
	int strlen_2 = strlen(argv[4]);
	for (i = 0 ; i < strlen_2 ; i++){
		if (!isdigit(argv[4][i])){
			fprintf(stderr,"El argumento 4 \"pos2\" ha de ser un numero.\n");
			exit(-4);
		}
	}	
	int pos2 = atoi(argv[4]);

	if (pos1 >= pos2){
		fprintf(stderr, "Error: el argumento pos1 (%d) es mayor que pos2 (%d)\n", pos1, pos2);
		exit(-5);
	}


	struct dirent *dir;
	while(dir = readdir(dir_stream)){
		if ((dir->d_type & (DT_LNK | DT_REG)) != DT_REG)
			continue;

		sprintf(buf1, "%s/%s", argv[1], dir->d_name);
		int fd = open(buf1, O_RDONLY);
		if (!fd){
			sprintf(buf2, "Error al abrir el fichero \"%s\":", buf1);
			perror(buf2);
			continue;
		}

		int len = lseek(fd, 0, SEEK_END);
		if (pos1 > len){
			fprintf(stderr, "pos1 (%d) es mayor que la longitud del fichero %s (%d)\n", pos1, buf1, len);
			continue;
		}
		if (pos2 > len){
			fprintf(stderr, "pos2 (%d) es mayor que la longitud del fichero %s (%d)\n", pos2, buf1, len);
			continue;
		}

		int pos = lseek(fd, pos1, SEEK_SET);
		while (pos < pos2){
			int read_len = pos2 - pos;
			if (read_len > MAX_BUF) 
				read_len = MAX_BUF;

			read(fd, buf2, read_len);
			write(result_fd, buf2, read_len);

			pos += read_len;
		}

		close(fd);

	}
	closedir(dir_stream);
	close(result_fd);
	
	exit(0);

}
