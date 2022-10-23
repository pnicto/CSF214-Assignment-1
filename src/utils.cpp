/*!
 * @file utils.cpp
 * @brief Source file for utility functions
 * @date 22-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/utils.h"

/*!
 * @brief Takes in start and end pointers and generates a binary
 * tree recursively
 * @details For binary operators generates tree normally but for unary operator
 * like "~" right node is created
 * @param formulaStartPtr
 * @param formulaEndPtr
 * @return ParseTree*
 */
ParseTree *createParseTree(std::string::iterator *formulaStartPtr,
                           std::string::iterator formulaEndPtr) {
  // Make previous node a leaf if the end of the prefix expression has been
  // reached
  if (*formulaStartPtr == formulaEndPtr) return nullptr;

  ParseTree *node = new ParseTree{**formulaStartPtr};

  // If the character is one of the three binary operators, they each have
  // non-null left and right nodes
  switch (*((*formulaStartPtr)++)) {
    case '+':
    case '*':
    case '>':
      node->setLeftNode(createParseTree(formulaStartPtr, formulaEndPtr));
      node->setRightNode(createParseTree(formulaStartPtr, formulaEndPtr));
      break;
      // In case of the negation operator, the left node remains null, and only
      // the right one has a value
    case '~':
      node->setRightNode(createParseTree(formulaStartPtr, formulaEndPtr));
      break;
      // All other characters are assumed to be propositional atoms, and both
      // the left and right nodes are null so they form leaves
    default:
      break;
  }
  return node;
}

// Task 5

/*!
 * @brief Gets the truth value of a given node
 *
 * @param nodePtr
 * @param hashPtr
 * @return true
 * @return false
 */
bool getNodeTruthValue(ParseTree *nodePtr,
                       std::unordered_map<char, bool> *hashPtr) {
  switch (nodePtr->getValue()) {
    // For the disjunction operator, returns 'true' if at least one of
    // its operands return 'true'
    case '+':
      return (getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) ||
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
      // For the conjunction operator, returns 'true' only if both of its
      // operands return 'true'
    case '*':
      return (getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) &&
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
      // For the implication operator, returns 'true' if either the hypothesis
      // is 'false' or the conclusion is 'true'
    case '>':
      return (!getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) ||
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
      // For the negation operator, returns the opposite of the operand's truth
      // value
    case '~':
      return (!getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    default:
      // If truth value of propositional atom has already been entered by the
      // user (it exists in the hashmap), it is used
      if ((*hashPtr).find(nodePtr->getValue()) != (*hashPtr).end())
        return (*hashPtr)[nodePtr->getValue()];
      // If truth value of propositional atom is unknown, the user is prompted
      // to enter it, and the value is stored in a hashmap for future use
      else {
        char truthVal{};
        std::cout
            << "Please enter the truth value (T/F) for propositional atom '"
            << nodePtr->getValue() << "': ";
        std::cin >> truthVal;
        if (truthVal == 'T' || truthVal == 't') {
          (*hashPtr)[nodePtr->getValue()] = true;
          return true;
        } else if (truthVal == 'F' || truthVal == 'f') {
          (*hashPtr)[nodePtr->getValue()] = false;
          return false;
        } else {
          std::cout << "\nUnknown value entered, assumed to be False\n";
          return false;
        }
      }
      break;
  }
}

/*!
 * @brief Evaluates the truth value of a given parse tree
 * @details Uses #getNodeTruthValue to evaluate the truth value of a given parse
 * tree
 * @param nodePtr
 * @return true
 * @return false
 */
bool evaluateTreeTruthValue(ParseTree *nodePtr) {
  std::unordered_map<char, bool> atomTruthVals;
  return getNodeTruthValue(nodePtr, &atomTruthVals);
}
