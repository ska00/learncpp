#include <cassert>
#include <iostream>
#include <limits>   // for std::numeric_limits
#include "Io.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise. does not ignore line if extraction is successful.
bool clearFailedExtraction()
{
	// Check for failed extraction
	if (!std::cin) // If the previous extraction failed
	{
		if (std::cin.eof()) // If the stream was closed
		{
			std::exit(0); // Shut down the program now
		}

		// Let's handle the failure
		std::cin.clear(); // Put us back in 'normal' operation mode
		ignoreLine();     // And remove the bad input

		return true;
	}

	return false;
}


char getValue()
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

		// Check if number between 1 and 9
		if (value >= '1' and value <= '9')
			return value;

		switch (value)
		{
		case 'A':
		case 'K':
		case 'Q':
		case 'J':
			return value;
		default:
			std::cout << "Invalid value. Please input (K)ing, (Q)ueen, (J)ack, (A)ce, or a number between 1 - 10.\n";
		}
	}
}

char getSuit()
{
	while (true)
	{
		char suit{};
		std::cout << "Enter the suit of the card: ";
		std::cin >> suit;

		if (!clearFailedExtraction())
			ignoreLine();

		switch (suit)
		{
		case 'H':
		case 'D':
		case 'S':
		case 'C':
			return suit;
		default:
			std::cout << "Invalid suit. Please input (H)earts, (D)iamonds, (C)lovers, or (S)pades.\n";
		}
	}
}