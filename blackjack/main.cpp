#include <iostream>
#include <cassert>  // for assert()
#include <string>
#include "Io.h"


auto getCard(char value, char suit) -> std::string
{
	using namespace std::literals::string_literals;

	std::string card{ " ___ \n" };
	card += "|"s + value + "  |\n"s;
	card += "| "s + suit + " |\n"s;
	card += "|__"s + value + "|\n"s;

	return card;
}


int main()
{
	/*std::cout << getCard('9', 'H');*/
	char suit{ getSuit() };
	char value{ getValue() };

	std::cout << getCard(value, suit);


	return 0;
}