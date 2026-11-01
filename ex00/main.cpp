#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	// vector test
	std::vector<int> vec;
	for (int i = 0; i < 5; i++)
		vec.push_back(i * 10);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "vector: found " << *it
				  << " at index " << std::distance(vec.begin(), it) << std::endl;
		easyfind(vec, 42);
	}
	catch (std::exception& e)
	{
		std::cout << "vector: " << e.what() << std::endl;
	}

	// list test
	std::list<int> lst;
	lst.push_back(7);
	lst.push_back(3);
	lst.push_back(7);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 7);
		std::cout << "list: found " << *it << std::endl;
		easyfind(lst, 100);
	}
	catch (std::exception& e)
	{
		std::cout << "list: " << e.what() << std::endl;
	}

	// deque test
	std::deque<int> dq;
	dq.push_back(-5);
	dq.push_front(1);

	try
	{
		std::deque<int>::iterator it = easyfind(dq, -5);
		std::cout << "deque: found " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "deque: " << e.what() << std::endl;
	}

	// const container test
	const std::vector<int> cvec(vec);
	try
	{
		std::vector<int>::const_iterator it = easyfind(cvec, 40);
		std::cout << "const vector: found " << *it << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "const vector: " << e.what() << std::endl;
	}

	return 0;
}