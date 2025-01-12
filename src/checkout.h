#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "list.h"

typedef struct Checkout {
  int id;
  bool open;
  List* clients;
} Checkout;

void open_checkout(Checkout* checkout);
void close_checkout(Checkout* checkout, Checkout* next_checkout);

#endif