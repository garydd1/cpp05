#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <iostream>


class Serializer
{
    public:

    typedef struct Data
    {
        std::string s1;
        int n;
        std::string s2;
    } Data;
    
    static void* serialize(Data* ptr); // Changed return type to void*
    static Data* deserialize(void* raw); // Changed parameter type to void*
	 
	
    ~Serializer();
	Serializer &operator=(Serializer const &toCopy);
	Serializer(Serializer const &toCopy);

    private:
    
    Serializer();
	Serializer(std::string const &value);
};

#endif