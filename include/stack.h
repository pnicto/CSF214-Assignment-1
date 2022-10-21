/*!
 * @file stack.h
 * @brief Header file for stack
 * @version 0.1
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>

/*!
 * @brief Class for stack to store operators
 *
 */
class Stack {
 private:
  /*!
   * @brief Elements of the stack
   *
   */
  char* stackElements;

  /*!
   * @brief Temporary variable to store the elements of the stack before
   * resizing the stack
   *
   */
  char* tempStackElements;

  /*!
   * @brief Maximum elements the stack can store
   *
   */
  int max{};

  /*!
   * @brief Index
   *
   */
  int top{};

  /*!
   * @brief Resizes the stack array dynamically
   *
   */
  void resizeArray();

 public:
  /*!
   * @brief Construct a new Stack object
   *
   */
  Stack();

  /*!
   * @brief Destroy the Stack object
   *
   */
  ~Stack();

  /*!
   * @brief Adds the element to the stack
   *
   * @param element
   */
  void push(char element);

  /*!
   * @brief Returns the element at the top from stack
   *
   * @return char
   */
  char pop();

  /*!
   * @brief Prints stack
   *
   */
  void printStack();
};
