#pragma once

#include "IFactory.hpp"

class serverFactory : public IFactory {
public:
    Poco::Net::HTTPRequestHandler * createResource() override;
};
