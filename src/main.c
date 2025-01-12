#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "checkout.h"
#include "client.h"

#define CHECKOUT_COUNT 5

Checkout* checkouts = NULL;

void register_client() {
  Client* new_client = input_client();

  // TODO - Validate checkout_id

  int checkout_id;
  printf("Digite o id do caixa: \n");
  scanf("%d", &checkout_id);

  if (checkouts[checkout_id].clients == NULL) {
    printf("Caixa fechado\n");
    return;
  }

  push(checkouts[checkout_id].clients, new_client);
}

void serve_client() {
  // TODO - Validate checkout_id

  int checkout_id;
  printf("Digite o id do caixa: \n");
  scanf("%d", &checkout_id);

  if (!checkouts[checkout_id].open) {
    printf("Caixa fechado\n");
    return;
  }

  if (checkouts[checkout_id].clients->size == 0) {
    printf("Nenhum cliente na fila\n");
    return;
  }

  Client* served_client = pop(checkouts[checkout_id].clients);

  print_client(served_client);
}

void open_or_close_checkout() {
  int checkout_id;
  printf("Digite o id do caixa: \n");
  scanf("%d", &checkout_id);

  int option;
  printf("Abrir (1) ou fechar (0) o caixa? \n");
  scanf("%d", &option);

  Checkout* next_checkout = NULL;

  for (int i = 0; i < CHECKOUT_COUNT; i++) {
    if (checkouts[i].open && i != checkout_id) {
      next_checkout = &checkouts[i];
      break;
    }
  }

  if (next_checkout == NULL && checkouts[checkout_id].clients->size > 0) {
    printf(
        "Você não pode fechar este caixa pois ele tem clientes e não há outro "
        "caixa aberto!\n");
    return;
  }

  if (option) {
    open_checkout(&checkouts[checkout_id]);
  } else {
    close_checkout(&checkouts[checkout_id], next_checkout);
  }
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
      print_list(checkouts[i].clients);
    }
  }
}

void print_checkout_status() {
  for (int i = 0; i < CHECKOUT_COUNT; i++) {
    if (checkouts[i].open) {
      printf("Caixa %d (Aberto): %d\n", checkouts[i].id,
             checkouts[i].clients->size);
    } else {
      printf("Caixa %d (Fechado)\n", checkouts[i].id);
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
    printf("\n");

    printf("[0] - Sair\n");
    printf("[1] - Cadastrar um cliente\n");
    printf("[2] - Atender um cliente\n");
    printf("[3] - Abrir ou fechar um caixa\n");
    printf("[4] - Imprimir a lista de clientes em espera\n");
    printf("[5] - Imprimir o status dos caixas\n");

    printf("\n");

    printf("Digite uma opção: \n");
    scanf("%d", &op);

    printf("\n");

    switch (op) {
      case 0:
        printf("Saindo...\n");
        break;
      case 1:
        register_client();
        break;
      case 2:
        serve_client();
        break;
      case 3:
        open_or_close_checkout();
        break;
      case 4:
        print_checkouts();
        break;
      case 5:
        print_checkout_status();
        break;
      default:
        printf("Opção inválida\n");
    }
  } while (op != 0);

  return 0;
}