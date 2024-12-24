#include "Factory.hh"

void factory_test() {

    while (true) {
        std::cout << "Select Product Type 1, 2 or exit to return. \n" << std::endl;
        std::string input; std::cin >> input;

        std::unique_ptr<Factory> f;

        if (input == "1") {
            f = std::make_unique<FirstProductFactory>();
        } else if (input == "2") {
            f = std::make_unique<SecondProductFactory>();
        } else if (input == "exit") break;

        std::shared_ptr<Product> p = f->get_product();

        p->display_price();
        p->state_type();
    }
}

