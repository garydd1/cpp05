#include "Serializer.hpp"

int main()
{
	// Serializer::Data* data = new Serializer::Data;
	Serializer::Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";
	uintptr_t raw = Serializer::serialize(&data);
	Serializer::Data* data2 = Serializer::deserialize(raw);
	std::cout << data2->s1 << std::endl;
	std::cout << data2->n << std::endl;
	std::cout << data2->s2 << std::endl;

	//Address of data and data2
	std::cout << &data << std::endl;
	std::cout << data2 << std::endl;
	return 0;
}