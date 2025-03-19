#include <iostream>

int main(){
    //std::cout - Printing stuff to the console
    std::cout << "Hello" << std::endl;

    std::cout << "The number is: " << 12 << std::endl;

    int age {21};
    std::cout << "The age is: " << age << std::endl;

    //std::cerr - Printing errors to the console
    std::cerr << "std::cerr Output: Something went wrong" << std::endl;

    //std::clog - Printing log messages to the console
    std::clog << "std::clog Output: This is a log message" << std::endl;

}