#include "serverFactory.hpp"
#include "resources/server.hpp"

Poco::Net::HTTPRequestHandler * serverFactory::createResource() {
    const auto resource = new resources::server();
    return resource;
}
