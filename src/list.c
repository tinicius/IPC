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

  while (client->priority >= current->client->priority && current != NULL) {
    prev = current;

    if (current->next == NULL) {
      current = NULL;
      break;
    }

    current = current->next;
  }

  if (prev == NULL) {
    if (client->priority < current->client->priority) {
      node->next = current;
      list->head = node;
      return;
    }

    current->next = node;
    return;
  }

  prev->next = node;
  node->next = current;
}

Client* pop(List* list) {
  if (list->head == NULL) {
    return NULL;
  }

  list->size--;

  ListNode* node = list->head;
  list->head = list->head->next;

  return node->client;
}

void print_list(List* list) {
  ListNode* current = list->head;

  while (current != NULL) {
    print_client(current->client);
    printf("\n");
    current = current->next;
  }

}