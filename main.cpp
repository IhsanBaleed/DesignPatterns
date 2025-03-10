#include <iostream>
#include "StateMachine/StateMachine.hh"
#include "Factory/Factory.hh"
#include "Decorator/Decorator.hh"
#include "Builder/Builder.hh"
#include "Singelton/Singelton.hh"
#include "AbstractFactory/AbstractFactory.hh"
#include "Prototype/Prototype.hh"

#include "Consts.hh"

void welcome_menu() {
    std::cout << menu << std::endl;

    while (true) {

        std::string input;
        std::cin >> input;

        if (input == "1") {
            state_machine_test();
        } else if (input == "2") {
            factory_test();
        } else if (input == "3") {
            decorator_test();
        } else if (input == "4") {
            builder_test();
        } else if (input == "5") {
            singelton_test();
        } else if (input == "6") {
            abstract_factory_test();
        } else if (input == "7") {
            prototype_test();
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
