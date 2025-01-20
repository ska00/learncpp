#pragma once

#include <cctype>   // for std::toupper
#include <cassert>
#include <iostream>
#include <limits>   // for std::numeric_limits
#include <string>
#include "UserInput.h"


bool isValidSuit(char suit);
bool isValidValue(char value);
bool isValidValue(int value);
char getSuitFromUser();
char getValueFromUser();
char max(char x, char y);
auto getCard(char value, char suit) -> std::string;
int getValue(char value);


template <typename T>
bool isValidValue(T value) = delete;
template <typename T>
bool isValidSuit(T suit) = delete;
