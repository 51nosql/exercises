#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

int main(int argc, char *argv[])
{
	MYSQL my_connection;
	int res;

	mysql_init(&my_connection);
	if(mysql_real_connect(&my_connection, "localhost", "root",
				"123456", "test", 0, NULL, 0)) {
		printf("Connection success\n");

		res = mysql_query(&my_connection, "CREATE TABLE cd( \
				id INTEGER AUTO_INCREMENT NOT NULL PRIMARY KEY, \
				title VARCHAR(70) NOT NULL, \
				artist_id INTEGER NOT NULL, \
				catalogue VARCHAR(30) NOT NULL, \
				notes VARCHAR(100) \
				);");
		if(res) {
			fprintf(stderr, "Create table 'cd' error: %d %s\n",
					mysql_errno(&my_connection),
					mysql_error(&my_connection));
		} else {
			printf("Table 'cd' created\n");
		}

		res = mysql_query(&my_connection, "CREATE TABLE artist ( \
				id INTEGER AUTO_INCREMENT NOT NULL PRIMARY KEY, \
				name VARCHAR(100) NOT NULL \
				);");
		if(res) {
			fprintf(stderr, "Create table 'artist' error: %d %s\n",
					mysql_errno(&my_connection),
					mysql_error(&my_connection));
		} else {
			printf("Table 'artist' created\n");
		}

		res = mysql_query(&my_connection, "CREATE TABLE track ( \
				cd_id INTEGER NOT NULL, \
				track_id INTEGER NOT NULL, \
				title VARCHAR(70), \
				PRIMARY KEY(cd_id, track_id));");
		if(res) {
			fprintf(stderr, "Create table 'track' error: %d %s\n",
					mysql_errno(&my_connection),
					mysql_error(&my_connection));
		} else {
			printf("Table 'track' created\n");
		}

		(void) mysql_query(&my_connection, "INSERT INTO artist(id,name) VALUES \
				(1, 'Pink Floyd'),(2, 'Genesis'),(3, 'Einaudi'),(4, 'Melanie C')");
		(void) mysql_query(&my_connection, "INSERT INTO cd(id,title,artist_id,"
				"catalogue) VALUES"
				"(1, 'Dark Side of the Moon', 1, 'B000024D4P'),"
				"(2, 'Wish You Were Here', 1, 'B000024D4S'),"
				"(3, 'A Trick of the Tail', 2, 'B000024D4S'),"
				"(4, 'Selling England By the Pound', 2, 'B000024E9M'),"
				"(5, 'I Giorni', 3, 'B000071WEV'),"
				"(6, 'Northern Star', 4, 'B00004YMST')");
		(void) mysql_query(&my_connection, "INSERT INTO track(cd_id, track_id,title) VALUES"
				"(1, 1, 'Speak to me'),"
				"(1, 2, 'Breathe'),"
				"(2, 1, 'Shine on you crazy diamond'),"
				"(2, 2, 'Welcome to the machine'),"
				"(2, 3, 'Have a cigar'),"
				"(2, 4, 'Wish you were here'),"
				"(2, 5, 'Shine on you crazy diamond pt.2'),"
				"(5, 1, 'Melodia Africana (part1)'),"
				"(5, 2, 'I due fiumi'),"
				"(5, 3, 'In un-altra vita'),"
				"(6, 11, 'Closer'),"
				"(6, 12, 'Feel The Sun')");
		
		mysql_close(&my_connection);
	} else {
		fprintf(stderr, "Connection failed\n");
		if(mysql_errno(&my_connection)) {
			fprintf(stderr, "Connection error: %d %s\n",
					mysql_errno(&my_connection),
					mysql_error(&my_connection));
		}
	}

	return EXIT_SUCCESS;
}

