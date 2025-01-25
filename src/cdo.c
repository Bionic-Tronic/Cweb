#include "../include/cweb.h"

int exec (CDO * cdo) {
    char *err_msg = 0;
    int rc;
    char result[1024];
    snprintf(result, 1024, "%s.sqlite", cdo->name_s);
   rc = sqlite3_open(result, &cdo->db);
   if (rc != SQLITE_OK) {
      fprintf(stderr, "exec(): %s\n", sqlite3_errmsg(cdo->db));
      return DB_ERROR;
   }
   rc = sqlite3_exec(cdo->db, cdo->query_s, 0, 0, &err_msg);
   if (rc != SQLITE_OK ) {
      fprintf(stderr, "exec(): %s\n", err_msg);
      sqlite3_free(err_msg);
      sqlite3_close(cdo->db);
      return ERROR;
   }
   sqlite3_close(cdo->db);
   cdo->is_error = OK;
   return OK;
}

int exec_insert (CDO * cdo, const String datos[]){
    int rc,o = 1;
    char result[1024];
    snprintf(result, 1024, "%s.sqlite", cdo->name_s);
    rc = sqlite3_open(result, &cdo->db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "exec_insert(): %s\n", sqlite3_errmsg(cdo->db));
        return DB_ERROR;
    }
    rc = sqlite3_prepare_v2(cdo->db, cdo->query_s, -1, &cdo->stmt, EMPTY);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "exec_insert(): %s\n", sqlite3_errmsg(cdo->db));
        return DB_ERROR;
    }
    for(int i = 0; i < cdo->length_arr; i++, o++){
        sqlite3_bind_text(cdo->stmt, o, datos[i], -1, SQLITE_STATIC);
    }
    rc = sqlite3_step(cdo->stmt);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "exec_insert(): %s\n", sqlite3_errmsg(cdo->db));
        return DB_ERROR;
    }
    sqlite3_finalize(cdo->stmt);
    sqlite3_close(cdo->db);
    return DB_OK;
}

int exec_select(CDO * cdo, int (*callback)()){
    char *err_msg = 0;
    int rc;
    char result[1024];
    snprintf(result, 1024, "%s.sqlite", cdo->name_s);
    rc = sqlite3_open(result, &cdo->db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "exec_select(): %s\n", sqlite3_errmsg(cdo->db));
        return DB_ERROR;
    }
    rc = sqlite3_exec(cdo->db, cdo->query_s, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "exec_select(): %s\n", err_msg);
        sqlite3_free(err_msg);
        return DB_ERROR;
    }
    sqlite3_close(cdo->db);
    return DB_OK;
}