#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int n,fd;
if(2!=argc)
{
printf("\n Usage \n");
return 1;
}
char buff[50];	
printf("Enter text to write in the file:\n");
gets(buff);
n=strlen(buff);
fd=open(argv[1],O_CREAT | O_RDWR, 0777); 
write(fd, buff, n);
write(1,buff,n);
printf("\n");
}
