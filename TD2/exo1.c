#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main (void){
	
	int Pnum;
	Pnum = fork();
	
	if(Pnum == -1){
		printf("Erreur");
		exit(-1);
	}
	else {
		if(Pnum == 0){
		printf("Hello c'est le processus fils\n");
		printf("Mon pid est : %d\n", getpid());
		printf("Le pid de mon pere est : %d\n", getppid());
		exit(getpid()%10);
		}
		else{
			int status;
			printf("Hello c'est le processus pere\n");
			printf("Le pid de mon fils est : %d\n", Pnum);
			printf("Mon pid est : %d\n", getpid());
			wait(&status);
			printf("status : %d\n", status);
		
		if(WIFEXITED(status)){
			printf("exited status %d\n", WEXITSTATUS(status));}
			else if(WIFSIGNALED(status)){
			printf("killed by signal %d\n", WTERMSIG(status));}
			else if(WIFSTOPPED(status)){
			printf("stopped by signal %d\n", WSTOPSIG(status));}
			else if(WIFCONTINUED(status)){
			printf("continued");}
		}
		exit(0);
	}
return(0);
}
	
	

