#include "Io.h"

int testIsValidSuit()
{
	assert(isValidSuit('D'));
	assert(!isValidSuit('F'));

	return 0;
}

int testIsValidValue()
{
	assert(isValidValue('4'));
	assert(isValidValue('T'));
	assert(!isValidValue('0'));
	assert(isValidValue(1));		// Will run the overloaded function

	return 0;
}

int runTests()
{
	testIsValidSuit();
	testIsValidValue();

	return 0;
}