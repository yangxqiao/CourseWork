#include "SrcMain.h"
#include "stdafx.h"
#include "Server.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

// reference: https://github.com/microsoft/cpprestsdk/blob/master/Release/samples/BlackJack/BlackJack_Server/BlackJack_Server.cpp

std::unique_ptr<Server> g_httpDealer;

void on_initialize(const string_t& address, const std::string filename)
{
    uri_builder uri(address);
    auto addr = uri.to_uri().to_string();
    g_httpDealer = std::make_unique<Server>(addr, filename);
    
    g_httpDealer->open().wait();
    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;
}

void on_shutdown()
{
    g_httpDealer->close().wait();
}

void ProcessCommandArgs(int argc, const char* argv[])
{
    utility::string_t port = U("12345");
    utility::string_t address = U("http://localhost:");
    address.append(port);
    
    if(argc >= 2)
    {
        std::string filename = argv[1];
        on_initialize(address, filename);
        while(true){}
    }
}
