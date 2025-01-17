#include <iostream>

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

int main()
{
	std::cout << add(3, 2);
	std::cout << add(3.3, 3.3);
	return 0;
}