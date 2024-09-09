#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define RET 0
#define ERR_RET -1
#define BYTE_COUNT 200

int main(int argc, char * argv[])
{
	char buf[200];
	int count = 0;
	
	//CHECK NO. argc
	if( 3 != argc )
	{
		printf("ERROR Number of Argument must be 3\n");
		return ERR_RET;
	}
	
	//CHECK THAT SOURCE FILE IS ALREADY EXIST
	int src_fd = open(argv[1], O_RDONLY );
	if( -1 == src_fd )
	{
		printf("ERROR SOURCE FILE NOT FOUND\n");
		return ERR_RET;
	}

	//CREATE DESTINATION FILE
	int des_fd = open( argv[2], O_CREAT|O_WRONLY|O_TRUNC );
	
	//COPYING DATA FROM SRC TO DES
	do
	{
		count = read( src_fd, buf, BYTE_COUNT);
		write( des_fd, buf, count);
	}while( count );

	return RET;


}
