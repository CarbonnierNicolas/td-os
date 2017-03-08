#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#define n 10

int main (int argc, char *argv[]){
	
	int i;
	int pid, status;
	
	for(i=0; i<n; i++){
		pid = fork();
		if(pid == -1) exit(0);
		if(pid == 0) exit(getpid()%10);
		}
	
	for(i=0; i<n; i++){
		pid = wait(&status);
		printf("PID du fils : %d\n", pid);
		printf("status : %d\n", WEXITSTATUS(status));
	}
return(0);
}
