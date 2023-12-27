#include "Span.hpp"
#include <numeric>

Span::Span()
{

}

Span::Span(unsigned int n)
{
	this->_n = n;
}

Span::Span(Span const &copy)
{
	*this = copy;
}

Span &Span::operator=(Span const &copy)
{
	this->_n = copy._n;
	return (*this);
}

Span::~Span()
{

}

void	Span::addNumber(int n)
{
	if (this->_v.size() < this->_n)
		this->_v.push_back(n);
	else
		throw Span::FullSpanException();
}

int		Span::shortestSpan()
{
	if (this->_v.size() <= 1)
		throw Span::NoSpanException();
	std::vector<int> tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int> diffs(tmp.size());
	std::cout << std::endl;
	std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin());
	int min = *std::min_element(diffs.begin() +1, diffs.end());
	return (min);
}

int		Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw Span::NoSpanException();
	int min = *std::min_element(this->_v.begin(), this->_v.end());
	int max = *std::max_element(this->_v.begin(), this->_v.end());
	return (max - min);
}
const char* Span::FullSpanException::what() const throw()
{
	return ("Span is full");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("No span to find");
}