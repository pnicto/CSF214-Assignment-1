#include "stack.h"

void Stack::resizeArray() {
  tempStackElements = stackElements;
  stackElements = new char[max * 2]{};
  for (int i = 0; i < max; i++) {
    stackElements[i] = tempStackElements[i];
  }
  max = 2 * max;
  delete[] tempStackElements;
}

Stack::Stack(void) {
  stackElements = new char[1]{};
  max = 1;
  top = -1;
}

void Stack::push(char element) {
  if (top >= max - 1) {
    resizeArray();
  }
  top++;
  stackElements[top] = element;
};

char Stack::pop() {
  if (top >= 0) {
    char elementToBeReturned = stackElements[top];
    stackElements[top] = 0;
    top--;
    return elementToBeReturned;
  }
  return 0;
}

void Stack::printStack() {
  for (int i = 0; i < max; i++) {
    std::cout << stackElements[i] << std::endl;
  }
}
