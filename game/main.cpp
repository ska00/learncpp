#include <iostream>
#include <string>
#include "io.h"
#include "Random.h"

using namespace io;
using StringView = std::string_view;
using String = std::string;
void introduction();


int main()
{
	introduction();
    return 0;
}

void introduction()
{
    printl(3);
    center();
    typewrite("....");
    typewrite("........");
    typewrite("Booting up... "); sleep(100);
    typewrite("Processes functional.");
    typewrite("Please enter your name: ", false);
    String name{ getInput() };
    typewrite("Hello");
    typewrite(name);
}