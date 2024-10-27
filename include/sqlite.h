////////////////////////////////////////////////////////////////
//Archivo: sqlite.h                                           //
//Este header contiene funciones importantes para el manejo   //
//de bases de datos sqlite intentando serla sencilla de usar. //
////////////////////////////////////////////////////////////////
#ifndef SQLITE_H
#define SQLITE_H

int _execute_sqlite_ (struct SERVER * server){
    sqlite3 *db;
	char *errMsg = 0;
	char *msgErrorW[BUFFER_SIZE];
	char msgErrorW2[BUFFER_SIZE];
	char msgErrorW3[BUFFER_SIZE];
	int result = sqlite3_open(_rute, &db);
	if (listen(server->server_fd, 3) < 0)
	{
		isAtError = 1;
		strError = "Error con el server";
		return ERROR;
	}
	if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->addrlen, (socklen_t *)&server->addrlen)) < 0)
	{
		isAtError = 1;
		strError = "Error con el server";
		return ERROR;
	}
	if (result != SQLITE_OK){
		isAtError = 1;
		strError = msgErrorW;
		return ERROR;
	}
	result = sqlite3_exec(db, _query_std, 0, 0, &errMsg);
	if (result != SQLITE_OK)
	{
		fprintf(stderr, "cwebs: %s\n", errMsg);
		isAtError = 1;
		strError = msgErrorW;
		sqlite3_free(errMsg);
		return ERROR;
	}
	sqlite3_close(db);
	return OK;
}

int _execute_sqlite (struct SERVER * server){
    sqlite3 *db;
	char *errMsg = 0;
	char *msgErrorW[BUFFER_SIZE];
	char msgErrorW2[BUFFER_SIZE];
	char msgErrorW3[BUFFER_SIZE];
	int result = sqlite3_open(_rute, &db);
	if (listen(server->server_fd, 3) < 0)
	{
		return ERROR;
	}
	if ((server->new_socket = accept(server->server_fd, (struct sockaddr *)&server->addrlen, (socklen_t *)&server->addrlen)) < 0){
		return ERROR;
	}
	if (result != SQLITE_OK){
		fprintf(stderr, "cwebs: %s\n", sqlite3_errmsg(db));
		isAtError = 1;
		strError = msgErrorW;
		return ERROR;
	}
	result = sqlite3_exec(db, _query_std, 0, 0, &errMsg);
	if (result != SQLITE_OK){
		fprintf(stderr, "cwebs: %s\n", errMsg);
		isAtError = 1;
		strError = msgErrorW;
		sqlite3_free(errMsg);
		return ERROR;
	}
	sqlite3_close(db);
	return OK;
}

void sqlite (Sqlite * s){
    s->execute_std = _execute_sqlite;
    s->execute = _execute_sqlite_;
    _rute = s->rute;
    _query = s->query;
    _query_std = s->query_std;
}

#endif
