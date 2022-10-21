#include "../include/tree.h"

// Constructor for Parse Tree
ParseTree::ParseTree(char character) {
  value = character;
  leftNode = nullptr;
  rightNode = nullptr;
}

// Destructor for Parse Tree
ParseTree::~ParseTree() {
  if (leftNode != nullptr) {
    delete leftNode;
  }
  if (rightNode != nullptr) {
    delete rightNode;
  }
}

// Getters for Parse Tree
char ParseTree::getValue() { return value; }
ParseTree *ParseTree::getLeftNode(ParseTree *node) { return node->leftNode; }
ParseTree *ParseTree::getRightNode(ParseTree *node) { return node->rightNode; }
int getHeight(ParseTree *node) {
  if (node == nullptr) return 0;
  return 1 + std::max(getHeight(node->getLeftNode(node)),
                      getHeight(node->getRightNode(node)));
}

// Setters for Parse Tree
void ParseTree::setLeftNode(ParseTree *node) { leftNode = node; }
void ParseTree::setRightNode(ParseTree *node) { rightNode = node; }

// For use in prefixToParseTree()
ParseTree *createTree(std::string::iterator *valuePtr,
                      std::string::iterator endPtr) {
  if (*valuePtr == endPtr) return nullptr;
  ParseTree *node = new ParseTree{**valuePtr};
  switch (*((*valuePtr)++)) {
    case '+':
    case '*':
    case '>':
      node->setLeftNode(createTree(valuePtr, endPtr));
      node->setRightNode(createTree(valuePtr, endPtr));
      break;
    case '~':
      node->setRightNode(createTree(valuePtr, endPtr));
      break;
    default:
      break;
  }
  return node;
}

// Task 2 solution
ParseTree *prefixToParseTree(std::string prefixFormula) {
  std::string::iterator characterPtr = prefixFormula.begin();
  std::string::iterator endPtr = prefixFormula.end();
  ParseTree *tree = createTree(&characterPtr, endPtr);
  return tree;
}

// Task 4 solution
int treeHeight(ParseTree *binaryTree) {
  int height = getHeight(binaryTree);
  return height;
}

void printBT(const std::string &prefix, ParseTree *node, bool isLeft) {
  if (node != nullptr) {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << node->getValue() << std::endl;
    printBT(prefix + (isLeft ? "│   " : "    "), node->getLeftNode(node), true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->getRightNode(node),
            false);
  }
}

// For use in parseTreeToInfix()
void inOrderTraversal(ParseTree *nodePtr, std::string *infixFormulaPtr) {
  if (nodePtr->getLeftNode(nodePtr) != nullptr)
    inOrderTraversal(nodePtr->getLeftNode(nodePtr), infixFormulaPtr);
  infixFormulaPtr->push_back(nodePtr->getValue());
  if (nodePtr->getRightNode(nodePtr) != nullptr)
    inOrderTraversal(nodePtr->getRightNode(nodePtr), infixFormulaPtr);
}

// Task 3 solution
std::string parseTreeToInfix(ParseTree *nodePtr) {
  std::string infixFormula = "";
  inOrderTraversal(nodePtr, &infixFormula);
  return infixFormula;
}

// For use in evaluateTreeTruthValue()
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

// Task 5 solution
bool evaluateTreeTruthValue(ParseTree *nodePtr) {
  std::unordered_map<char, bool> atomTruthVals;
  return getNodeTruthValue(nodePtr, &atomTruthVals);
}
