#pragma once

#include <string>
#include <memory>
#include <iostream>

void builder_test(); // client / driver code

// Use this pattern when you have a product
// but this product requires lots of configuration
// this allows us to make a product in anyway we want with endless costtomzations
// you can call the builder directly
// you can also make a director that makes a pre-defind products based on its methods

// p.s: use reset() on unique_ptr to release memory.



enum class ItemType {
    Undefined,
    Bread,
    Cake,
    Pie
};


// products
class BakeryProduct {

    ItemType item_type;
    std::string name;
    std::string recipe;

protected: // only children calsses can be made

    BakeryProduct (std::string name, ItemType item_type);

public:

    virtual ~BakeryProduct() {
        std::cout << "Item Destroyed " << name << std::endl; 
    }

    void set_recipe(std::string operations);

    std::string show_recipe();

};

class Bread : public BakeryProduct {

public:

    Bread(std::string name);
};

class Cake : public BakeryProduct {

public:

    Cake(std::string name);
};

class Pie : public BakeryProduct {

public:

    Pie(std::string name);
};


// interfaces
class Oven {

protected:
    std::unique_ptr<BakeryProduct> product;
    int heat = 0;
    int timer = 0;

public:

    BakeryProduct* get_product();

    virtual void reset(std::string = "");

    virtual void set_heat(int heat);
    virtual void set_timer(int timer);

    virtual void add_sugar(std::string amount) = 0;
    virtual void add_yeast(std::string amount) = 0;
    virtual void add_water(std::string amount) = 0;
    virtual void add_flour(std::string amount) = 0;

    virtual void do_recipe() = 0;
};

class ISweetsOven : public Oven {

public:

    virtual void add_chocolate(std::string amout) = 0;

};


// builders (Ovens in this case)
class BreadOven : public Oven {

public:

    BreadOven(std::string bread_type);

    void add_sugar(std::string amount) override;
    void add_yeast(std::string amount) override;
    void add_water(std::string amount) override;
    void add_flour(std::string amount) override;

    void do_recipe() override;

    void reset(std::string bread_type);
};

class PieOven : public Oven {

public:

    PieOven(std::string pie_type);

    void add_sugar(std::string amount) override;
    void add_yeast(std::string amount) override;
    void add_water(std::string amount) override;
    void add_flour(std::string amount) override;

    void do_recipe() override;

    void reset(std::string pie_type);
};

// let cake oven have a different interface unique for chocolate cake
class CakeOven : public ISweetsOven {
    
public:

    CakeOven(std::string pie_type);

    void add_sugar(std::string amount) override;
    void add_yeast(std::string amount) override;
    void add_water(std::string amount) override;
    void add_flour(std::string amount) override;
    void add_chocolate(std::string amout) override;

    void do_recipe() override;

    void reset(std::string pie_type);
};


// Director (Baker in this case)
class Baker {

    std::shared_ptr<Oven> oven_;

public:

    Baker(std::shared_ptr<Oven> oven);

    void set_oven(std::shared_ptr<Oven> oven);
    
    void make_bread();

    void make_pie();

    void make_cake();
};
