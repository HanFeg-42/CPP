#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& other) : v(other.v), N(other.N) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		N = other.N;
		v = other.v;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (v.size() >= N)
		throw MaximunReachedException();
	v.push_back(n);
}

int Span::shortestSpan()
{
	size_t size = v.size();

	if (size < 2)
		throw std::runtime_error("Not enough numbers!");

	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];     // use adjacent difference

	for (size_t i = 2; i < size; i++)
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];

	return min;
}

int Span::longestSpan()
{
	if (v.size() < 2)
		throw std::runtime_error("Not enough numbers!");

	std::vector<int>::iterator min = std::min_element(v.begin(), v.end());
	std::vector<int>::iterator max = std::max_element(v.begin(), v.end());

	return *max - *min;
}

const char* Span::MaximunReachedException::what() const throw()
{
	return "Max numbers that can be stored is reached!";
}
