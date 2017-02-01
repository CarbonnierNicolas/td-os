#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define EOF -1

int getchar(int fd){
	
	int tmp;
	if(read(fd,&tmp,1)) return tmp;
	return EOF;
	
//	autre facon de coder getchar :
//	int c;
//	return (read(fd,&c,1)?c:EOF;

}


int main(){
	
int fd;
fd=open("fd",O_RDONLY);	
getchar(fd);

}
