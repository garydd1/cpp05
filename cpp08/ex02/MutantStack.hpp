#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack  : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(size_t initialSize);
		MutantStack(MutantStack const &toCopy);
		MutantStack &operator=(MutantStack const &toCopy);

	// Modifiers
	void push(T const &value) {

		std::stack<T>::push(value);
		d.push_back(value);
	}

	void pop() {
		std::stack<T>::pop();
		d.pop_back();
	}
		
	//Iterator
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() 
	{
		return (this->d.begin());
	}
	iterator end() {
		return (this->d.end());
	}

	private:
		std::deque<T> d;
};

#include "MutantStack.tpp"

#endif
