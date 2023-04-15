#ifndef BUILDER2_HPP
#define BUILDER2_HPP
#include <iostream>
#include <memory>

class Computer {
public:
    void set_cpu(std::string cpu) { cpu_ = cpu; }
    void set_ram(std::string ram) { ram_ = ram; }
    void set_video_card(std::string video_card) { video_card_ = video_card; }

    std::string cpu() const { return cpu_; }
    std::string ram() const  { return ram_; }
    std::string video_card() const { return video_card_; }
private:
    std::string cpu_;
    std::string ram_;
    std::string video_card_;
};

class Builder {
public:
    virtual ~Builder() {}

    virtual void BuildCpu() = 0;
    virtual void BuildRam() = 0;
    virtual void BuildVideoCard() = 0;
    virtual std::shared_ptr<Computer> GetComputer() = 0;
};

class ThinkPadBuilder : public Builder {
public:
    ThinkPadBuilder() {
        computer_ptr_ = std::make_shared<Computer>();
    }

    ~ThinkPadBuilder() {
    }

    void BuildCpu() override {
        computer_ptr_->set_cpu("i5-6200U");
    }

    void BuildRam() override {
        computer_ptr_->set_ram("DDR5");
    }

    void BuildVideoCard() override {
        computer_ptr_->set_video_card("NVIDIA Geforce 920MX");
    }

    std::shared_ptr<Computer> GetComputer() override
    {
        return computer_ptr_;
    }

private:
    std::shared_ptr<Computer> computer_ptr_;
};

class Direcror
{
public:
     std::shared_ptr<Computer> Build(Builder* builder)
    {
        if (builder == nullptr)
            throw "builder can't be nullptr!";

        builder->BuildCpu();
        builder->BuildRam();
        builder->BuildVideoCard();

        return builder->GetComputer();
    }
};

#endif