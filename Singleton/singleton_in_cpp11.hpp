#ifndef SINGLETON_IN_CPP11_HPP
#define SINGLETON_IN_CPP11_HPP
#include <iostream>

namespace SingletonInCpp11
{
    class DBConfig {
    public:
        static DBConfig& Instance() {
            static DBConfig config;     // Guaranteed to be destroyed and instantiated on first use
            return config;
        }

        DBConfig(const DBConfig&) = delete;
        DBConfig& operator=(const DBConfig&) = delete;
    private:
        DBConfig() {
            std::cout << "DBConfig()" << std::endl;
        }

    public:
        ~DBConfig() {
            std::cout << "~DBConfig()" << std::endl;
        }
    };
};

#endif