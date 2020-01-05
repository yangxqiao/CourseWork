#ifndef Server_h
#define Server_h

#include "stdafx.h"
#include <map>
#include <vector>

using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

// reference: https://github.com/microsoft/cpprestsdk/blob/master/Release/samples/BlackJack/BlackJack_Server/Dealer.cpp
class Server{
public:
    Server(utility::string_t url, std::string filename);
    void readFile(std::string filename);
    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }
    web::json::value formJsonForId(std::map<std::string, std::vector<std::string>>::iterator it);
    web::json::value formJsonForName(std::vector<std::map<std::string, std::vector<std::string>>::iterator> allMovies);
    web::json::value formJsonNotFoundID();
    web::json::value formJsonNotFoundName();
    std::vector<std::string> Split(const std::string& str, char delim);

private:
    void handle_get(http_request message);
    std::map<std::string, std::vector<std::string>> fileInfo;
    http_listener m_listener;
};


#endif
