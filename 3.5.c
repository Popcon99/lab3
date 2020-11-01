#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int  main(void)
{
        int fd[2],f,i,num,flag=1; pipe(fd);
	f =fork();  
	
	if(f>0)
	{
	printf("CHILD PROCESS..");
	printf("\nEnter a number :");
	scanf("%d",&num);

	if(num==1)flag=0;
	for(i=2;i<=(num/2);i++)
	if(num%i==0)
	{

	flag=0;
	break;
	}

	close(fd[0]);
	write(fd[1], &flag, sizeof(flag));
	}
else if(f==0)
{
printf("\n\nPARENT PROCESS.");
close(fd[1]);
read(fd[0], &flag, sizeof(flag));

if(flag==1)printf("\n\tlt is a prime number..\n");
else 
printf("\n\t it s not a prime number...\n");

}return EXIT_SUCCESS;
}



