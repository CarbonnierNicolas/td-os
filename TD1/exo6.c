#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	struct stat fi;
	stat(argv[1], &fi);
	
	if(fi.st_mode & S_IFREG) write(1,"-",1);
	if(fi.st_mode & S_IFDIR) write(1,"d",1);
	if(fi.st_mode & S_IFIFO) write(1,"l",1);
	
	if(fi.st_mode & S_IRUSR) write(1,"r",1); else write(1,"-",1);
	if(fi.st_mode & S_IWUSR) write(1,"w",1); else write(1,"-",1);
	if(fi.st_mode & S_IXUSR) write(1,"x",1); else write(1,"-",1);
	
	if(fi.st_mode & S_IRGRP) write(1,"r",1); else write(1,"-",1);
	if(fi.st_mode & S_IWGRP) write(1,"w",1); else write(1,"-",1);
	if(fi.st_mode & S_IXGRP) write(1,"x",1); else write(1,"-",1);
	
	if(fi.st_mode & S_IROTH) write(1,"r",1); else write(1,"-",1);
	if(fi.st_mode & S_IWOTH) write(1,"w",1); else write(1,"-",1);
	if(fi.st_mode & S_IXOTH) write(1,"x",1); else write(1,"-",1);
	write(1,"\n",1);

return 0;
}
