/*!
 * @file conversions.h
 * @brief Header file for conversions
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <algorithm>
#include <string>

#include "conversions.h"
#include "parsetree.h"
#include "stack.h"
#include "utils.h"

std::string infixToPrefix(std::string infixFormula);

// Task 2
ParseTree *prefixToParseTree(std::string prefixFormula);
