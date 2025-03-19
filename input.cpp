#include <iostream>

int main(){

    int age; 

    std::string name;

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    std::cout << "Enter age: " << std::endl;
    std::cin >> age;

    std::cout << "" << name << " is " << age << " years old." << std::endl;
}