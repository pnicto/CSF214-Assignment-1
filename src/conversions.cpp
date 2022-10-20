#include "conversions.h"

std::string infixToPrefix(std::string infixFormula) {
  Stack operatorStack{};
  std::string prefixFormula{};

  // Reverse the formula as per the algorithm
  std::reverse(infixFormula.begin(), infixFormula.end());

  // Iterate through the string and add the operators to stack
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

      // When '(' is the character in the reversed infix formula, start  popping
      // the stack and add to the prefix formula until ')'
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

      // If the character is not an operator append it to the prefix string
      default:
        prefixFormula += character;
        break;
    }
  }

  std::reverse(prefixFormula.begin(), prefixFormula.end());
  return prefixFormula;
}
