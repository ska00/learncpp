#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string_view>

namespace io
{
	// Only include functions we want to be used.
	void sleep(int ms);
	void center();
	std::string getName();
	void uncenter();
	void centerCout(std::string_view message);
	void typewrite(std::string_view message);
	void printl(int numLines);
	static bool isPunctuation(char c);
	static void setupCenter(std::string_view);
}