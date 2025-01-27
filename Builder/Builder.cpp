#include "Builder.hh" 

void builder_test() { // clinet code

    std::shared_ptr<Oven> bread_oven = std::make_shared<BreadOven>("Cheese Bread");
    Baker baker(bread_oven);
    baker.make_bread();
    std::cout << bread_oven->get_product()->show_recipe() << std::endl;
    bread_oven->reset("Garlic Bread");
    baker.make_bread();

    std::shared_ptr<Oven> pie_oven = std::make_shared<PieOven>("Apple Pie");
    baker.set_oven(pie_oven);
    baker.make_pie();
    std::cout << pie_oven->get_product()->show_recipe() << std::endl;
    pie_oven->reset("Cherry Pie");

    std::shared_ptr<Oven> cake_oven = std::make_shared<CakeOven>("Black Forest");
    baker.set_oven(cake_oven);
    baker.make_cake();
    std::cout << cake_oven->get_product()->show_recipe() << std::endl;
    cake_oven->reset("Classic Chocolate");

    std::cout << std::endl;
}



BakeryProduct::BakeryProduct(std::string name, ItemType item_type) : 
    item_type(item_type), name(name) {}

void BakeryProduct::set_recipe(std::string operations) {
    recipe += operations + "\n";
}

std::string BakeryProduct::show_recipe() {
        return recipe;
}



Bread::Bread(std::string name) : BakeryProduct (name, ItemType::Bread) {}

Pie::Pie(std::string name) : BakeryProduct (name, ItemType::Pie) {}

Cake::Cake(std::string name) : BakeryProduct (name, ItemType::Cake) {}



void Oven::set_heat(int heat) {
    this->heat = heat;
}

void Oven::set_timer(int timer) {
    this->timer = timer;
}

void Oven::reset(std::string) {
    product.reset();
}

BakeryProduct* Oven::get_product() {
    return product.get();
}



BreadOven::BreadOven(std::string bread_type) {
    product = std::make_unique<Bread>(bread_type);
}

void BreadOven::add_sugar(std::string amount) {
    if (product)
        product->set_recipe("Bread Oven added " + amount + " of sugar");
}

void BreadOven::add_yeast(std::string amount) {
    if (product)
        product->set_recipe("Bread Oven added " + amount + " of yeast");
}

void BreadOven::add_water(std::string amount) {
    if (product)
        product->set_recipe("Bread Oven added " + amount + " of water");
}

void BreadOven::add_flour(std::string amount) {
    if (product)
        product->set_recipe("Bread Oven added " + amount + " of flour");
}

void BreadOven::do_recipe() {
    add_sugar("13 g");
    add_yeast("5 g");
    add_water("30 g");
    add_flour("20 g");
}

void BreadOven::reset(std::string bread_type) {
    Oven::reset();
    product = std::make_unique<Bread>(bread_type);
}



PieOven::PieOven(std::string pie_type) {
    product = std::make_unique<Pie>(pie_type);
}

void PieOven::add_sugar(std::string amount) {
    if (product)
        product->set_recipe("Pie Oven added " + amount + " of sugar");
}

void PieOven::add_yeast(std::string amount) {
    if (product)
        product->set_recipe("Pie Oven added " + amount + " of yeast");
}

void PieOven::add_water(std::string amount) {
    if (product)
        product->set_recipe("Pie Oven added " + amount + " of water");
}

void PieOven::add_flour(std::string amount) {
    if (product)
        product->set_recipe("Pie Oven added " + amount + " of flour");
}

void PieOven::do_recipe() {
    add_yeast("22 g");
    add_flour("50 g");
    add_water("30 g");
}

void PieOven::reset(std::string pie_type) {
    Oven::reset();
    product = std::make_unique<Pie>(pie_type);
}



CakeOven::CakeOven(std::string cake_type) {
    product = std::make_unique<Cake>(cake_type);
}

void CakeOven::add_sugar(std::string amount) {
    if (product)
        product->set_recipe("Cake Oven added " + amount + " of sugar");
}

void CakeOven::add_yeast(std::string amount) {
    if (product)
        product->set_recipe("Cake Oven added " + amount + " of yeast");
}

void CakeOven::add_water(std::string amount) {
    if (product)
        product->set_recipe("Cake Oven added " + amount + " of water");
}

void CakeOven::add_flour(std::string amount) {
    if (product)
        product->set_recipe("Cake Oven added " + amount + " of flour");
}

void CakeOven::add_chocolate(std::string amount) {
    if (product)
        product->set_recipe("Cake Oven added " + amount + " of chocolate");
}

void CakeOven::do_recipe() {
    add_yeast("22 g");
    add_flour("50 g");
    add_water("30 g");
    add_chocolate("50 g");
}

void CakeOven::reset(std::string cake_type) {
    Oven::reset();
    product = std::make_unique<Cake>(cake_type);
}



Baker::Baker(std::shared_ptr<Oven> oven) {
    oven_ = oven;
}

void Baker::set_oven(std::shared_ptr<Oven> oven) {
    oven_ = oven;
}

void Baker::make_bread() {
    oven_->set_heat(120);
    oven_->set_timer(60);
    oven_->add_sugar("20 G");
    oven_->add_water("25 G");
    oven_->add_yeast("4 G");
    oven_->add_flour("30 G");
}

void Baker::make_pie() {
    oven_->set_heat(200);
    oven_->set_timer(120);
    oven_->add_water("25 G");
    oven_->add_yeast("4 G");
    oven_->add_flour("55 G");
}

void Baker::make_cake() {
    if (std::dynamic_pointer_cast<CakeOven>(oven_)) { // if it is a cake
        oven_->do_recipe();
        auto cake_oven = std::dynamic_pointer_cast<CakeOven>(oven_);

        cake_oven->add_chocolate("30 g");
        cake_oven->add_chocolate("20 g");
        cake_oven->add_chocolate("40 g");
    }
}
