#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include <iostream>
#include <list>
#include <memory>

class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void Update(const std::string& message_from_subject) = 0;
};

class ISubject
{
public:
    virtual ~ISubject() = default;
    virtual void Attach(std::shared_ptr<IObserver> observer) = 0;
    virtual void Detach(std::shared_ptr<IObserver> observer) = 0;
    virtual void Notify() = 0;
};

class Subject : public ISubject 
{
public:
    virtual ~Subject() { }

    void Attach(std::shared_ptr<IObserver> observer) override 
    {
        list_observer_.push_back(observer);
    }

    void Detach(std::shared_ptr<IObserver> observer) override 
    {
        list_observer_.remove(observer);
    }

    void Notify() override {
        for (auto it : list_observer_)
            it->Update(message_);
    }

    void CreateMessage(std::string message) {
        message_ = message;
        Notify();
    }

 private:
    std::list<std::shared_ptr<IObserver>> list_observer_;
    std::string message_;
};


class Observer : public IObserver
{
public:
    Observer()
    {}

    virtual ~Observer() 
    {}

    void Update(const std::string &message_from_subject) override
    {}
};

#endif