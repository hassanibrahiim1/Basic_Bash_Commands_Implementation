#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define ERR_RET -1
#define RET 0 
#define PATH_MAX 256
int main()
{
	char buf[PATH_MAX];
	if( getcwd(buf,PATH_MAX ) == NULL)
	{
		printf("ERROR Path Name ecxeeds PATH_MAX\n");
		return ERR_RET;
	}
	printf("%s\n", buf);
	return RET;
	
}
