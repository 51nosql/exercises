#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

// gcc -I/usr/include/mysql mysql_connect1.c -L/usr/lib/mysql -lmysqlclient

int main(int argc, char *argv[])
{
	MYSQL *conn_ptr;

	conn_ptr = mysql_init(NULL);
	if(!conn_ptr) {
		fprintf(stderr, "mysql_init failed\n");
		return EXIT_FAILURE;
	}

	conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "123456",
									"test", 0, NULL, 0);

	if(conn_ptr) {
		printf("Connection success\n");
	} else {
		printf("Connection failed\n");
	}

	mysql_close(conn_ptr);
	return EXIT_SUCCESS;
}

