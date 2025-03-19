#include <iostream>
#include <string> // need string library for getline

int main(){

    int age; 

    std::string fullName;

    std::cout << "Enter full name: " << std::endl;
    std::getline(std::cin, fullName); // get the entire input from the whole line instead of just cutting off at the first whitespace

    std::cout << "Enter age: " << std::endl;
    std::cin >> age;

    std::cout << "" << fullName << " is " << age << " years old." << std::endl;
}