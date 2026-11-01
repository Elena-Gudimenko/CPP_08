#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullException();
	_numbers.push_back(number);
}

long Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	// Copy to long to avoid overflow, then sort
	std::vector<long> sorted(_numbers.begin(), _numbers.end());
	std::sort(sorted.begin(), sorted.end());

	// diffs[i] = sorted[i] - sorted[i - 1]; diffs[0] is just sorted[0]
	std::vector<long> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

	// Skip the first element, it is not a difference
	return *std::min_element(diffs.begin() + 1, diffs.end());
}

long Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	long minValue = *std::min_element(_numbers.begin(), _numbers.end());
	long maxValue = *std::max_element(_numbers.begin(), _numbers.end());
	return maxValue - minValue;
}

unsigned int Span::size() const
{
	return _numbers.size();
}

unsigned int Span::capacity() const
{
	return _maxSize;
}

const char* Span::FullException::what() const throw()
{
	return "Span is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to find a span";
}