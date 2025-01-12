#include "checkout.h"

void open_checkout(Checkout* checkout) {
  if (checkout->open) {
    printf("Caixa já está aberto\n");
    return;
  }

  checkout->open = true;
}

void close_checkout(Checkout* checkout, Checkout* next_checkout) {
  if (!checkout->open) {
    printf("Caixa já está fechado\n");
    return;
  }

  Client* client = pop(checkout->clients);

  while (client != NULL) {
    push(next_checkout->clients, client);
    client = pop(checkout->clients);
  }

  checkout->open = false;
}