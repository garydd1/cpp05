/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:43:49 by dgarizad          #+#    #+#             */
/*   Updated: 2024/05/18 14:18:37 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &toCopy)
{
	if (this != &toCopy)
	{
		this->t = toCopy.t;
		this->d = toCopy.d;
	}
	return (*this);
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &toCopy) : std::stack<T>(toCopy)
{
	*this = toCopy;
}

//parametrized constructor
template <typename T>
MutantStack<T>::MutantStack(size_t initialSize) : std::stack<T>()
{
	this->d.resize(initialSize);
}

