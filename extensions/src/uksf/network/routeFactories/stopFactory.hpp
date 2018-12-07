#pragma once

#include "IFactory.hpp"
#include "resources/stop.hpp"

class stopFactory : public IFactory {
    Poco::Net::HTTPRequestHandler * createResource() override {
        const auto resource = new resources::stop();
        return resource;
    }
};