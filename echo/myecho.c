#include<stdio.h>
#include<string.h>

#define RET 0

int main(int argc, char* argv[])
{
	
	for(int i = 1 ; i < argc ; i++)
	{
		printf("%s ", argv[i]);
	}	
	printf("\n");
	return RET; 
}
