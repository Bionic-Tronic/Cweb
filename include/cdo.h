#ifndef CDO_H
#define CDO_H

int _exec (struct CDO * cdo) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc;
    char result[MAX_VARS];
    concatplus(result,"%s.db",cdo->name_s);
   rc = sqlite3_open(result, &db);
   if (rc != SQLITE_OK) {
      if(cdo->errors == true){
          fprintf(stderr, "cweb: %s\n", sqlite3_errmsg(db));
          cdo->is_error = ERROR;
          return ERROR;
      } else {
          cdo->is_error = ERROR;
          return ERROR;
      }
   }
   rc = sqlite3_exec(db, cdo->query_s, 0, 0, &err_msg);
   if (rc != SQLITE_OK ) {
      if(cdo->errors == true){
          fprintf(stderr, "cweb: %s\n", err_msg);
          sqlite3_free(err_msg);
          sqlite3_close(db);
          cdo->is_error = ERROR;
          return ERROR;
      } else {
          sqlite3_free(err_msg);
          sqlite3_close(db);
          cdo->is_error = ERROR;
          return ERROR;
      }
   }
   sqlite3_close(db);
   cdo->is_error = OK;
   return OK;
}

int _insert (struct CDO * cdo, const String datos[]){
    int rc,o = 1;
    char result[MAX_VARS];
    concatplus(result,"%s.db",cdo->name_s);
    rc = sqlite3_open(result, &cdo->db);
    if (rc != SQLITE_OK) {
        if(cdo->errors == true){
            fprintf(stderr, "cweb: %s\n", sqlite3_errmsg(cdo->db));
            cdo->is_error = ERROR;
            return ERROR;
        } else {
            cdo->is_error = ERROR;
            return ERROR;
        }
    }
    
    rc = sqlite3_prepare_v2(cdo->db, cdo->query_s, -1, &cdo->stmt, EMPTY);
    if (rc != SQLITE_OK) {
        if(cdo->errors == true){
            fprintf(stderr, "cweb: %s\n", sqlite3_errmsg(cdo->db));
            cdo->is_error = ERROR;
            return ERROR;
        } else {
            cdo->is_error = ERROR;
            return ERROR;
        }
    }
    
    for(int i = 0; i < cdo->length_arr; i++, o++){
        sqlite3_bind_text(cdo->stmt, o, datos[i], -1, SQLITE_STATIC);
    }
    
    rc = sqlite3_step(&cdo->stmt);
    if (rc != SQLITE_OK) {
        if(cdo->errors == true){
            fprintf(stderr, "cweb: %s\n", sqlite3_errmsg(cdo->db));
            cdo->is_error = ERROR;
            return ERROR;
        } else {
            cdo->is_error = ERROR;
            return ERROR;
        }
    }
    sqlite3_finalize(cdo->stmt);
    sqlite3_close(cdo->db);
    cdo->is_error = OK;
    return OK;
}

int _select_ (struct CDO * cdo, int (*callback)()){
    char *err_msg = 0;
    int rc;
    char result[MAX_VARS];
    concatplus(result,"%s.db",cdo->name_s);
    rc = sqlite3_open(result, &cdo->db);
    if (rc != SQLITE_OK) {
        if(cdo->errors == true){
            fprintf(stderr, "cweb: %s\n", sqlite3_errmsg(cdo->db));
            cdo->is_error = ERROR;
            return ERROR;
        } else {
            cdo->is_error = ERROR;
            return ERROR;
        }
    }
    rc = sqlite3_exec(cdo->db, cdo->query_s, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        if(cdo->errors == true){
            fprintf(stderr, "cweb: %s\n", err_msg);
            sqlite3_free(err_msg);
            cdo->is_error = ERROR;
            return ERROR;
        } else {
            sqlite3_free(err_msg);
            cdo->is_error = ERROR;
            return ERROR;
        }
    }
    sqlite3_close(cdo->db);
    cdo->is_error = OK;
    return OK;
}

void cdo (struct CDO * cdo) {
    cdo->is_error = OK;
    cdo->exec = _exec;
    cdo->insert_update = _insert;
    cdo->select = _select_;
}

#endif
