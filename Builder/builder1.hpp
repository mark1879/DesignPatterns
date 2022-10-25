#ifndef BUILDER1_HPP
#define BUILDER1_HPP

#include <iostream>
#include <vector>

using namespace std;

/**
 * It makes sense to use the Builder pattern only when your products are quite
 * complex and require extensive configuration.
 *
 * Unlike in other creational patterns, different concrete builders can produce
 * unrelated products. In other words, results of various builders may not
 * always follow the same interface.
 */
class Product {
public:
    void ListParts() const {
        cout << "Product parts: ";

        for (size_t i = 0; i < parts_.size(); i++) {
            if(parts_[i] == parts_.back()) {
                std::cout << parts_[i];
            } else {
                std::cout << parts_[i] << ", ";
            }
        }

        cout << "\n\n"; 
    }

public:
    std::vector<std::string> parts_;
};

/**
 * The Builder interface specifies methods for creating the different parts of
 * the Product objects.
 */
class Builder{
public:
    virtual ~Builder() {}
    virtual void ProducePartA() const =0;
    virtual void ProducePartB() const =0;
    virtual void ProducePartC() const =0;
};

/**
 * The Concrete Builder classes follow the Builder interface and provide
 * specific implementations of the building steps. Your program may have several
 * variations of Builders, implemented differently.
 */
class ConcreteBuilder : public Builder {
private:
    Product* product;

public:
    /**
     * A fresh builder instance should contain a blank product object, which is
     * used in further assembly.
     */
    ConcreteBuilder(){
        this->Reset();
    }

    ~ConcreteBuilder(){
        delete product;
    }

    void Reset(){
        this->product = new Product();
    }

    /**
     * All production steps work with the same product instance.
     */
    void ProducePartA() const override {
        this->product->parts_.push_back("PartA");
    }

    void ProducePartB()const override{
        this->product->parts_.push_back("PartB");
    }

    void ProducePartC()const override{
        this->product->parts_.push_back("PartC");
    }

    /**
     * Please be careful here with the memory ownership. Once you call
     * GetProduct the user of this function is responsable to release this
     * memory. Here could be a better option to use smart pointers to avoid
     * memory leaks
     */
    Product* GetProduct() {
        Product* result= this->product;
        this->Reset();
        return result;
    }
};


/**
 * The Director is only responsible for executing the building steps in a
 * particular sequence. It is helpful when producing products according to a
 * specific order or configuration. Strictly speaking, the Director class is
 * optional, since the client can control builders directly.
 */
class Director{
private:
    Builder* builder;

public:
    void set_builder(Builder* builder){
        this->builder=builder;
    }

    void BuildMinimalViableProduct(){
        this->builder->ProducePartA();
    }
    
    void BuildFullFeaturedProduct(){
        this->builder->ProducePartA();
        this->builder->ProducePartB();
        this->builder->ProducePartC();
    }
};

void ClientCode(Director& director)
{
    ConcreteBuilder* builder = new ConcreteBuilder();
    director.set_builder(builder);
    cout << "Standard basic product:\n"; 
    director.BuildMinimalViableProduct();
    
    Product* p= builder->GetProduct();
    p->ListParts();
    delete p;

    cout << "Standard full featured product:\n"; 
    director.BuildFullFeaturedProduct();

    p= builder->GetProduct();
    p->ListParts();
    delete p;

    // Remember, the Builder pattern can be used without a Director class.
    cout << "Custom product:\n";
    builder->ProducePartA();
    builder->ProducePartC();
    p=builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;
}

#endif