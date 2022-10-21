/*!
 * @file conversions.cpp
 * @brief Source file for conversions
 * @version 0.1
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/conversions.h"

std::string infixToPrefix(std::string infixFormula) {
  /*!
   * @details Create operator stack
   *
   */
  Stack operatorStack{};
  /*!
   * @details Create empty prefix formula
   *
   */
  std::string prefixFormula{};

  /*!
   * @details Reverse the formula as per the algorithm
   *
   */
  std::reverse(infixFormula.begin(), infixFormula.end());

  /*!
   * @details Iterate through the string and add the operators to stack
   *
   */
  for (char character : infixFormula) {
    switch (character) {
      case '~':
        operatorStack.push(character);
        break;

      case '+':
        operatorStack.push(character);
        break;

      case '*':
        operatorStack.push(character);
        break;

      case '>':
        operatorStack.push(character);
        break;

        /*!
         * @details When '(' is the character in the reversed infix formula,
         * start popping the stack and add to the prefix formula until ')' else
         * add the character to operator stack
         *
         */
      case '(':
        while (1) {
          char operatorToBeAdded = operatorStack.pop();
          if (operatorToBeAdded == ')')
            break;
          else
            prefixFormula += operatorToBeAdded;
        }
        break;

      case ')':
        operatorStack.push(character);
        break;

      /*!
       * @details If the character is not an operator append it to the prefix
       * string
       *
       */
      default:
        prefixFormula += character;
        break;
    }
  }

  /*!
   * @details Reverse the prefix formula string created so far to get the
   * desired result
   *
   */
  std::reverse(prefixFormula.begin(), prefixFormula.end());

  return prefixFormula;
}
