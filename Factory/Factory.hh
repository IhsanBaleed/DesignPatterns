#pragma once

#include <iostream>
#include <memory>
#include <list>


// Use this pattern when you want the user to extend your code
// Use it to save system resources by reusing current objects

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
  std::list<std::shared_ptr<Product>> pool;

public:

  Factory() {
    std::cout << "Factory Constructor" << std::endl;
  }
  ~Factory() {
    std::cout << "Factory Destructor" << std::endl;
  }

  virtual void generate_products(int num) = 0;
  virtual std::shared_ptr<Product> get_a_product() = 0;

};

class FirstProductFactory : public Factory {

public:

  void generate_products(int num) override {
    for (int i=0; i<num; i++) {
      pool.push_back(std::make_shared<FirstProduct>());
    }
  }

  std::shared_ptr<Product> get_a_product() {
    if (pool.size() > 0) {
      std::shared_ptr<Product> p = pool.front();
      pool.pop_front();
      return p;
    } 
    return nullptr;
  }

};

class SecondProductFactory : public  Factory {

public:

  void generate_products(int num) override {
    for (int i=0; i<num; i++) {
      pool.push_back(std::make_shared<SecondProduct>());
    }
  }

  std::shared_ptr<Product> get_a_product() {
    if (pool.size() > 0) {
      std::shared_ptr<Product> p = pool.front();
      pool.pop_front();
      return p;
    } 
    return nullptr;
  }

};

void factory_test();

