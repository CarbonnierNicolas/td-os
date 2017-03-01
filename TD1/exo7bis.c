#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>


int main(int argc, char *argv[]){
	
	DIR *rep = NULL;
	rep = opendir("/");
	if(rep == NULL){
		printf("N'ouvre pas");
		exit(-1);
		}
	
	struct dirent *dir;
	while((dir = readdir(rep)) != NULL){
		if(dir->d_name[0] != '.'){
			printf("%s\n", dir->d_name);
			}
		if(closedir(rep == 1)){
			printf("ne ferme pas");
			exit(-1);
			}
		}
		
	return 0;
		
}
	




