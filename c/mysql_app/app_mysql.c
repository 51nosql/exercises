#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mysql.h"
#include "app_mysql.h"

static MYSQL my_connection;
static int dbconnected = 0;

static int get_artist_id(char *artist);

int database_start(char *name, char *pwd) {
	if(dbconnected) return 1;

	mysql_init(&my_connection);
	if(!mysql_real_connect(&my_connection, "localhost", name, pwd, "test", 0, NULL, 0)) {
		fprintf(stderr, "Database connection failure: %d, %s\n",
				mysql_errno(&my_connection), mysql_error(&my_connection));
		return 0;
	}
	dbconnected = 1;
	return 1;
}

void database_end()
{
	if(dbconnected) mysql_close(&my_connection);
	dbconnected = 0;
}

int add_cd(char *artist, char *title, char *catalogue, int *cd_id)
{
	MYSQL_RES *res_ptr;
	MYSQL_ROW mysqlrow;

	int res;
	char is[250];
	char es[250];
	int artist = -1;
	int new_cd_id = -1;

	if(!dbconnected) return 0;

	artist_id = get_artist_id(artist);
	mysql_escape_string(es, title, strlen(title));
	sprintf(is, "INSERT INTO cd(title, artist_id, catalogue) \
			VALUES('%s', %d, '%s')", es, artist_id, catalogue);
	res = mysql_query(&my_connection, is);
	if(res) {
		fprintf(stderr, "Insert error %d: %s\n",
				mysql_errno(&my_connection), mysql_error(&my_connection));
		return 0;
	}

	res = mysql_query(&my_connection, "SELECT LAST_INSERT_ID()");
	if(res) {
		printf("SELECT error: %s\n", mysql_error(&my_connection));
		return 0;
	} else {
		res_ptr = mysql_use_result(&my_connection);
		if(res_ptr) {
			if((mysqlrow = mysql_fetch_row(res_ptr))) {
				sscanf(mysqlrow[0], "%d", &new_cd_id);
			}
			mysql_free_result(res_ptr);
		}
		*cd_id = new_cd_id;
		if(new_cd_id != -1) return 1;
		return 0;
	}
}

/* Find or create an artist_id for the given string */
static int get_artist_id(char *artist)
{
	MYSQL_RES *res_ptr;
	MYSQL_ROW mysqlrow;

	int res;
	char qs[250];
	char is[250];
	char es[250];
	int artist_id = -1;

	/* Does it already exist ? */
	mysql_escape_string(es, artist, strlen(artist));
	sprintf(qs, "SELECT id FROM artist WHERE name = '%s'", es);

	res = mysql_query(&my_connection, qs);
	if(res) {
		fprintf(stderr, "SELECT error: %s\n", mysql_error(&my_connection));
	} else {
		res_ptr = mysql_store_result(&my_connection);
		if(res_ptr) {
			if(mysql_num_rows(res_ptr) > 0) {
				sscanf(mysqlrow[0], "%d", &artist_id);
			}
			mysql_free_result(res_ptr);
		}
	}
	if(artist_id != -1) return artist_id;

	sprintf(is, "INSERT INTO artist(name) VALUES('%s')", es);
	res = mysql_query(&my_connection, is);
	if(res) {
		fprintf(stderr, "Insert error %d: %s\n",
				mysql_errno(&my_connection), mysql_error(&my_connection));
		return 0;
	}

	res = mysql_query(&my_connection, "SELECT LAST_INSERT_ID()");
	if(res) {
		printf("SELECT error: %s\n", mysql_error(&my_connection));
		return 0;
	} else {
		res_ptr = mysql_use_result(&my_connection);
		if(res_ptr) {
			if((mysqlrow = mysql_fetch_row(res_ptr))) {
				sscanf(mysqlrow[0], "%d", &artist_id);
			}
			mysql_free_result(res_ptr);
		}
	}
	return artist_id;
}

int add_tracks(struct current_tracks_st *tracks)
{
	int res;
	char is[250];
	char es[250];
	int i;

	if(!dbconnected) return 0;

	i = 0;
	while(tracks->track[i][0]) {
		mysql_escape_string(es, tracks->track[i], strlen(tracks->track[i]));
		sprintf(is, "INSERT INTO track(cd_id, track_id, title) \
				VALUES(%d, %d, '%s'", tracks->cd_id, i + 1, es);
		res = mysql_query(&my_connection, is);
		if(res) {
			fprintf(stderr, "Insert error %d: %s\n",
					mysql_errno(&my_connection), mysql_error(&my_connection));
			return 0;
		}
		i++;
	}
	return 1;
}

