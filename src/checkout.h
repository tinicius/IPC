#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "list.h"

typedef struct Checkout {
  int id;
  bool open;
  List* clients;
} Checkout;

#endif