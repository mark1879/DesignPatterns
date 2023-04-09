#include "singleton.hpp"
#include "singleton_thread_safety.hpp"
#include "singleton_in_cpp11.hpp"
#include <iostream>
#include <thread>

void TestSingleton()
{
    std::cout << "test_singleton..." << std::endl;

    Singleton::DBConfig* db_config = Singleton::DBConfig::Instance();
    db_config->DelInstance();

    // 不允许“独立创建对象”
    // Singleton::DBConfig config;
    // Singleton::DBConfig* config_ptr = new Singleton::DBConfig();

    // 不允许“拷贝构造”
    // Singleton::DBConfig config = *Singleton::DBConfig::Instance();

    // 不允许“赋值拷贝”
    // config = *config_ptr;

    // 不允许“赋值拷贝”
    // Singleton::DBConfig* config_ptr1 = Singleton::DBConfig::Instance();
    // Singleton::DBConfig* config_ptr2 = Singleton::DBConfig::Instance();
    // *config_ptr1 = *config_ptr2;

}

void func_create()
{
    for (int i = 0; i < 10; i++)
        SingletonThreadSafety::DBConfig::Instance();
}

void func_release()
{
    for (int i = 0; i < 10; i++)
        SingletonThreadSafety::DBConfig::DelInstance();
}

void TestSingletonThreadSafety()
{
    std::cout << "test_singleton_thread_safety..." << std::endl;

    for (int i = 0; i < 10; i++)
    {
        auto th = std::thread(func_create);
        th.join();
    }

    for (int i = 0; i < 10; i++)
    {
        auto th = std::thread(func_release);
        th.join();
    }
}

void func1()
{
     for (int i = 0; i < 10; i++)
        SingletonInCpp11::DBConfig::Instance();
}

void TestSingletonInCpp11()
{
    std::cout << "test_singleton_in_cpp11..." << std::endl;

    for (int i = 0; i < 10; i++)
    {
        auto th = std::thread(func1);
        th.join();
    }
}


int main()
{
    TestSingleton();
    TestSingletonThreadSafety();
    TestSingletonInCpp11();

    std::cout << "test done!" << std::endl;

    return 0;
}