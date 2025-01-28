#pragma once

#include <iostream>
#include <string>
#include <memory>


// Use this pattern when you need to have only one instance of a class
// This instanec is shared across all areas of the code
// Use it to make a global variable, and make control over it strict

class Singelton {

protected:

    std::string data_;

    // This pointer object must be static
    // It also must be a private member
    // We can use raw pointers here, makes things simpler
    static Singelton* singelton_;
    
    // The consturctor should be protected or private to prevent
    // This stops other objects from making copies of it
    Singelton (std::string data);

    ~Singelton() { // No need to destroy the data, the instance should stay there unitl end of program

    }

public:

    // The copy constructor and operators must be deleted
    // This stops the copying of the instance of the class
    // Make sure to delete all public constructors too
    Singelton(Singelton&) = delete; 
    void operator=(const Singelton&) = delete;

    // the method must be static, non-static methods must be called through an object
    static Singelton* get_instance();

    std::string get_data();
};


void singelton_test();


