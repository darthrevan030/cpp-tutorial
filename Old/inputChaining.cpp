#include <iostream>
#include <string>

int main(){

    int age; 

    std::string name;

    std::cout << "Enter name and age: " << std::endl;
    std::cin >> name >> age;

    std::cout << "" << name << " is " << age << " years old." << std::endl;

    return 0;
}