#include "list.hpp"
#include <iostream>

int main() {
  List list;
  list.PushFront(5);
  list.PushFront(7);
  list.PrintListForward();
  return 0;
}