#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void decompose(char *in){
	int i;
	for(i=0; i<strlen(in)+1; i++){
		if(in[i] == ':') in[i] = '\o';
	}
}

int main(int argc, char **argv){
	char *p = getenv("PATH");
	decompose(p);
	return 0;	
}
