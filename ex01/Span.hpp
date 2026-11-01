#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(int number);
	long	shortestSpan() const;
	long	longestSpan() const;

	unsigned int	size() const;
	unsigned int	capacity() const;

	// Adds a whole range of numbers in one call
	template <typename InputIt>
	void	addRange(InputIt begin, InputIt end)
	{
		unsigned long count = std::distance(begin, end);
		if (_numbers.size() + count > _maxSize)
			throw FullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	class FullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif