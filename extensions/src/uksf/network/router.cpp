#include "router.hpp"
#include <string>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/URI.h>
#include <Poco/Net/HTTPServerRequest.h>
#include "routeFactories/resourceNotFound.hpp"
#include "routeFactories/IFactory.hpp"
#include "routeFactories/factory.hpp"

class defaultRequestHandler;

router::router() {
    init();
}

void router::init() {
    addRoute("/server", "server");
    addRoute("/server/stop", "server/stop");
}

Poco::Net::HTTPRequestHandler * router::createRequestHandler(const Poco::Net::HTTPServerRequest & request) {
    return getResource(request.getURI());
}

Poco::Net::HTTPRequestHandler * router::getResource(const std::string & route) {
    Poco::URI uri = Poco::URI(route);
    auto factoryIndex = routingTable.find(uri.getPath());
    if (factoryIndex == routingTable.end()) {
        return new resourceNotFound();
    }
    IFactory * factory = factory::createResourceFactory(factoryIndex->second);
    return factory->createResource();
}

void router::addRoute(const std::string & route, const std::string & factory) {
    routingTable[route] = factory;
}
