#include <stdio.h>
#include <stdlib.h>

//gcc efence.c
//./a.out

//gcc efence.c -lefence
//./a.out

int main()
{
	char *ptr = (char *) malloc(1024);
	ptr[0] = 0;

	/* Now write beyond the block */
	ptr[1024] = 0;
	exit(0);
}
