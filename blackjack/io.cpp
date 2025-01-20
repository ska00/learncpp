#include <cctype>   // for std::toupper
#include <cassert>
#include <iostream>
#include <limits>   // for std::numeric_limits
#include <string>
#include "Io.h"
#include "UserInput.h"

using namespace std::literals::string_literals;
using String = std::string;


template <typename T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}

char max(char x, char y)
{
	return (getValue(x) > getValue(y)) ? x : y;
}

int getValue(char value)
{
	switch (value)
	{
	case 'K':
		return 13;
	case 'Q':
		return 12;
	case 'J':
	case 'A':
		return 11;
	case 'T':
		return 10;
	default:
		std::cerr << "getValue(): invalid argument (" << value << ")";
		std::exit(1);
	}
}


bool isValidSuit(char suit)
{
	switch (suit)
	{
	case 'H':
	case 'D':
	case 'S':
	case 'C':
		return true;
	}
	return false;
}


bool isValidValue(char value)
{
	if (value >= '1' and value <= '9')
		return true;

	switch (value)
	{
	case 'A':
	case 'K':
	case 'Q':
	case 'J':
	case 'T':
		return true;
	}
	return false;
}

bool isValidValue(int value)
{
	if (value >= 1 and value <= 10)
		return true;
	return false;
}


String getCard(char value, char suit)
{
	if (!isValidSuit(suit) or !isValidValue(value))
		return "";

	String card{ " ___ \n" };
	card += "|"s + value + "  |\n"s;
	card += "| "s + suit + " |\n"s;
	card += "|__"s + value + "|\n"s;

	return card;
}

char getSuitFromUser()
{
	while (true)
	{
		char suit{};
		std::cout << "Enter the suit of the card: ";
		std::cin >> suit;

		if (!clearFailedExtraction())
			ignoreLine();

		suit = static_cast<char>(std::toupper(suit));

		if (isValidSuit(suit))
			return suit;

		std::cout << "Invalid suit. Please input (H)earts, (D)iamonds, (C)lovers, or (S)pades.\n";
	}
}

char getValueFromUser()
{
	while (true)
	{
		char value{};
		std::cout << "Enter the value of the card: ";
		std::cin >> value;

		// Check if 10 has been inputted.
		if (value == '1' and std::cin.peek() == '0')
		{
			std::cin.clear();
			ignoreLine();
			return 'T';
		}

		std::cin.clear();
		ignoreLine();

		value = static_cast<char>(std::toupper(value));

		if (isValidValue(value))
			return value;

		std::cout << "Invalid value. Please input (K)ing, (Q)ueen, (J)ack, (A)ce, or a number between 1 - 10.\n";
	}
}

