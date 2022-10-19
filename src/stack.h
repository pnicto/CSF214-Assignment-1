#pragma once

#include <iostream>

class Stack {
 private:
  char* stackElements;
  char* tempStackElements;
  int top, max;

  void resizeArray();

 public:
  Stack();
  ~Stack();

  void push(char element);

  char pop();

  void printStack();
};
