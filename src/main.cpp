#include "main.h"

#include "conversions.h"

int main() {
  std::string infixFormula;

  // Take user input for infix formula
  std::cin >> infixFormula;

  // Task 1
  std::string prefixFormula = infixToPrefix(infixFormula);
  std::cout << "Prefix Formula: " << prefixFormula << '\n';

  return 0;
}
