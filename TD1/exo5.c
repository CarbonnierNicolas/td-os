#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define EOF -1
#define MAXBUF 1024

int bgetchar(void){
	
	static unsigned char buf[MAXBUF];
	static int ncar;
	static char *p;
	
	if(ncar == 0){
		ncar = read(0, buf, MAXBUF);
		p = buf;
		};
	if(ncar-- > 0) return *p++;
	else return EOF;
}


int main(){
	
int res;

while(1){
	res = bgetchar();
	if(res == EOF){
	printf("EOF\n");
	break;
	}
	printf("got %c \n", res);
	}
return 0;
}
