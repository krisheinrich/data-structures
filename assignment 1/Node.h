// Node.h

#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>

struct Node {
  int value;
  std::vector<Node*> children;
  void addChild(Node* child);

  Node(int val) {
    value = val
  };
};
