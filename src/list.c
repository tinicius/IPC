#include "list.h"

void push(List* list, Client* client) {
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  node->client = client;
  node->next = NULL;

  list->size++;

  if (list->head == NULL) {
    list->head = node;
    return;
  }

  ListNode* prev = NULL;
  ListNode* current = list->head;

  while (client->priority >= current->client->priority &&
         current->next != NULL) {
    prev = current;
    current = current->next;
  }

  if (prev == NULL) {
    node->next = list->head;
    list->head = node;
  } else {
    prev->next = node;
    node->next = current;
  }
}

void print(List* list) {
  ListNode* current = list->head;

  while (current != NULL) {
    printf("%s (%d) ", current->client->name, current->client->priority);
    current = current->next;
  }

  printf("\n");
}