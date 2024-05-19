#include "Span.hpp"

int main()
{
Span sp = Span(5);
std::vector<int> numbers;
numbers.push_back(6);
numbers.push_back(3);
numbers.push_back(17);
numbers.push_back(9);
numbers.push_back(11);
for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
    sp.addNumber(*it);
}
try {
	sp.addNumber(14);
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
Span sp2 = Span(1);
try {
	sp2.shortestSpan();
}
catch (std::exception &e)
{
	std::cout << e.what() << std::endl;
}
return 0;
}
