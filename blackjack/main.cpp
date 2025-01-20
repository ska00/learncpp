#include <iostream>
#include <cassert>  // for assert()
#include <string>
#include "Io.h"

int runTests();

int main()
{
	runTests();

	/*char suit{ getSuitFromUser() };
	char value{ getValueFromUser() };

	std::cout << getCard(value, suit);*/

	char card1{ 'Q' };
	char card2{ 'A' };

	std::cout << max(card1, card2);

	return 0;
}