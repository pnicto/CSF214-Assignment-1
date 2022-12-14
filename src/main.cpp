/*!
 * @file main.cpp
 * @brief Source file for main
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "../include/main.h"

/*!
 * @brief Where the tasks are run
 * @details Takes user input for infix formula and calls respective functions
 * for tasks
 *
 * @return int 0 if success
 */
int main() {
  std::string infixFormula;

  // Take user input for infix formula
  std::cout << "Enter a well parenthesized propositional logic formula:"
            << '\n';
  std::cout << "Example (~p) ,(p>q), ((p+q)>(~r))" << '\n';
  std::cin >> infixFormula;

  // Task 1
  std::string prefixFormula = infixToPrefix(infixFormula);
  std::cout << "Prefix Formula: " << prefixFormula << '\n';

  // Task 2
  ParseTree* binaryTree = prefixToParseTree(prefixFormula);
  binaryTree->printParseTree("", binaryTree, true);

  // Task 3
  std::string infixExpression = binaryTree->getInfixExpression(binaryTree);
  std::cout << "Infix Expression:" << infixExpression << '\n';

  // Task 4
  long long int height = binaryTree->getHeight(binaryTree);
  std::cout << "Height:" << height << '\n';

  // Task 5
  bool truthValue = evaluateTreeTruthValue(binaryTree);
  std::cout << "Truth value of the binary expression is: "
            << ((truthValue) ? "True" : "False") << '\n';

  delete binaryTree;

  return 0;
}
