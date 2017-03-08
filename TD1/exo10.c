#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#define MAX 1024
#define N 128
#define MAXBUF 1024

void separe (char *chaine, char **tab){
	char *q;
	int ntab;
	
	ntab = 0;
	q = chaine;
	while(*q != '\0'){
		tab[ntab++] = q;
		while(*q != '\0' && *q != ':'){
			*q++;
		}
		if(*q == ':'){
			*q++ = '\0';
			}
	}
	tab[ntab] = NULL;
	
}

struct SEP{
		char T[MAX][MAX];
		int compteur;
};
typedef struct SEP sep;

sep separer(char chaine[MAX]){
	if(chaine == NULL){printf("error"); exit(0);}
	sep separe;
	int i;
	int j=0;
	int cmpt=0;
	
	for(i=0; i<strlen(chaine); i++){
		if(chaine[i] == ':'){
			cmpt++;
			j=0;
			}
		else{
			separe.T[cmpt][j] = chaine[i];
			j++;
			}
		}
		separe.compteur = cmpt;
		return separe;
}

void path(){
	sep separe;
	char *tmp;
	int i;
	
	tmp = getenv("PATH");
	separe = separer(tmp);
	
	for(i=0; i<=separe.compteur; i++){
		printf("%s \n", separe.T[i]);
		}
}

int main(int argc, char *argv[]){
	
	int i;
	char *tab[20];
	char buf[MAXBUF];
	
	if(argc != 2){
		fprintf(stderr,"usage which cmd\n");
		exit(1);
	}
	
	separe(getenv("PATH"), tab);
	
	printf("my PATH \n");
	i = 0;
	while(tab[i] != NULL){
		printf("%s\n", tab[i]);
		i++;
	}
	
	printf("\n looking for %s cad\n", argv[1]);
	i =0;
	while(tab[i] != NULL){
		sprintf(buf," %s%s", tab[i], argv[1]);
		if(access(buf, X_OK) != -1){
			printf("%s\n", buf);
			exit(0);
		}
		i++;
	}
	
	fprintf(stderr,"command %s not found\n", argv[1]);
	exit(1);
	
	path();
}
