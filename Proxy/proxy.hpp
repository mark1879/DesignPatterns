#ifndef PROXY_HPP
#define PROXY_HPP
#include <iostream>
#include <chrono>

class Cache
{
public:
    Cache() {}
    ~Cache() {}
};

class Subject 
{
public:
    virtual ~Subject() {}
    virtual void Request(Cache& cache) = 0;
};

class RealSubject : public Subject
{
public:
    void Request(Cache& cache) override
    {
        // acquire real-time info
    }
};

class Proxy : public Subject
{
public:
    Proxy()
        : real_subject_(new RealSubject())
        , cache_time_(0)
    {}

    ~Proxy()
    {
        delete real_subject_;
        real_subject_ = nullptr;
    }

    // 案例：比如获取服务器信息，限时内可返回
    // 缓存，超时则重新获取
    void Request(Cache& cache) override
    {
        std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	    long long current_time = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();

        if (current_time - cache_time_ <= 2000)
        {
            cache = cache_;
        }
        else
        {   
            if (real_subject_)
            {
                real_subject_->Request(cache_);
                cache_time_ = current_time;
            }
        }
    }
private:
    Subject* real_subject_;
    Cache cache_;
    long long cache_time_;
};

#endif