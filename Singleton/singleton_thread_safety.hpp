#ifndef SINGLETON_THREAD_SAFETY_HPP
#define SINGLETON_THREAD_SAFETY_HPP
#include <iostream>
#include <mutex>

namespace SingletonThreadSafety
{
    class DBConfig
    {
    public:
        volatile static DBConfig* Instance();
        static void DelInstance();

        DBConfig(const DBConfig&) = delete;
        DBConfig& operator=(const DBConfig&) = delete;
    private:
        DBConfig()
        {
            std::cout << "DBConfig()" << std::endl;
        }

        ~DBConfig()
        {
            std::cout << "~DBConfig()" << std::endl;
        }

    private:
        // 防止“指针被 new 出来以后，对象还未被初始化，导致其它线程调用未初始化的对象”
        volatile static DBConfig* config_;
        static std::mutex mutex_;
    };

    // 懒汉模式
    volatile DBConfig* DBConfig::config_ = nullptr;
    std::mutex DBConfig::mutex_;

    volatile DBConfig* DBConfig::Instance()
    {
        if (config_ == nullptr)
        {
            std::lock_guard<std::mutex> lock(mutex_);
            if (config_ == nullptr)
                config_ = new DBConfig();
        }

        return config_;
    }

    // 如何保证内存被释放时，没有成员函数正在被执行？
    void DBConfig::DelInstance()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (config_)
        {
            delete config_;
            config_ = nullptr;
        }
    }
};


#endif