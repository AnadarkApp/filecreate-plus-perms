/* EXAMPLE TO CREATE A FILE USING CREAT SYSTEM CALL WITH PERMISSSIONS 
 gcc -Wall filename.c -o filename*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
 
int main(int argc,char *argv[])
{
    int fd; // file descriptor
    
    if (argc < 2)
    {
	fprintf(stdout,"FILECREATE\n\n");
        fprintf(stdout,"usage %s <filename> perms<opt>0640 default\n " ,argv[0]);
        return 1;
    }


     if (access( argv[1], F_OK ) != -1)
    {
        perror("close");
        fprintf(stdout,"File already exists, terminating");
}

if (argc > 2){
int permset=(strtol(argv[2],NULL,8));
fprintf(stdout,"permset is equal to: %i\n ", permset);
fd = creat(argv[1],permset); // Reference man 2 creat
    if(fd == -1)
        perror("creat");
}


    if (close(fd) == -1)
        perror("close");
    
   
    return 0;
}

