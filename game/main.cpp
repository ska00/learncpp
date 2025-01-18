#include <iostream>
#include "io.h"
#include "Random.h"

using namespace io;

void introduction()
{
	io::printl(3);
	io::center();
	io::typewrite("....");
	typewrite("........");
	typewrite("Booting up... "); sleep(100);
	typewrite("Processes functional.");
	typewrite("Please enter your name: ");
	std::string name{ getName() };
	typewrite("Hello");
	typewrite(name);
}

int main()
{
	introduction();
	return 0;
}