/*!
 * @file utils.h
 * @brief Utility functions for tasks
 * @date 22-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <string>

#include "parsetree.h"

// Task 2
ParseTree *createParseTree(std::string::iterator *formulaStartPtr,
                           std::string::iterator formulaEndPtr);

// Task 5
bool getNodeTruthValue(ParseTree *nodePtr,
                       std::unordered_map<char, bool> *hashPtr);
bool evaluateTreeTruthValue(ParseTree *nodePtr);