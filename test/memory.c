#include "../include/cweb.h"

int main (){
  printf("Server: %ldBytes\n",sizeof(server));
  printf("SMTP: %ldBytes\n",sizeof(SMTP));
  printf("Connect_api: %ldBytes\n",sizeof(SMTP));
  printf("ftp: %ldBytes\n",sizeof(ftp));
  printf("CDO: %ldBytes\n",sizeof(CDO));
  printf("Files: %ldBytes\n",sizeof(files));
  return 0;
}
