#include "client.h"

Client* input_client() {
  Client* client = (Client*)malloc(sizeof(Client));

  client->name = (char*)malloc(100 * sizeof(char));

  fgetc(stdin);
  printf("Digite o nome do cliente: \n");
  fgets(client->name, 100, stdin);
  client->name[strcspn(client->name, "\n")] = 0;

  printf("Digite o CPF do cliente: \n");
  scanf("%ld", &client->cpf);

  if (client->cpf < 0) {
    printf("CPF inválido\n");
    return NULL;
  }

  printf("Digite a prioridade do cliente: \n");
  scanf("%d", &client->priority);

  if (client->priority < 1 || client->priority > 3) {
    printf("Prioridade inválida\n");
    return NULL;
  }

  printf("Digite a quantidade de itens do cliente: \n");
  scanf("%d", &client->items);

  if (client->items < 0) {
    printf("Quantidade de itens inválida\n");
    return NULL;
  }

  return client;
}

void print_client(Client* client) {
  printf("Nome: %s\n", client->name);
  printf("CPF: %ld\n", client->cpf);
  printf("Prioridade: %d\n", client->priority);
  printf("Itens: %d\n", client->items);
}