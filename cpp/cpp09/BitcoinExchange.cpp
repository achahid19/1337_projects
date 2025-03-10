#include "BitcoinExchange.hpp"

// c++98 does not support this methods.
static inline std::vector<std::string> split(std::string& str, const std::string delimiters);
static inline void trim(std::string& input);

void    BitcoinExchange::loadRequestFile(const char *fileName) {
    std::ifstream	inputFile(fileName);
	std::string		request;

	// now that we have the user request, parse it and load to a vector of pairs <string, int>.
    std::getline(inputFile, request, '\n'), request.clear();
	while(std::getline(inputFile, request, '\n')) {
		// extract the key, value parse them, all okay? push to the vector.
		std::vector<std::string> key_value = split(request, "|");

		 // size != 2 -> format error.
		if (key_value.size() != 2) throw std::runtime_error("Error: Format error!");
		for (std::vector<std::string>::iterator it = key_value.begin(); it != key_value.end(); it++)
            trim(*it);

		// parse value
		if (key_value[1][0] != '-' && isdigit(key_value[1][0]) == false)
			throw std::runtime_error("Error: wrong value!");

		// load key-value
		std::string key = key_value[0];
		const int	value = std::atoi(key_value[1].c_str());

        if (value < 0) throw std::out_of_range("Error: not a positive number!");
		else if(value > 1000) throw std::out_of_range("Error: too large number!");

		// parse the date
        std::vector<std::string> dateCheck = split(key, "-");

        // check size of containers + size of strings (date format -> year-month-day)
        if (dateCheck.size() != 3 || dateCheck[0].size() != 4
            || dateCheck[1].size() != 2 || dateCheck[2].size() != 2) 
            throw std::logic_error(key);
        int month = atoi(dateCheck[1].c_str());
        int day = atoi(dateCheck[2].c_str());
        if (month > 12 || month < 0) throw std::logic_error(key);
        if (day > 31 || day < 0) throw std::logic_error(key);
        
		// push the pair into the vector.
		_requestData.push_back(make_pair(key, value));
		request.clear();
	}
}

void    BitcoinExchange::displayRequest()  {
    for (vector_pair::iterator it = _requestData.begin(); it != _requestData.end(); it++) {
    	std::cout << "date: " << it->first << " amount: " << it->second << std::endl;
	}
};

static inline std::vector<std::string> split(std::string& str, const std::string delimiters) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find_first_of(delimiters);

    while (end != std::string::npos) {
        if (end != start) { // Avoid empty tokens
            tokens.push_back(str.substr(start, end - start));
        }
        start = end + 1;
        end = str.find_first_of(delimiters, start);
    }

    // Add the last token
    if (start < str.length()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

static inline void trim(std::string& input) {
	// Trim trailing spaces
	while (!input.empty() && input.back() == ' ') {
		input.pop_back();
	}
	// Trim leading spaces
	size_t start = input.find_first_not_of(' ');
	if (start != std::string::npos) {
		input.erase(0, start);
	}
}
