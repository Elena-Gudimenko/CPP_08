#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

// Thrown when the value is not present in the container
class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Value not found in container";
	}
};

// Returns an iterator to the first occurrence of value in container
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

// Same as above, for const containers
template <typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif