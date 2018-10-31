#include "abstractResource.hpp"
#include "Poco/JSON/Parser.h"
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include "Poco/URI.h"
#include "Poco/JSON/Object.h"

namespace resources {
    abstractResource::abstractResource() = default;
    abstractResource::~abstractResource() = default;

    void abstractResource::handleHttpHeaders(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        response.setContentType("application/json; charset=utf-8");
        if (request.getContentType() != "application/json" && request.get("Accept") != "application/json") {
            throw exception("Unsupported Media Type", "The only media type supported is application/json. Used: " + request.getContentType() + ", " + request.get("Accept"), 415);
        }

        if (request.getMethod() != Poco::Net::HTTPRequest::HTTP_GET &&
            request.getMethod() != Poco::Net::HTTPRequest::HTTP_PUT &&
            request.getMethod() != Poco::Net::HTTPRequest::HTTP_POST &&
            request.getMethod() != Poco::Net::HTTPRequest::HTTP_DELETE &&
            request.getMethod() != Poco::Net::HTTPRequest::HTTP_OPTIONS
        ) {
            throw exception("Not Implemented", "The request method is not supported by the server and cannot be handled.", 501);
        }
    }

    void abstractResource::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        try {
            handleHttpHeaders(request, response);
        } catch (exception& exception) {
            handleHttpStatusCode(exception.code(), response);

            Poco::DynamicStruct rootJsonStructure;
            Poco::Dynamic::Array errorsCollection;
            Poco::DynamicStruct error;
            Poco::DynamicStruct sourceErrorPointer;
            sourceErrorPointer.insert("pointer", requestHost + request.getURI());
            error.insert("status", exception.code());
            error.insert("type", exception.type());
            error.insert("details", exception.message());
            error.insert("source", sourceErrorPointer);
            errorsCollection.push_back(error);
            rootJsonStructure.insert("error", errorsCollection);

            std::ostream& errorStream = response.send();
            errorStream << rootJsonStructure.toString();
            errorStream.flush();
            return;
        }

        Poco::URI uri = Poco::URI(request.getURI());

        requestURI = request.getURI();
        requestHost = request.getHost();
        baseUrl = "http://" + requestHost + requestURI;
        queryStringParameters = uri.getQueryParameters();

        if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_GET) {
            this->handle_get(request, response);
            return;
        }

        if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_PUT) {
            this->handle_put(request, response);
            return;
        }

        if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_POST) {
            this->handle_post(request, response);
            return;
        }

        if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_DELETE) {
            this->handle_delete(request, response);
            return;
        }

        if (request.getMethod() == Poco::Net::HTTPRequest::HTTP_OPTIONS) {
            this->handle_options(request, response);
        }
    }

    void abstractResource::handle_get(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        handleHttpStatusCode(501, response);
        std::ostream& errorStream = response.send();
        errorStream.flush();
    }

    void abstractResource::handle_put(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        handleHttpStatusCode(501, response);
        std::ostream& errorStream = response.send();
        errorStream.flush();
    }

    void abstractResource::handle_post(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        handleHttpStatusCode(501, response);
        std::ostream& errorStream = response.send();
        errorStream.flush();
    }

    void abstractResource::handle_delete(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        handleHttpStatusCode(501, response);
        std::ostream& errorStream = response.send();
        errorStream.flush();
    }

    void abstractResource::handle_options(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) {
        response.setStatusAndReason(
            Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED,
            Poco::Net::HTTPResponse::HTTP_REASON_NOT_IMPLEMENTED
        );

        std::ostream& errorStream = response.send();
        errorStream.flush();
    }

    Poco::JSON::Object::Ptr abstractResource::getJsonAttributesSectionObject(const std::string& payload) {
        Poco::JSON::Parser jsonParser;
        Poco::Dynamic::Var parsingResult = jsonParser.parse(payload);
        auto jsonObject = parsingResult.extract<Poco::JSON::Object::Ptr>();

        if (jsonObject->isArray("data")) {
            throw exception(
                Poco::Net::HTTPResponse::HTTP_REASON_BAD_REQUEST,
                "This payload can not be represented as a collection.",
                Poco::Net::HTTPResponse::HTTP_BAD_REQUEST
            );
        }

        Poco::JSON::Object::Ptr dataObject = jsonObject->getObject("data");

        if (!dataObject->has("attributes")) {
            throw exception(
                Poco::Net::HTTPResponse::HTTP_REASON_BAD_REQUEST,
                "The payload has no an 'attributes' section.",
                Poco::Net::HTTPResponse::HTTP_BAD_REQUEST
            );
        }

        return dataObject->getObject("attributes");
    }

    void abstractResource::assertPayloadAttributes(
        const Poco::JSON::Object::Ptr& payloadObject, const std::list<std::string>& attributes) {
        for (auto const& attribute : attributes) {
            if (!payloadObject->has(attribute)) {
                throw exception(
                    Poco::Net::HTTPResponse::HTTP_REASON_BAD_REQUEST,
                    "One or more attributes are is missing at the payload.",
                    Poco::Net::HTTPResponse::HTTP_BAD_REQUEST
                );
            }
        }
    }

    void abstractResource::handleHttpStatusCode(const int statusCode, Poco::Net::HTTPServerResponse& response) {
        switch (statusCode) {
        case 200:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_OK);
            break;
        case 201:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_CREATED);
            break;
        case 202:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_ACCEPTED);
            break;
        case 204:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NO_CONTENT);
            break;
        case 205:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_RESET_CONTENT);
            break;
        case 206:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_PARTIAL_CONTENT);
            break;
        case 400:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
            break;
        case 401:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_UNAUTHORIZED);
            break;
        case 403:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_FORBIDDEN);
            break;
        case 404:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
            break;
        case 405:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_METHOD_NOT_ALLOWED);
            break;
        case 406:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_ACCEPTABLE);
            break;
        case 409:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_CONFLICT);
            break;
        case 410:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_GONE);
            break;
        case 415:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_UNSUPPORTEDMEDIATYPE);
        case 500:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_INTERNAL_SERVER_ERROR);
        case 501:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_IMPLEMENTED);
        case 503:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_SERVICE_UNAVAILABLE);
        default:
            response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
        }
    }

    std::string abstractResource::getUrl(const std::string& fragment) {
        return baseUrl + fragment;
    }

    std::string abstractResource::toJson(const exception& exception) {
        Poco::DynamicStruct rootJsonStructure;
        Poco::Dynamic::Array errorsCollection;
        Poco::DynamicStruct error;
        Poco::DynamicStruct sourceErrorPointer;
        sourceErrorPointer.insert("pointer", requestHost + requestURI);
        error.insert("status", exception.code());
        error.insert("type", exception.type());
        error.insert("details", exception.message());
        error.insert("source", sourceErrorPointer);
        errorsCollection.push_back(error);
        rootJsonStructure.insert("error", errorsCollection);

        return rootJsonStructure.toString();
    }

    std::string abstractResource::getQueryParameter(const std::string& parameterKey) {
        const auto iterator = std::find_if(queryStringParameters.begin(), queryStringParameters.end(), [&parameterKey](const std::pair<std::string, std::string>& item) {
                                         return item.first == parameterKey;
                                     }
        );

        if (iterator == queryStringParameters.end()) {
            throw exception(
                Poco::Net::HTTPResponse::HTTP_REASON_BAD_REQUEST,
                "Attribute '" + parameterKey + "' is missing at URL.",
                Poco::Net::HTTPResponse::HTTP_BAD_REQUEST
            );
        }

        return iterator->second;
    }
}
