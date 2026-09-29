#include <iostream>
#include <math.h>


int main() {
    double x = 0;
    double y = 0;
    char op;

    std::cout << "Enter a Number: " << std::endl;
    std::cin >> x;

    std::cout << "Enter another Number: " << std::endl;
    std::cin >> y;

    std::cout << "Enter an operation (+, -, *, /): " << std::endl;
    std::cin >> op;

    switch (op) {
        case '+':
            x += y;
            break;
        case '-':
            x -= y;
            break;
        case '*':
            x *= y;
            break;
        case '/':
            if (y != 0) {
                x /= y;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
    }

    std::cout << "The result is " << x << std::endl;

    return 0;
}
