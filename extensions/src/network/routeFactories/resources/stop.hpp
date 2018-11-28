#pragma once
#include "abstractResource.hpp"

namespace resources {
    class stop : public abstractResource {
    public:
        stop();
        ~stop() override;

    protected:
        void handle_get(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&) override;
        void handle_options(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&) override;
    };
}
