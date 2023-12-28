#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <iostream>
#include <cstdint>

class Serializer
{
	public:

	typedef struct Data
	{
		std::string s1;
		int n;
		std::string s2;
	} Data;
	
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	~Serializer();
	private:
	
	Serializer();

};

#endif 