#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkout.h"
#include "client.h"

#define CHECKOUT_COUNT 5

Checkout* checkouts = NULL;

void register_client() {
  Client* new_client = input_client();

  int checkout_id;
  printf("Digite o id do caixa: \n");
  scanf("%d", &checkout_id);

  printf("%d\n", checkout_id);

  if (checkouts[checkout_id].clients == NULL) {
    printf("Caixa fechado\n");
    return;
  }

  push(checkouts[checkout_id].clients, new_client);
}

void print_checkouts() {
  for (int i = 0; i < CHECKOUT_COUNT; i++) {
    printf("Caixa %d: ", checkouts[i].id);

    if (checkouts[i].open) {
      printf("Aberto\n");
    } else {
      printf("Fechado\n");
    }

    if (checkouts[i].clients->size > 0) {
      printf("Clientes: ");
      print(checkouts[i].clients);
    }
  }
}

int main() {
  int op;

  checkouts = (Checkout*)malloc(CHECKOUT_COUNT * sizeof(Checkout));

  for (int i = 0; i < CHECKOUT_COUNT; i++) {
    checkouts[i].id = i;
    checkouts[i].open = true;

    checkouts[i].clients = (List*)malloc(sizeof(List));
    checkouts[i].clients->head = NULL;
    checkouts[i].clients->size = 0;
  }

  do {
    printf("[0] - Sair\n");
    printf("[1] - Cadastrar um cliente\n");
    printf("[2] - Atender um cliente\n");
    printf("[3] - Abrir ou fechar um caixa\n");
    printf("[4] - Imprimir a lista de clientes em espera\n");
    printf("[5] - Imprimir o status dos caixas\n");

    printf("Digite uma opção: \n");
    scanf("%d", &op);

    switch (op) {
      case 0:
        printf("Saindo...\n");
        break;
      case 1:
        register_client();
        break;
      case 2:
        printf("Atender um cliente\n");
        break;
      case 3:
        printf("Abrir ou fechar um caixa\n");
        break;
      case 4:
        print_checkouts();
        break;
      case 5:
        printf("Imprimir o status dos caixas\n");
        break;
      default:
        printf("Opção inválida\n");
    }
  } while (op != 0);

  return 0;
}