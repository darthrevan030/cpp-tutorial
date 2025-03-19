#include <iostream>

int main(){

    int age; 

    std::string name;

    // taking str as input
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    // taking int as input
    std::cout << "Enter age: " << std::endl;
    std::cin >> age;

    // using the inputs from the user, making an output statement
    std::cout << "" << name << " is " << age << " years old." << std::endl;
}