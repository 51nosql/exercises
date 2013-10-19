#include <signal.h>
#include <stdio.h>
#include <unistd.h>

//Ctrl+C

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n", sig);
	(void) signal(SIGINT, SIG_DFL); //resume to default behavior
}

int main()
{
	(void) signal(SIGINT, ouch);

	while(1) {
		printf("Hello World!\n");
		sleep(1);
	}
}
