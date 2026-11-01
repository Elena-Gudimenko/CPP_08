#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include "MutantStack.hpp"

// Prints any const MutantStack using const_iterator
template <typename T, typename C>
void printConst(const MutantStack<T, C>& ms)
{
	typename MutantStack<T, C>::const_iterator it = ms.begin();
	while (it != ms.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "=== Subject test: MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=== Same test: std::list ===" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.back() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(lst);
	}

	std::cout << "\n=== Reverse iterators ===" << std::endl;
	{
		MutantStack<int> ms;
		for (int i = 1; i <= 5; i++)
			ms.push(i);
		MutantStack<int>::reverse_iterator rit = ms.rbegin();
		while (rit != ms.rend())
		{
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Const iterators ===" << std::endl;
	{
		MutantStack<int> ms;
		ms.push(10);
		ms.push(20);
		ms.push(30);
		printConst(ms);
	}

	std::cout << "\n=== Copy and assignment (deep copy) ===" << std::endl;
	{
		MutantStack<int> a;
		a.push(1);
		a.push(2);

		MutantStack<int> b(a);
		MutantStack<int> c;
		c = a;

		a.push(3);
		std::cout << "a: ";
		printConst(a);
		std::cout << "b: ";
		printConst(b);
		std::cout << "c: ";
		printConst(c);
	}

	std::cout << "\n=== STL algorithms on MutantStack ===" << std::endl;
	{
		MutantStack<int> ms;
		ms.push(4);
		ms.push(8);
		ms.push(15);
		ms.push(16);
		ms.push(23);
		ms.push(42);

		std::cout << "sum: " << std::accumulate(ms.begin(), ms.end(), 0) << std::endl;
		std::cout << "max: " << *std::max_element(ms.begin(), ms.end()) << std::endl;

		MutantStack<int>::iterator found = std::find(ms.begin(), ms.end(), 15);
		if (found != ms.end())
			std::cout << "found: " << *found << std::endl;
		else
			std::cout << "15 not found" << std::endl;
	}

	std::cout << "\n=== Other types and underlying containers ===" << std::endl;
	{
		MutantStack<std::string> words;
		words.push("hello");
		words.push("mutant");
		words.push("stack");
		printConst(words);

		MutantStack<int, std::vector<int> > vecStack;
		vecStack.push(100);
		vecStack.push(200);
		printConst(vecStack);

		MutantStack<int, std::list<int> > listStack;
		listStack.push(-1);
		listStack.push(-2);
		printConst(listStack);
	}

	return 0;
}