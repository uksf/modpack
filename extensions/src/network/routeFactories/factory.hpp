#pragma once
#include <string>

class IFactory;

class factory {
public:
    static IFactory* createResourceFactory(std::string&);

private:
    factory() {};

};
