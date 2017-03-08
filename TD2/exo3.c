#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void creation(int n, int m){
	int i, pid;
	for(i=0; i<n; i++){
		pid = fork();
		printf("pid : %d\n", pid);
		if(pid == -1){printf("error"); exit(0);}
		if(pid == 0) exit(getpid()%10);
		if(m>1) creation(n,m-1);
		else{
			for(i=0; i<n; i++){
			wait(&pid);
			}
		}
	}
}

int main (int argc, char *argv[]){
	
	//if(argc != 2){printf("too few arguments\n"); exit(0);}
	//int  n = atoi(argv[1]);
	//int m = atoi(argv[2]);
	
	//printf(" argv[1] = %d\n", n);
	//printf(" argv[2] = %d\n", m);
	
	creation(3,5);

	exit(0);
}
