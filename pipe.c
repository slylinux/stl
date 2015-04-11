#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/myfifo"
#define SIZE 1024
int main(int argc,char* argv[])
{
	char s[]="hello world";
	char buf[SIZE];
	struct stat st;
	if(stat(FIFO_NAME,&st)==-1){
		unlink(FIFO_NAME);
		mkfifo(FIFO_NAME,0777);
	}
	if(argc!=2){
		printf("Usage: %s write/read\n",argv[0]);
		return -1;
	}
	if(!strcmp(argv[1],"write")){
		int fd=open(FIFO_NAME,O_WRONLY);
		write(fd,s,sizeof(s));
		close(fd);
	}else if(!strcmp(argv[1],"read")){
		int fd=open(FIFO_NAME,O_RDONLY);
		read(fd,buf,sizeof(buf));
		printf("read str=%s\n",buf);
		close(fd);		
	}
	return 0;
}
