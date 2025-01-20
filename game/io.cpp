#include <chrono>		// for std::chrono::milliseconds
#include <conio.h>		// for _getch()
#include <iostream>
#include <limits>		// for std::numeric_limits
#include <string>		// for std::string 
#include <string_view>	// for std::string_view
#include <thread>		// for sleep
#include "io.h"

// Constants (not accessible outside of this file)
constexpr int g_typewriteSpeedDefault{ 50 };
constexpr int g_typewriteSpeedSpace{ 120 };
constexpr int g_typewriteSpeedPunc{ 250 };
constexpr int g_consoleWidth{ 121 };
static bool isCentered{ false };

// Helper functions
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
bool clearFailedExtraction()
{
	// Check for failed extraction
	if (!std::cin) // If the previous extraction failed
	{
		if (std::cin.eof()) // If the user entered an EOF
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


namespace io
{
	using std::cout;
	using StringView = std::string_view;
	using String = std::string;

	String getInput()
	{
		String input{};
		std::getline(std::cin >> std::ws, input);
		return input;
	}

	static bool isPunctuation(char c)
	{
		if (c == '.' or c == '?' or c == '!' or c == ',')
			return true;
		return false;
	}

	void awaitEnter()
	{
		if (std::cin.eof()) // If the user entered an EOF
		{
			std::exit(0); // Shut down the program now
		}

		while (true)	// Do not show output any characters the user might put in and only break when enter is pressed
		{
			if (static_cast<char>(_getch()) == '\r')
				break;
		}
		std::cout << '\n';
	}

	void center()
	{
		isCentered = true;
	}

	void uncenter()
	{
		isCentered = false;
	}

	void sleep(int ms)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	}

	void typewrite(StringView message, bool waiting)
	{
		std::size_t length{ message.length() };

		if (isCentered)
			setupCenter(message);

		for (std::size_t i{ 0 }; i < length; ++i)
		{
			cout << message[i];

			if (message[i] == ' ')
				sleep(g_typewriteSpeedSpace);
			else if (isPunctuation(message[i]))
				sleep(g_typewriteSpeedPunc);
			else
				sleep(g_typewriteSpeedDefault);
		}

		if (waiting)
			awaitEnter();
	}

	void printl(int numLines)
	{
		for (int i {0}; i < numLines; ++i)
			cout << '\n';
	}

	void centerCout(StringView message)
	{
		int leadingSpaces{ g_consoleWidth - static_cast<int>(message.length()) };
		leadingSpaces /= 2;

		for (int i{ 0 }; i < leadingSpaces; ++i)
			cout << " ";

		cout << message;
	}

	static void setupCenter(StringView message)
	{
		int leadingSpaces{ g_consoleWidth - static_cast<int>(message.length()) };
		leadingSpaces /= 2;

		for (int i{ 0 }; i < leadingSpaces; ++i)
			cout << " ";
	}
}