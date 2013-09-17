all: app

app: app_mysql.c app_test.c app_mysql.h
	gcc -o app -I/opt/mysql/include app_mysql.c app_test.c -lmysqlclient -L/opt/mysql/lib
