#include <stdio.h>
#include <stdlib.h>

int main()
{
	char tmpname[L_tmpnam];
	char *filename;
	FILE *tmpfp;

	filename = tmpnam(tmpname); //warning
	printf("Temporary file name is: %s\n", filename);
	tmpfp = tmpfile();
	if(tmpfp)
		printf("Opened a temporary file OK\n");
	else
		perror("tmpfile");

	exit(0);
}

