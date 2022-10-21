/*!
 * @file conversions.h
 * @brief Header file for conversions
 * @version 0.1
 * @date 21-10-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <algorithm>
#include <string>

#include "conversions.h"
#include "stack.h"

/*!
 * @brief Takes the infix formula given and converts into prefix formula
 * @param infixFormula
 * @return std::string prefixFormula
 */
std::string infixToPrefix(std::string infixFormula);
