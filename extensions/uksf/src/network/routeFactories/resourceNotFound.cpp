#include "resourceNotFound.hpp"
#include <Poco/Net/HTTPResponse.h>
#include <Poco/DynamicStruct.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>

void resourceNotFound::handleRequest(Poco::Net::HTTPServerRequest & request, Poco::Net::HTTPServerResponse & response) {
    response.setStatus(Poco::Net::HTTPResponse::HTTP_NOT_FOUND);
    response.setReason(Poco::Net::HTTPResponse::HTTP_REASON_NOT_FOUND);
    response.setContentType("application/json; charset=utf-8");

    Poco::DynamicStruct error;
    error.insert("error", "Resource not found");
    error.insert("path", request.getURI());
    std::ostream& outputStream = response.send();
    outputStream << error.toString();
    outputStream.flush();
}
