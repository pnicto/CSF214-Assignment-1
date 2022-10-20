#include "main.h"

#include "conversions.h"
#include "tree.h"

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

  // Task 4
  int height = treeHeight(*binaryTree);
  std::cout << "Height:" << height << '\n';

  delete binaryTree;
  return 0;
}
