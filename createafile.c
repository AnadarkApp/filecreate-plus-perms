/* EXAMPLE TO CREATE A FILE USING CREAT SYSTEM CALL WITH PERMISSSIONS
 gcc -Wall filename.c -o filename*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_PERMISSIONS "0640"

int main(int argc,char *argv[])
{
	// If no arguments are passed, print out usage and quit
	if (argc < 2)
	{
		printf("FILECREATE\n\n");
		printf("usage %s <filename> perms<opt>%s default\n " ,argv[0], DEFAULT_PERMISSIONS);
		return 1;
	}

	// If we can open the file to read, it already exists. Error and exit.
	if (fopen(argv[1], "r") != NULL)
	{
		fprintf(stderr, "File error: file already exists.");
		return -2;
	}

	// We got enough arguments to proceed, so create the file.
	FILE* newFile = fopen(argv[1], "w");
	if(newFile == NULL) {
		fprintf(stderr, "File error: unable to create new file.");
		return -3;
	}

	// Either use the passed permissions or use the default
	if (argc > 2){
		int permissions = strtol(argv[2], NULL, 8);
		chmod(argv[1], permissions);
	}
	else {
		int permissions = strtol(DEFAULT_PERMISSIONS, NULL, 8);
		chmod(argv[1], permissions);
	}

	fclose(newFile);

	return 0;
}
