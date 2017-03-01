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
	path();
}
