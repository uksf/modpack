#pragma once
#include <Poco/Net/HTTPRequestHandler.h>
#include <list>
#include <Poco/URI.h>
#include "Poco/JSON/Object.h"
#include "../../exception.hpp"

namespace resources {
    class abstractResource : public Poco::Net::HTTPRequestHandler {
    public:
        abstractResource();
        ~abstractResource() override;
        void handleRequest(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&) override;

    protected:
        virtual void handle_get(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);
        virtual void handle_put(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);
        virtual void handle_post(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);
        virtual void handle_delete(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);
        virtual void handle_options(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);
        virtual void handleHttpHeaders(Poco::Net::HTTPServerRequest&, Poco::Net::HTTPServerResponse&);
        Poco::JSON::Object::Ptr getJsonAttributesSectionObject(const std::string&);
        void assertPayloadAttributes(const Poco::JSON::Object::Ptr&, const std::list<std::string>&);
        void handleHttpStatusCode(int statusCode, Poco::Net::HTTPServerResponse&);
        std::string getUrl(const std::string& fragment);
        std::string toJson(const exception&);
        std::string getQueryParameter(const std::string&);

    private:
        std::string baseUrl;
        std::string requestURI;
        std::string requestHost;
        Poco::URI::QueryParameters queryStringParameters;
    };
}
