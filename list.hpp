#pragma once

class Node {
public:
  int data;
  Node *next = nullptr; // valores default
  Node *previous = nullptr;
};

class List {
private:
  void createFirstNode(int d);
    int size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
public:
  void PushBack(int d);
  void PushFront(int d);
  void PrintListForward();
  void PrintListBackward();
  void ChangeAllPositions();
  void PopBack();
  void PopFront();
  ~List();
};