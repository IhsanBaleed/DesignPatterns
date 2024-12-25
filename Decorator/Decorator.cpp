#include "Decorator.hh" 

void decorator_test() {

    std::shared_ptr<Component> c_a = std::make_shared<ConcreteCompA>();

    std::shared_ptr<Component>  d_a = std::make_shared<ConcreteDecoratorA>(c_a);
    std::cout << d_a->look_up() << std::endl;
    std::cout << d_a->spin_around() << std::endl;

    std::shared_ptr<Component>  d_b = std::make_shared<ConcreteDecoratorB>(d_a);
    std::cout << d_b->look_up() << std::endl;
    std::cout << d_b->spin_around() << std::endl;

    std::shared_ptr<Component>  d_a2 = std::make_shared<ConcreteDecoratorA>(d_b);
    std::cout << d_a2->look_up() << std::endl;
    std::cout << d_a2->spin_around() << std::endl;
    
    // we can make many decoratros, each can have a unique imlementation
    // which in turn can call other decorators
    // this can loop around until we eventaully reach a component
    // which would be the samllest doll in the set.
}



