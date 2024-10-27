#include <iostream>
#include "StateMachine/StateMachine.hh"

std::string menu = "Welcome to Design Patterns in Modern C++\n"
                   "Please select a design pattern to run:\n"
                   "1. State Machine\n"
                   "type Exit to quit\n";

std::string input;

void state_machine_test() {

    std::cout << "State Machine Menu:\n";
    std::cout << "1. Start Charging\n";
    std::cout << "2. Take Order\n";
    std::cout << "3. Wakeup\n";
    std::cout << "4. Repair\n";
    std::cout << "Type 'exit' to quit\n";
    std::cout << "Enter your choice: \n";

    StateMachine robot;

    while (true) {

        std::cin >> input;
    
        if (input == "exit") {
            break;
        } else if (input == "1") {
            robot.start_charging();
        } else if (input == "2") {
            robot.take_order();
        } else if (input == "3") {
            robot.wakeup();
        } else if (input == "4") {
            robot.repair();
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void welcome_menu() {
    std::cout << menu << std::endl;

    while (true) {
        std::cin >> input;
        if (input == "1") {
            state_machine_test();
        } else if (input == "Exit") {
            exit(0);
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << menu << std::endl;
    }
}

int main() {

    welcome_menu();

    return 0;
}