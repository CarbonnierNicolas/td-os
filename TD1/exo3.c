#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	
int titi, toto;
int tmp;
toto = open("toto", O_RDONLY);
titi = open("titi", O_CREAT | O_WRONLY | S_IWUSR | S_IRUSR);

while(read(toto,&tmp,1)){
	 
	write(titi,&tmp,1);

}


close(toto);
close(titi);
}
