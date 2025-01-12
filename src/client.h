#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Client {
  char *name;
  long cpf;
  int priority;
  int items;
} Client;

Client* input_client();

#endif