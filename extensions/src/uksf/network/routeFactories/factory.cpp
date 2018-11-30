#include "factory.hpp"
#include "serverFactory.hpp"
#include "stopFactory.hpp"

IFactory * factory::createResourceFactory(std::string & route) {
    IFactory * factory = nullptr;
    if (route == "server") {
        return new serverFactory();
    } else if (route == "stop") {
        return new stopFactory();
    }

    return factory;
}
