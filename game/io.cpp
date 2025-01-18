#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <string_view>
#include "io.h"

namespace io
{
	using std::cout;

	constexpr int g_typewriteSpeedDefault{ 50 };
	constexpr int g_typewriteSpeedSpace{ 120 };
	constexpr int g_typewriteSpeedPunc{ 250 };

	constexpr int g_consoleWidth{ 121 };

	bool isCentered{ false };

	std::string getName()
	{
		std::string name{};
		std::getline(std::cin >> std::ws, name);
		return name;
	}

	void awaitInput()
	{
		char input{};
		std::cin.get(input);
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

	static bool isPunctuation(char c)
	{
		if (c == '.' or c == '?' or c == '!' or c == ',')
			return true;
		return false;
	}

	void typewrite(std::string_view message)
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

		awaitInput();
	}

	void printl(int numLines)
	{
		for (int i {0}; i < numLines; ++i)
			cout << '\n';
	}

	void centerCout(std::string_view message)
	{
		int leadingSpaces{ g_consoleWidth - static_cast<int>(message.length()) };
		leadingSpaces /= 2;

		for (int i{ 0 }; i < leadingSpaces; ++i)
			cout << " ";

		cout << message;
	}

	static void setupCenter(std::string_view message)
	{
		int leadingSpaces{ g_consoleWidth - static_cast<int>(message.length()) };
		leadingSpaces /= 2;

		for (int i{ 0 }; i < leadingSpaces; ++i)
			cout << " ";
	}
}