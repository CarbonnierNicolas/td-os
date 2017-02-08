#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int my_open(char **fichier){
	
	int fd;
	fd = open(*fichier, O_RDONLY);
	return fd;
}



int main(int argc, char *argv[]){
	
	int fichier;
	fichier = my_open(&argv[1]);
}
