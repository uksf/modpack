#pragma once
#include "abstractResource.hpp"

namespace resources {
    class server : public abstractResource {
    public:
        server();
        ~server() override;

    protected:
        void handle_get(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&) override;
        void handle_options(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&) override;
    };
}
