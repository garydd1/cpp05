#include "Serializer.hpp"
#include <iostream>
#include <cstdlib> // For srand
#include <ctime>   // For time
int main()
{
    Serializer::Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";
    void* raw = Serializer::serialize(&data); // Changed uintptr_t to void*
    std::cout << raw << std::endl; // This will print the pointer value
    std::cout << &raw << std::endl; // This prints the address of the pointer variable itself
    Serializer::Data* data2 = Serializer::deserialize(raw); // No change needed here
    std::cout << data2->s1 << std::endl;
    std::cout << data2->n << std::endl;
    std::cout << data2->s2 << std::endl;

    //Address of data and data2
    std::cout << &data << std::endl; // Prints the address of data
    std::cout << data2 << std::endl; // Prints the address stored in data2, should match the value printed by `std::cout << raw << std::endl;`
    return 0;
}