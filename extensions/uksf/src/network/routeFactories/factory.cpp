#include "factory.hpp"
#include "serverFactory.hpp"

IFactory * factory::createResourceFactory(std::string & route) {
    IFactory * factory = nullptr;
    if (route == "server") {
        return new serverFactory();
    }

    return factory;
}
