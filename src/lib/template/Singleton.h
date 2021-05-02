//
// Created by yangheechan on 2021-04-23.
//

#ifndef PEVIEW_SINGLETON_H
#define PEVIEW_SINGLETON_H

template<typename T>
class Singleton {
public:
    static T& instance();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton) = delete;

protected:
    struct token { };
    Singleton() { }
};

#include <memory>
template<typename T>
T& Singleton<T>::instance()
{
    static const std::unique_ptr<T> instance{new T{token{}}};
    return *instance;
}

#endif //PEVIEW_SINGLETON_H
