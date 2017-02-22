#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>


int main(int argc, char *argv[]){
	
	DIR *fd;
	fd = opendir(argv[1]);
	
	struct dirent *dir;
	
	



}
