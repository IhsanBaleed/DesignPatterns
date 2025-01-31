#include "AbstractFactory.hh" 

void abstract_factory_test() {

    std::unique_ptr<IFactory> p_f = std::make_unique<PlasticFactory>("High Quality Plastics");
    std::unique_ptr<IFactory> w_f = std::make_unique<WoodenFactory>("Oak Factory");

    std::shared_ptr<IChair> w_c = w_f->make_chair("Fancy Chair");
    std::shared_ptr<IChair> p_c = p_f->make_chair("Plastic Chair");

    w_c->state_type();
    p_c->state_type();


    std::shared_ptr<ISofa> w_s = w_f->make_sofa("Fancy Sofa");
    std::shared_ptr<ISofa> p_s = p_f->make_sofa("Plastic Sofa");

    w_s->state_type();
    p_s->state_type();
}
