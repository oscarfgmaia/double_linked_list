#include "list.hpp"
#include <iostream>

// minino buliçoso

void List::createFirstNode(int d) {
  Node *node = new Node{d}; // quando cria aqui os next e prev ja sao nullptr
                            // por conta dos defaults
  head = node;
  tail = node;
  ++size;
};

size_t size = 0;
Node *head = nullptr;
Node *tail = nullptr;
// to lgd, vou inciializar sasporra sempre com valor default..

// xo xo xo, para de buli or
List::~List() {
  auto *node = head;
  while (node) { // while node is not nullptr
    auto *temp = node;
    node = node->next;
    delete temp;
  }
}
// boa, podia ser isso tb kkk
void List::PushBack(int d) {
  if (!tail) {
    createFirstNode(d);
    return;
  }
  Node *node = new Node();
  node->previous = tail;
  node->next = nullptr;
  node->data = d;
  ++size; // ++size ao invés de size++ (sao diferentes)
  tail->next = node;
  tail = node;
};

void List::PushFront(int d) {
  if (!head) {
    createFirstNode(d);
  } else {
    Node *node = new Node();
    node->previous = nullptr;
    node->next = head;
    node->data = d;
    ++size;
    head->previous = node;
    head = node;
  }
};

void List::PrintListForward() {
  Node *node = head;
  while (node) {
    std::cout << node->data << std::endl;
    node = node->next;
  }
};

void List::PrintListBackward() {
  Node *node = tail;
  while (node != nullptr) {
    std::cout << node->data << std::endl;
    node = node->previous;
  }
};

void List::ChangeAllPositions() {
  Node *traveler = head;
  while (traveler != nullptr) {
    traveler->data += 1;
    traveler = traveler->next;
  }
}

void List::PopBack() {
  if (!head) {
    tail = tail->previous;
    tail->next = nullptr;
  }
}
void List::PopFront() {
  if (!head) {
    head = head->next;
    head->previous = nullptr;
  }
}
