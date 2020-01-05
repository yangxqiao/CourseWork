#pragma once
#include <string>
#include <vector>
#include <tuple>

inline std::vector<std::string> Split(const std::string& str)
{
	const char delim = ',';
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

// TODO: ParseStr template metaprogram

// Here is the generic template version
// it is uncompilable by not actually returning anything
template <typename T>
std::tuple<T> ParseElem(const std::string& elem)
{}

// Specialization of ParseElem<int>
// Converts elem to a tuple{int}
template<>
inline std::tuple<int> ParseElem<int>(const std::string& elem){
    return std::make_tuple(std::stoi(elem));
}

// Specialization of ParseElem<std::string>
// Just makes a tuple{str} from elem
template<>
inline std::tuple<std::string> ParseElem<std::string>(const std::string& elem){
    return std::make_tuple(elem);
}

template <typename... Args>
std::tuple<Args...> ParseStr(std::vector<std::string>& paramV);

// Specialization for zero types
template<>
inline std::tuple<> ParseStr<>(std::vector<std::string>& paramV)
{
    return std::make_tuple();
}

template <typename T, typename... Args>
std::tuple<T, Args...> ParseStrHelper(std::vector<std::string>& paramV)
{
    // Get the last string from the vector
    // This assumes paramV is in reverse
    std::string elem = paramV.back();
    paramV.pop_back();
    
    // ParseElem<T>(elem) takes elem and converts it into a tuple{T},
    //
    // Then, take the remaining  elements in paramV, and pass
    // it to ParseStr for the remaining variadic types (Args..)
    // (This is the recursive step)
    //
    // Concatenate these typles with tuple_cat
    return std::tuple_cat(ParseElem<T>(elem), ParseStr<Args...>(paramV));
}

template<typename... Args>
std::tuple<Args...> ParseStr(std::vector<std::string> &paramV) {
    return ParseStrHelper<Args...>(paramV);
}
