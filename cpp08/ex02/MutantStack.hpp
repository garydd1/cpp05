#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack  : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		~MutantStack() {}
		// MutantStack(MutantStack const &toCopy);
		MutantStack &operator=(MutantStack const &toCopy);

		//Element access
		T& top() {
   			return std::stack<T>::top();
		}

		//Capacity
		// Capacity
	bool empty() const {
		return std::stack<T>::empty();
	}

	size_t size() const {
		return std::stack<T>::size();
	}

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
		std::stack<T> t;
		std::deque<T> d;
};



#endif