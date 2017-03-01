#define MAXLINE 1024
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

//A FINIR
//man 2 chmode
//man 2 stat => s_time



int main(int argc, char **argv){
	char source[MAXLINE], dest[MAXLINE];
	if(argc != 3){
		printf("error");
		exit(-1);
		}
	
	strcpy(source, argv[1]);
	strcpy(dest, argv[2]);
	
	if(copie_arbre(source, dest == -1)){
		printf("error");
		exit(-1);
		}
		
	exit(0);
}

void copie_arbre(char *source, char *copie){
	struct stat stbuf;
	if(stat(source, &stbuf) == -1){ printf("error"); exit(-1);}
	int n;
	
	if(stbuf.st_mode & S_IFDIR != 0){
		n = copie_repertoire(source, copie);
		}
	else{
		if(stbuf.st_mode & S_IFREG != 0){
			n = copie_fichier(source, copie);
			}
		else n = -1;
		}
	
}

void copie_repertoire(char *source, char *copie){
	DIR *rep = opendir(source);
	mkdir(copie, 0777);
	char *tempsource, *tempdest;
	
	tempsource = source + strlen(source);
	*tempsource++ = '/';
	
	tempdest = copie + strlen(copie);
	*tempdest++ = '/';
	
	struct dirent *dir;
	while(dir = readdir(rep) != NULL){
		//on saute les .
		strcpy(tempsource, dir->d_name);
		strcpy(tempdest, dir->d_name);
		copie_arbre(*tempsource, *tempdest);
		closedir(rep);
		*(tempsource-1)='\o';
		*(tempdest-1)='\o';
	}
}
