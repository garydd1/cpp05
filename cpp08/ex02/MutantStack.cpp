#include "MutantStack.hpp"

// template <typename T>
// MutantStack<T>::MutantStack() : std::stack<T>()
// {
// }

// template <typename T>
// MutantStack<T>::MutantStack(T value) : std::stack<T>()
// {
// 	value = value;
// }

// template <typename T>
// MutantStack<T>::MutantStack(MutantStack const &toCopy) : std::stack<T>(toCopy)
// {
// }

// template <typename T>
// MutantStack<T>::~MutantStack()
// {
// }

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &toCopy)
{
	if (this != &toCopy)
	{
		this->t = toCopy.t;
	}
	return (*this);
}

//Element access
// template <typename T>
// T &MutantStack<T>::top()
// {
// 	return (this->t.top());
// }

//Capacity
// template <typename T>
// bool MutantStack<T>::empty() const
// {
// 	return (this->t.empty());
// }

// template <typename T>
// size_t MutantStack<T>::size() const
// {
// 	return (this->t.size());
// }

// //Modifiers
// template <typename T>
// void MutantStack<T>::push(T const &value)
// {
// 	this->t.push(value);
// }

// template <typename T>
// void MutantStack<T>::pop()
// {
// 	this->t.pop();
// }



// //iterators
// template <typename T>
// typename MutantStack<T>::iterator MutantStack<T>::begin()
// {
// 	return (std::stack<T>::c.begin());
// }