#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cmath>

class Span
{
	public:

		//OCF Orthodox Canonical Form
		Span();
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &copy);
		~Span();

		//Member functions
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

		//Exceptions
		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		unsigned int _n;
		std::vector<int> _v;

};


#endif
