#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include <iostream>

// 适用于“单线程环境”
namespace Singleton
{
    class DBConfig
    {
    public:
        static DBConfig* Instance();
        static void DelInstance();

        DBConfig(const DBConfig&) = delete;
        DBConfig& operator=(const DBConfig&) = delete;

        DBConfig(DBConfig&&) = delete;
        DBConfig& operator=(DBConfig&&) = delete;
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
        static DBConfig* config_;
    };

    // 懒汉模式
    DBConfig* DBConfig::config_ = nullptr;

    DBConfig* DBConfig::Instance()
    {
        if (config_ == nullptr)
            config_ = new DBConfig();

        return config_;
    }

    void DBConfig::DelInstance()
    {
        if (config_)
        {
            delete config_;
            config_ = nullptr;
        }
    }

    // 饿汉模式，适用于创建时比较耗时的场景
    // DBConfig* DBConfig::config_ = new DBConfig();

    // DBConfig* DBConfig::Instance()
    // {
    //     return config_;
    // }
};


#endif