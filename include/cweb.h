////////////////////////////////////////////////////////////////
//Archivo: cweb.h                                             //
//Este header contine la incluciones de la librerias          //
//necesarias incluyendo las creadas propias.                  //
////////////////////////////////////////////////////////////////
#ifndef CWEB_H
#define CWEB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <netdb.h>
#include <sys/stat.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <sqlite3.h>
#include <curl/curl.h>

#include "var.h"
#include "server.h"
#include "html.h"
#include "archives.h"
#include "http.h"
#include "sqlite.h"
#include "smtp.h"
#include "cdo.h"
#include "json.h"

#endif
