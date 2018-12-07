#pragma once

#include "IFactory.hpp"
#include "resources/server.hpp"

class serverFactory : public IFactory {
    Poco::Net::HTTPRequestHandler * createResource() override {
        const auto resource = new resources::server();
        return resource;
    }
};