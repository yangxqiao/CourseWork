#include "Server.h"
#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace web;
using namespace utility;
using namespace http;
using namespace web::http::experimental::listener;

// reference: https://github.com/microsoft/cpprestsdk/blob/master/Release/samples/BlackJack/BlackJack_Server/Dealer.cpp

Server::Server(utility::string_t url, std::string filename)
:m_listener(url)
{
    readFile(filename);
    m_listener.support(methods::GET, std::bind(&Server::handle_get, this, std::placeholders::_1));
}

void Server::handle_get(http_request message)
{
    ucout << message.to_string() << std::endl;
    auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));

    std::string target = paths[1];
    
    if(target == "id")
    {
        std::string movieID = paths[2];
        auto movie = fileInfo.find(movieID);
        if(movie == fileInfo.end())
        {
            message.reply(status_codes::NotFound, formJsonNotFoundID());
        }
        else{
            message.reply(status_codes::OK, formJsonForId(movie));
        }
    }
    else if(target == "name")
    {
        std::string movieName = paths[2];
        int startPos = 0;
        while((startPos = movieName.find("%20", startPos)) != std::string::npos) {
            movieName.replace(startPos, 2, " ");
            startPos += 1;
        }
        std::vector<std::map<std::string, std::vector<std::string>>::iterator> allMovies;
        for(auto it = fileInfo.begin(); it != fileInfo.end(); ++it)
        {
            if(it->second[2] == movieName)
            {
                allMovies.emplace_back(it);
            }
        }
        
        if(allMovies.empty())
        {
            message.reply(status_codes::NotFound, formJsonNotFoundName());
        }
        else{
            message.reply(status_codes::OK, formJsonForName(allMovies));
        }
    }
}

void Server::readFile(std::string filename){
    std::ifstream ifile(filename);
    std::string line;
    getline(ifile, line);
    std::vector<std::string> info;
    
    while(getline(ifile, line))
    {
        if(line.substr(10,5) == "movie")
        {
            info = Split(line, '\t');
            fileInfo.insert(std::make_pair(info[0], info));
        }
    }
}

// reference: https://github.com/microsoft/cpprestsdk/blob/master/Release/samples/BlackJack/BlackJack_Server/messagetypes.h
// reference: https://github.com/microsoft/cpprestsdk/wiki/JSON

web::json::value Server::formJsonForId(std::map<std::string, std::vector<std::string>>::iterator it)
{
    std::vector<std::string> detailedInfo = it->second;
    web::json::value movie = web::json::value::object();
    
    std::string genresString = detailedInfo.back();
    std::vector<std::string> genresVector = Split(genresString, ',');
    web::json::value genres = web::json::value::array(genresVector.size());
    for(auto i = 0; i < genresVector.size(); i++)
    {
        genres[i] = json::value::string(U(genresVector[i]));
    }
    
    movie["Genres"] = genres;
    movie["ID"] = web::json::value::string(U(it->first));
    if(detailedInfo[7] == "\\N")
    {
        movie["Runtime"] = web::json::value::number(0);
    }
    else{
        movie["Runtime"] = web::json::value::number(std::stoi(detailedInfo[7]));
    }
    movie["Title"] = web::json::value::string(U(detailedInfo[2]));
    std::string url = "https://www.imdb.com/title/" + it->first + "/";
    movie["URL"] = web::json::value::string(url);
    if(detailedInfo[5] == "\\N")
    {
        movie["Year"] = web::json::value::number(0);
    }
    else{
        movie["Year"] = web::json::value::number(std::stoi(detailedInfo[5]));
    }
    ucout << movie << std::endl;
    return movie;
}

web::json::value Server::formJsonForName(std::vector<std::map<std::string, std::vector<std::string>>::iterator> allMovies){
    web::json::value movies = web::json::value::array(allMovies.size());
    for(unsigned int index = 0; index < allMovies.size(); index++)
    {
        std::vector<std::string> detailedInfo = allMovies[index]->second;
        web::json::value movie = web::json::value::object();
        
        std::string genresString = detailedInfo.back();
        std::vector<std::string> genresVector = Split(genresString, ',');
        web::json::value genres = web::json::value::array(genresVector.size());
        for(auto i = 0; i < genresVector.size(); i++)
        {
            genres[i] = json::value::string(U(genresVector[i]));
        }
        
        movie["Genres"] = genres;
        movie["ID"] = web::json::value::string(U(allMovies[index]->first));
        if(detailedInfo[7] == "\\N")
        {
            movie["Runtime"] = web::json::value::number(0);
        }
        else{
            movie["Runtime"] = web::json::value::number(std::stoi(detailedInfo[7]));
        }
        movie["Title"] = web::json::value::string(U(detailedInfo[2]));
        std::string url = "https://www.imdb.com/title/" + allMovies[index]->first + "/";
        movie["URL"] = web::json::value::string(url);
        if(detailedInfo[5] == "\\N")
        {
            movie["Year"] = web::json::value::number(0);
        }
        else{
            movie["Year"] = web::json::value::number(std::stoi(detailedInfo[5]));
        }
        movies[index] = movie;
    }
    return movies;
}

web::json::value Server::formJsonNotFoundID(){
    web::json::value notFound = web::json::value::object();
    notFound["Error"] = web::json::value::string(U("No movie with that ID found"));
    return notFound;
}

web::json::value Server::formJsonNotFoundName(){
    web::json::value notFound = web::json::value::object();
    notFound["Error"] = web::json::value::string(U("No movie by that name found"));
    return notFound;
}

std::vector<std::string> Server::Split(const std::string& str, char delim)
{
    std::vector<std::string> retVal;

    size_t start = 0;
    size_t delimLoc = str.find_first_of(delim, start);
    while (delimLoc != std::string::npos)
    {
        retVal.emplace_back(str.substr(start, delimLoc - start));

        start = delimLoc + 1;
        delimLoc = str.find_first_of(delim, start);
    }

    retVal.emplace_back(str.substr(start));
    return retVal;
}
