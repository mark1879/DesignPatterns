#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

namespace AbstractFactory
{
    class ProductOffice
    {
    public:
        virtual ~ProductOffice() {}
        virtual void Work() = 0;
    };

    class ProductOfficeA : public ProductOffice
    {
    public:
        ProductOfficeA(std::string name){}
        ~ProductOfficeA(){}

        void Work() override
        {}
    };

    class ProductOfficeB : public ProductOffice
    {
    public:
        ProductOfficeB(std::string name, size_t width, size_t height){}
        ~ProductOfficeB(){}

        void Work() override
        {}
    };

    class ProductHome
    {
    public:
        virtual ~ProductHome() {}
        virtual void Work() = 0;
    };

    class ProductHomeA : public ProductHome
    {
    public:
        ProductHomeA(std::string name){}
        ~ProductHomeA(){}

        void Work() override
        {}
    };

    class ProductHomeB : public ProductHome
    {
    public:
        ProductHomeB(std::string name, size_t width, size_t height){}
        ~ProductHomeB(){}

        void Work() override
        {}
    };

    class Factory
    {
    public:
        virtual ~Factory() {}
        virtual ProductHome* CreateProducHome() = 0;
        virtual ProductOffice* CreateProductOffice() = 0;
    };

    class FactoryA : public Factory
    {
    public:
        ProductHome* CreateProducHome()
        {
            return new ProductHomeA("ProductHomeA");
        }

        ProductOffice* CreateProductOffice()
        {
            return new ProductOfficeA("ProductOfficeA");
        }
    };

    class FactoryB : public Factory
    {
    public:
        ProductHome* CreateProducHome()
        {
            return new ProductHomeB("ProductHomeB", 100, 100);
        }

        ProductOffice* CreateProductOffice()
        {
            return new ProductOfficeB("ProductOfficeB", 100, 100);
        }
    };
};
#endif