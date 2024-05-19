/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:32:21 by dgarizad          #+#    #+#             */
/*   Updated: 2024/05/17 20:31:17 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <array>

int main(void)
{
	try{
		Array<int> test1(5);
		Array<int> vacio;
		
		test1[0] = 42;
		test1[test1.size() - 1] = 42;
		
		std::cout << "test nº1 size: " << test1.size() << std::endl;
		for (unsigned int i = 0; i < test1.size(); i++)
		{
			std::cout << "position " << i << " -> " << test1[i] << std::endl;
		}
		std::cout << std::endl;

		Array<int> test2(test1);
		test2[2] = 24;

		std::cout << "test nº2 size: " << test2.size() << std::endl;
		for (unsigned int i = 0; i < test2.size(); i++)
		{
			std::cout << "position " << i << " -> " << test2[i] << std::endl;
		}
		std::cout << std::endl;

		Array<int> test3 = test2;
		std::cout << "test nº3 size: " << test3.size() << std::endl;
		for (unsigned int i = 0; i < test3.size(); i++)
		{
			std::cout << "position " << i << " -> " << test3[i] << std::endl;
		}
		std::cout << std::endl;
		
		
		
		//Array<char> ola;
		
		//return 0;
	}catch(std::exception &err){
		std::cout << err.what() << std::endl;
	}

}