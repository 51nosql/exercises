#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct {
	int integer;
	char string[24];
} RECORD;

#define NRECORDS (100)

int main()
{
	exit(0);
}
