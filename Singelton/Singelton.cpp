#include "Singelton.hh" 

// remember to define static vars outside of class (if no const needed)
Singelton* Singelton::singelton_ = nullptr; 


void singelton_test() {

    Singelton* s = Singelton::get_instance();

    std::cout << s->get_data() << std::endl;

    Singelton& s1 = *Singelton::get_instance(); // you can also use it through a ref var

}

Singelton::Singelton(std::string data) {
    this->data_ = data;
}

std::string Singelton::get_data() {
    return data_;
}

Singelton* Singelton::get_instance() {
    if (!Singelton::singelton_)
        Singelton::singelton_ = new Singelton("We got an Instance!!");

    return Singelton::singelton_;
}
