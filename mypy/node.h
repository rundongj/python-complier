#pragma once
#include <iostream>

class Literal;

class Node {
public:
  Node() {}
  virtual ~Node() {}
  virtual const Node* eval() = 0;
  virtual void print() const { 
    std::cout << "NODE" << std::endl; 
  }
};

