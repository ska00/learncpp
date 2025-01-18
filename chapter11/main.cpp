#include <iostream>
#include <type_traits> 

// Forward declaration
template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>;

// Function overloading
//int add(int x, int y)
//{
//	return x + y;
//}
//
//double add(double x, double y)
//{
//	return x + y;
//}

template <typename T>
T add(T x, T y)
{
	return x + y;
}

template <typename T>
T mult(T x, int y) {
	return x * y;
}

//int max(int x, int y)
//{
//	return (x < y) ? y : x;
//}

// Function template (have to be the same type)
//template <typename T>
//T max(T x, T y)
//{
//	return (x < y) ? y : x;
//}

// This can be forward declared.
template <typename T, typename U>
auto max(T x, U y) -> std::common_type_t<T, U>
{
	return (x < y) ? y : x;
}

template <typename T>
void ptype(T x)
{
	std::cout << "The value " << x << " has type: " << typeid(x).name() << '\n';
}

template <int N>
constexpr int factorial()
{
	static_assert((N >= 0) && "factorial(): N must be non-negative.");

	int result{ 1 };
	for (int i{ 1 }; i <= N; ++i)
		result *= i;

	return result;
}

int main()
{
	static_assert(factorial<0>() == 1);
	static_assert(factorial<3>() == 6);
	static_assert(factorial<5>() == 120);

	factorial<-3>(); // should fail to compile

	return 0;
}