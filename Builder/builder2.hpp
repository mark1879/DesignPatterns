#ifndef BUILDER2_HPP
#define BUILDER2_HPP

#include <iostream>

using namespace std;

// product
class Computer {
public:
    void SetCpu(string cpu) {
        cpu_ = cpu;
    }

    void SetMainboard(string mainboard) {
        mainboard_ = mainboard;
    }

    void SetRam(string ram) {
        ram_ = ram;
    }

    void SetVideoCard(string video_card) {
        video_card_ = video_card;
    }

    string cpu() { 
        return cpu_; 
    }

    string mainboard() { 
        return mainboard_; 
    }

    string ram() {
        return ram_;
    }

    string video_card() {
        return video_card_;
    }

private:
    string cpu_;
    string mainboard_;
    string ram_;
    string video_card_;
};

class Builder {
public:
    virtual void BuildCpu() = 0;
    virtual void BuildMainboard() = 0;
    virtual void BuildRam() = 0;
    virtual void BuildVideoCard() = 0;
    virtual Computer* GetResult() = 0;
};

// ThinkPad
class ThinkPadBuilder : public Builder {
public:
    ThinkPadBuilder() {
        Reset();
    }

    ~ThinkPadBuilder() {
        delete computer_;
    }

    void BuildCpu() {
        computer_->SetCpu("i5-6200U");
    }

    void BuildMainboard() {
        computer_->SetMainboard("Intel DP55KG");
    }
    
    void BuildRam() {
        computer_->SetRam("DDR5");
    }

    void BuildVideoCard() {
        computer_->SetVideoCard("NVIDIA Geforce 920MX");
    }

    Computer* GetResult() {
        Computer* result = computer_;
        Reset();
        return result;
    }

private:
    void Reset() {
        computer_ = new Computer();
    }

private:
    Computer *computer_;
};

// Yoga
class YogaBuilder : public Builder {
public:
    YogaBuilder() {
        Reset();
    }

    ~YogaBuilder() {
        delete computer_;
    }

    void BuildCpu() {
        computer_->SetCpu("i7-7500U");
    }

    void BuildMainboard() {
        computer_->SetMainboard("Intel DP55KG");
    }
    
    void BuildRam() {
        computer_->SetRam("DDR5");
    }

    void BuildVideoCard() {
        computer_->SetVideoCard("NVIDIA GeForce 940MX");
    }

    Computer* GetResult() {
        Computer* result = computer_;
        Reset();
        return result;
    }

private:
    void Reset() {
        computer_ = new Computer();
    }

private:
    Computer *computer_;
};

class Direcror
{
public:
    void Create(Builder *builder) {
        builder->BuildCpu();
        builder->BuildMainboard();
        builder->BuildRam();
        builder->BuildVideoCard();
    }
};

#endif