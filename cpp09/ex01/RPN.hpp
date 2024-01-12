#ifndef RPN_HPP 
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>

class Rpn
{
	public:
		Rpn();
		Rpn(int argc, char **argv);
		~Rpn();
		Rpn(const Rpn& toCopy);
		Rpn& operator=(const Rpn& toCopy);

		void process(int argc, char **argv);
		double add(double a, double b); 
		double subtract(double a, double b);
		double multiply(double a, double b);
		double divide(double a, double b);
		
		void printStack();
	private:
		std::stack<std::string> _stack;
		double (Rpn::*funcs[4])(double, double);
};


#endif
