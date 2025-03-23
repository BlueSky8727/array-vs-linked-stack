#include <iostream>
#include "arraystack.h"

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Push\n";
    std::cout << "2. Pop\n";
    std::cout << "3. Display\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice (0-3): ";
}

int main() {
    ArrayStack stack;
    int choice, value;

    while (true) {
        displayMenu();
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 0 - 3.\n";
            continue;
        }

        switch (choice) {
            case 0:
                std::cout << "Exiting program...\n";
                return 0;
            case 1:
                std::cout << "Enter value to push: ";
                if (std::cin >> value) {
                    stack.push(value);
                } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a numeric value.\n";
                }
                break;
            case 2:
                if (!stack.isEmpty()) {
                    std::cout << "Popped: " << stack.pop() << "\n";
                } else {
                    std::cout << "Stack is empty. Cannot pop.\n";
                }
                break;
            case 3:
                stack.display();
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 0 and 3.\n";
                break;
        }
    }

    return 0;
}
