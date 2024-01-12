#include "RPN.hpp"

Rpn::Rpn()
{
	std::cout << "Default constructor called; this wont be usefull" << std::endl;
}

Rpn::~Rpn()
{

}

Rpn::Rpn(int arg, char** argv)
{
	for (int i = 1; i < arg; i++)
	{
		this->_stack.push(argv[i]);
	}

	funcs[0] = &Rpn::add;
	funcs[1] = &Rpn::subtract;
	funcs[2] = &Rpn::multiply;
	funcs[3] = &Rpn::divide;
}

void Rpn::printStack()
{
	std::stack<std::string> tmp = _stack;
	while(!tmp.empty())
	{
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
}

void Rpn::process(int argc, char** argv)
{
	std::stack <double> stack;
	std::string operators = "+-*/";
	double temp;
	std::istringstream iss(argv[1]);
	std::string item;
	argc ++;

	while(iss >> item)
	{
		std::stringstream ss(item);
		double value; 
		if (ss >> value)
		{
			stack.push(value);
			std::cout << "pushed: " << value << std::endl;
		}else if (operators.find(item) != std::string::npos)
		{
			if (stack.size() < 2)
			{
				std::cout << "Ended possible operations" << std::endl;
				break;
			}
			temp = stack.top();
			std::cout << "doing: "<< stack.top() << operators[operators.find(item)]; 
			stack.pop();
			std::cout<< stack.top() << std::endl;
			temp = (this->*funcs[operators.find(item)])(stack.top(), temp);
			stack.pop();
			stack.push(temp);
			std::cout << "pushed: " << temp << std::endl;
			
		}else 
		{
			std::cout << "Error" << std::endl;
			exit (1);
		}	
	}
	std::cout << "result: " << temp << std::endl;
}

double Rpn::add(double a, double b)
{
	return (a + b);
}

double Rpn::subtract(double a, double b)
{
	return (a - b);
}

double Rpn::divide(double a, double b)
{
	return (a / b);
}

double Rpn::multiply(double a, double b)
{
	return (a * b);
}
