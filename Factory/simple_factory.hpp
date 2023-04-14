#ifndef SIMPLE_FACTORY_HPP
#define SIMPLE_FACTORY_HPP
#include <iostream>

namespace SimpleFactory
{
    enum class ProductType
    {
        kA,
        kB,
    };

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


    class SimpleMessageFactory
    {
    public:
        static Product* CreateProduc(ProductType type)
        {
            if (type == ProductType::kA)
            {
                return new ProductA("ProductA");
            }
            else if (type == ProductType::kB)
            {
                return new ProductB("ProductB", 100, 100);
            }

            return nullptr;
        }
    };
};
#endif 