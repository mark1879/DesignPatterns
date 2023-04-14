#ifndef GENERAL_FACTORY_HPP
#define GENERAL_FACTORY_HPP

namespace GeneralFactory
{
    class Product
    {
    public:
        virtual ~Product() {}
        virtual void Work() = 0;
    };

    class ProductA : public Product
    {
    public:
        ProductA(std::string name) {}
        ~ProductA() {}
        void Work() override
        {}
    };

    class ProductB : public Product
    {
    public:
        ProductB(std::string name, size_t width, size_t heiht) {}
        ~ProductB() {}
        void Work() override
        {}
    };

    class Factory
    {
    public:
        virtual ~Factory() {}
        virtual Product* CreateProduct() = 0;
    };

    class FactoryA : public Factory
    {
    public:
        Product* CreateProduct() override
        {
            return new ProductA("ProductA");
        }
    };

    class FactoryB : public Factory
    {
    public:
        Product* CreateProduct() override
        {
            return new ProductB("ProductB", 100, 100);
        }
    };
};
#endif