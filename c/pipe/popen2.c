#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *write_fp;
	char buffer[BUFSIZ + 1];

	sprintf(buffer, "Once upon a time, there was...\n");
	write_fp = popen("od -c", "w");
	if(write_fp != NULL) {
		//echo "Once upon a time, there was..." | od -c
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
