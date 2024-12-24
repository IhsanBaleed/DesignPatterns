#pragma once

#include <iostream>
#include <memory>

class Product {

public:
  Product() {
    std::cout << "Product Constructor" << std::endl;
  }
  ~Product() {
    std::cout << "Product Destructor" << std::endl;
  }
  virtual void display_price() = 0;
  virtual void state_type() = 0;

};

// you must use public when you want to inherit
// otherwise the default constructor will be protected
class FirstProduct : public Product{

  void display_price() override { 
    std::cout << "First Product Price" << std::endl;
  }

  void state_type() override {
    std::cout << "I am First Product" << std::endl;
  }

};

class SecondProduct : public Product{

  void display_price() override { 
    std::cout << "Second Product Price" << std::endl;
  }

  void state_type() override {
    std::cout << "I am Second Product" << std::endl;
  }

};


class Factory {

protected:
  std::shared_ptr<Product> p_ptr;

public:

  Factory() {
    std::cout << "Factory Constructor" << std::endl;
  }
  ~Factory() {
    std::cout << "Factory Destructor" << std::endl;
  }

  std::shared_ptr<Product> get_product() {
    return p_ptr; 
  }

};

class FirstProductFactory : public Factory {

public:
  FirstProductFactory() {
    p_ptr = std::make_shared<FirstProduct>();
  }

};

class SecondProductFactory : public  Factory {

public:
  SecondProductFactory() {
    p_ptr = std::make_shared<SecondProduct>();
  }

};

void factory_test();

