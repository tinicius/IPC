#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "client.h"

typedef struct ListNode ListNode;

typedef struct ListNode {
  Client* client;
  ListNode* next;
} ListNode;

typedef struct List {
  int size;
  ListNode* head;
} List;

void push(List* list, Client* client);

void print(List* list);

#endif