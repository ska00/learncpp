#pragma once

#include <iostream>
#include <chrono>
#include <conio.h>
#include <thread>
#include <string_view>

namespace io
{
	// Only include functions we want to be used.
	void sleep(int ms);
	void center();
	auto getInput() -> std::string;
	void uncenter();
	void centerCout(std::string_view message);
	void typewrite(std::string_view message, bool waiting = true);
	void printl(int numLines);
	static bool isPunctuation(char c);
	static void setupCenter(std::string_view);
}