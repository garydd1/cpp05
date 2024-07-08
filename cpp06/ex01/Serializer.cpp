#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

void* Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<void*>(ptr);
}

Serializer::Data* Serializer::deserialize(void* raw)
{
    return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer(std::string const &value)
{
	(void)value;
}

Serializer::Serializer(Serializer const &toCopy)
{
	(void)toCopy;
}

Serializer &Serializer::operator=(Serializer const &toCopy)
{
	(void)toCopy;
	return *this;
}

