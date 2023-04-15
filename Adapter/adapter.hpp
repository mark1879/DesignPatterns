#ifndef ADAPTER_HPP
#define ADAPTER_HPP
#include <iostream>
#include <memory>

// 场景：外部需要按照 Target 中的接口来调用 Adaptee 的功能

class Target
{
public:
    virtual ~Target() = default;

    virtual std::string Request() const
    {
        return "Target: The default target's behavior.";
    }
};

class Adaptee
{
public:
    std::string SpecificRequest() const 
    {
        return "Adaptee: specific request."; 
    }
};

// 也可以根据 Adaptee 命名 Adapter，而不传 Adaptee 的指针
class Adapter : public Target
{
private:
    std::shared_ptr<Adaptee> adaptee_ptr_;

public:
    Adapter(std::shared_ptr<Adaptee> adaptee) : adaptee_ptr_(adaptee)
    {}

    ~Adapter()
    {}

    std::string Request() const override
    {
        return adaptee_ptr_->SpecificRequest();
    }
};

#endif