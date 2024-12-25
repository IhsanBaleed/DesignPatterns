#pragma once

#include <iostream>
#include <string>
#include <memory>

// the interface that all instances will implement/inherit
class Component {

public:
    virtual ~Component() {
        std::cout << "Destructor Called" << std::endl;
    }

    virtual std::string print_message() = 0;
    virtual std::string spin_around() = 0;
    virtual std::string look_up() = 0;
};

// we can create as many components as we want.

class ConcreteCompA : public Component {
public:
    std::string print_message() override {
        return "I am ConcreteCompA";
    }
    std::string spin_around() override {
        return "ConcreteCompA Spin around";
    }
    std::string look_up() override {
        return "ConcreteCompA Look up";
    }
};

class ConcreteCompB : public Component {
public:
    std::string print_message() override {
        return "I am ConcreteCompB";
    }
    std::string spin_around() override {
        return "ConcreteCompB Spin around";
    }
    std::string look_up() override {
        return "ConcreteCompB Look up";
    }
};

//------------------------------------------------------------------------

class Decorator : public Component {

protected:
    std::shared_ptr<Component> comp_ptr;

public:
    Decorator (std::shared_ptr<Component> comp_ptr) {
        this->comp_ptr = comp_ptr;
    }

    std::string print_message() override {
        return comp_ptr->print_message();
    }
    std::string spin_around() override {
        return comp_ptr->spin_around();
    }
    std::string look_up() override {
        return comp_ptr->look_up();
    }
};

// we can create as many decorators as we want, this allows to stack behaviours on top another
// but, to make them wrap around each other, we must let once decorator capture another
// we cant let a component wrap a decorator, components sit at the very end of things.

class ConcreteDecoratorA : public Decorator {

public:
    ConcreteDecoratorA(std::shared_ptr<Component> comp_ptr) : Decorator(comp_ptr){
    }

    std::string print_message() override {
        return "ConcreteDecoratorA print_message -> " + Decorator::print_message(); 
    }
    std::string spin_around() override {
        return "ConcreteDecoratorA spin_around -> " + Decorator::spin_around(); 
    }
    std::string look_up() override {
        return "ConcreteDecoratorA look_up -> " + Decorator::look_up(); 
    }
};

class ConcreteDecoratorB : public Decorator {

public:
    ConcreteDecoratorB(std::shared_ptr<Component> comp_ptr) : Decorator(comp_ptr){
    }

    std::string print_message() override {
        return "ConcreteDecoratorB print_message -> " + Decorator::print_message(); 
    }
    std::string spin_around() override {
        return "ConcreteDecoratorB spin_around -> " + Decorator::spin_around(); 
    }
    std::string look_up() override {
        return "ConcreteDecoratorB look_up -> " + Decorator::look_up(); 
    }
};

void decorator_test();