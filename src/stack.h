#pragma once
#include <iostream>

class Stack {
 private:
  char* stackElements;
  char* tempStackElements;
  int top, max;

  void resizeArray();

 public:
  Stack(void);

  void push(char element);

  char pop();

  void printStack();
};