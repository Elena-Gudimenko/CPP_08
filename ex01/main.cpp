#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include "Span.hpp"

int main()
{
	std::cout << "=== Subject test ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== Full span ===" << std::endl;
	{
		Span sp(2);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Not enough numbers ===" << std::endl;
	{
		Span empty(10);
		try
		{
			empty.shortestSpan();
		}
		catch (std::exception& e)
		{
			std::cout << "Empty: " << e.what() << std::endl;
		}

		Span one(10);
		one.addNumber(42);
		try
		{
			one.longestSpan();
		}
		catch (std::exception& e)
		{
			std::cout << "One number: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Extreme values (overflow check) ===" << std::endl;
	{
		Span sp(2);
		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n=== addRange with 10000 known numbers ===" << std::endl;
	{
		std::vector<int> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(i * 3);

		Span sp(10000);
		sp.addRange(v.begin(), v.end());
		std::cout << "size:     " << sp.size() << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << " (expected 3)" << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << " (expected 29997)" << std::endl;
	}

	std::cout << "\n=== addRange from std::list, overflow ===" << std::endl;
	{
		std::list<int> lst(20, 7);
		Span sp(10);
		try
		{
			sp.addRange(lst.begin(), lst.end());
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== 100000 random numbers ===" << std::endl;
	{
		std::srand(std::time(NULL));
		std::vector<int> v(100000);
		std::generate(v.begin(), v.end(), std::rand);

		Span sp(100000);
		sp.addRange(v.begin(), v.end());
		std::cout << "size:     " << sp.size() << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest:  " << sp.longestSpan() << std::endl;
	}

	return 0;
}