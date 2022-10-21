#include "../include/main.h"

#include "../include/conversions.h"
#include "../include/tree.h"

int main() {
  std::string infixFormula;

  // Take user input for infix formula
  std::cin >> infixFormula;

  // Task 1
  std::string prefixFormula = infixToPrefix(infixFormula);
  std::cout << "Prefix Formula: " << prefixFormula << '\n';

  // Task 2
  ParseTree* binaryTree = prefixToParseTree(prefixFormula);
  printBT("", binaryTree, true);

  // Task 3
  std::string infixExpression = parseTreeToInfix(binaryTree);
  std::cout << "Infix Expression:" << infixExpression << '\n';

  // Task 4
  int height = treeHeight(binaryTree);
  std::cout << "Height:" << height << '\n';

  // Task 5
  bool truthValue = evaluateTreeTruthValue(binaryTree);
  std::cout << "Truth value of the binary expression is: "
            << ((truthValue) ? "True" : "False") << '\n';

  delete binaryTree;

  return 0;
}
