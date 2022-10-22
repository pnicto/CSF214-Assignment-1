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
  if (*formulaStartPtr == formulaEndPtr) return nullptr;

  ParseTree *node = new ParseTree{**formulaStartPtr};

  switch (*((*formulaStartPtr)++)) {
    case '+':
    case '*':
    case '>':
      node->setLeftNode(createParseTree(formulaStartPtr, formulaEndPtr));
      node->setRightNode(createParseTree(formulaStartPtr, formulaEndPtr));
      break;
    case '~':
      node->setRightNode(createParseTree(formulaStartPtr, formulaEndPtr));
      break;
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
    case '+':
      return (getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) ||
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    case '*':
      return (getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) &&
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    case '>':
      return (!getNodeTruthValue(nodePtr->getLeftNode(nodePtr), hashPtr) ||
              getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    case '~':
      return (!getNodeTruthValue(nodePtr->getRightNode(nodePtr), hashPtr));
      break;
    default:
      if ((*hashPtr).find(nodePtr->getValue()) != (*hashPtr).end())
        return (*hashPtr)[nodePtr->getValue()];
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
