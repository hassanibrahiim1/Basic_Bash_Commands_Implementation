#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define RET 0
#define ERR_RET -1

#define MAX_COUNT 256

int main(int argc, char* argv[])
{
	char buf[MAX_COUNT];
	int count = 0;
	//check user input (arg)
	if( 3 != argc)
	{
		printf("ERROR PLEASE WRITE SOURCE AND DESTINATION IN CORRECT WAY\n");
		return ERR_RET;
	}
	
	int fd_src = open(argv[1], O_RDONLY);
	if( -1 == fd_src)
	{
		printf("Source File Doesn't Exist !\n");
		return ERR_RET;
	}
	
	char* des_buf = strcat(argv[2],"/");
	des_buf = strcat(des_buf, argv[1]);

	int fd_des = open(des_buf, O_CREAT|O_WRONLY);
	
	do
	{
		count = read(fd_src, buf, MAX_COUNT);
                write(fd_des, buf, count);
	}while(count);

	close(fd_src);
        close(fd_des);
        remove(argv[1]);
	return RET;


}
