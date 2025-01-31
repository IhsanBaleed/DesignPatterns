#pragma once
#include <string>
#include <iostream>
#include <memory>

void abstract_factory_test();

class IChair {

    std::string model_;

public:

    IChair(std::string model) : model_(model) {

    }

    std::string get_model() {
        return model_;
    }

    virtual void state_type() = 0;

};

class WoodenChair : public IChair {

public:

    WoodenChair(std::string model) : IChair(model) {}

    void state_type() override {
        std::cout << "I am a wooden chair" << std::endl;
    }

};

class PlasticChair : public IChair {

public:

    PlasticChair(std::string model) : IChair(model) {}

    void state_type() override {
        std::cout << "I am a Plastic chair" << std::endl;
    }

};


class ISofa {

    std::string model_;

public:

    ISofa(std::string model) : model_(model) {

    }

    std::string get_model() {
        return model_;
    }

    virtual void state_type() = 0;
};

class WoodenSofa : public ISofa {

public:

    WoodenSofa(std::string model) : ISofa(model) {}

    void state_type() override {
        std::cout << "I am a Wooden Sofa" << std::endl;
    }
};

class PlasticSofa : public ISofa {

public:
    PlasticSofa(std::string model) : ISofa(model) {}

    void state_type() override {
        std::cout << "I am a Plastic Sofa" << std::endl;
    }
};


class IFactory {

    std::string factory_type;

public:

    IFactory(std::string type) : factory_type(type) {}

    virtual std::shared_ptr<IChair> make_chair(std::string model) = 0;
    
    virtual std::shared_ptr<ISofa> make_sofa(std::string model) = 0;
};

class WoodenFactory : public IFactory {

public:

    WoodenFactory(std::string type) : IFactory(type) {}

    std::shared_ptr<IChair> make_chair(std::string model) override {
        
        std::shared_ptr<IChair> chair = std::make_shared<WoodenChair>(model);

        return chair;
    }

    std::shared_ptr<ISofa> make_sofa(std::string model) override {
        
        std::shared_ptr<ISofa> sofa = std::make_shared<WoodenSofa>(model);

        return sofa;
    }

};

class PlasticFactory : public IFactory {

public:

    PlasticFactory(std::string type) : IFactory(type) {}

    std::shared_ptr<IChair> make_chair(std::string model) override {
        
        std::shared_ptr<IChair> chair = std::make_shared<PlasticChair>(model);

        return chair;
    }

    std::shared_ptr<ISofa> make_sofa(std::string model) override {
        
        std::shared_ptr<ISofa> sofa = std::make_shared<PlasticSofa>(model);

        return sofa;
    }

};
