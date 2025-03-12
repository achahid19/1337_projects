#include "BitcoinExchange.hpp"

// c++98 does not support this methods.
static inline std::vector<std::string> split(std::string& str, const std::string delimiters);
static inline void trim(std::string& input);

bool	isNumber(std::string &n) {
	bool	isNum = true;

	trim(n);
	for (std::string::iterator it = n.begin(); it != n.end(); it++) {
		if (it == n.begin() && *it == '-') continue;
		if (isdigit(*it) == false) return false;
	}
	return isNum;
}
// Methods
void    BitcoinExchange::executeRequest(const char *fileName) {
	std::ifstream							inputFile(fileName);
	std::string								request, key;
	int										value, month, day;
	std::vector<std::string>				dateCheck, key_value;
	std::map<std::string, double>::iterator findDate, it;

	// file checking
	if (!inputFile) throw std::runtime_error("Error: file not found!");
	std::getline(inputFile, request, '\n'); // skip the first line.
	if (request.empty()) throw std::runtime_error("Error: Empty file");
	request.clear();

	this->loadBtcRates();
	while(std::getline(inputFile, request, '\n')) {
		key_value = split(request, "|");

		if (key_value.size() != 2 || isNumber(key_value[1]) == false) {
			std::cerr <<  "Error: bad input -> " << request << std::endl;
			goto here;
		};
		trim(key_value[0]);

		// load key-value
		key = key_value[0];
		value = std::atoi(key_value[1].c_str());

		if (value < 0) {
			std::cerr << "Error: not a positive number!" << std::endl;
			goto here;
		}
		else if(value > 1000) {
			std::cerr << "Error: too large number!" << std::endl;
			goto here;
		}

		// parse the date
		dateCheck = split(key, "-");

		// check size of containers + size of strings (date format -> year-month-day)
		if (dateCheck.size() != 3 || dateCheck[0].size() != 4
			|| dateCheck[1].size() != 2 || dateCheck[2].size() != 2) {
			std::cerr <<  "Error: bad input -> " << request << std::endl;
			goto here;
		}
		month = atoi(dateCheck[1].c_str());
		day = atoi(dateCheck[2].c_str());
		if (month > 12 || month < 0) {
			std::cerr <<  "Error: bad input -> " << request << std::endl;
			goto here;
		}
		if (day > 31 || day < 0) {
			std::cerr <<  "Error: bad input -> " << request << std::endl;
			goto here;
		}
			
		findDate = _bitcoinRates.find(key);
		if (findDate != _bitcoinRates.end()) {
			std::cout << key << " => " << value << " = ";
			std::cout << std::fixed << std::setprecision(2) << value * findDate->second << std::endl;
		}
		else {
			// find on the map the closet date, use the lower date not the upper
			it = _bitcoinRates.lower_bound(key);

			if (it != _bitcoinRates.begin()) it--;
			std::cout << it->first << " => " << value << " = ";
			std::cout << std::fixed << std::setprecision(2) << value * it->second << std::endl;
		}
here:	request.clear();
	}
}

void	BitcoinExchange::loadBtcRates() {
	std::ifstream	csvFile("data.csv");
	std::string		row;
	
	if (!csvFile) throw std::runtime_error("Error: Btc rates DB not found");
	getline(csvFile, row, '\n'), row.clear();
	while (getline(csvFile, row, '\n')) {
		std::vector<std::string> key_value = split(row, ",");

		_bitcoinRates.insert(
			make_pair(key_value[0], std::atof(key_value[1].c_str()))
		);
		row.clear();
	}
}

void	BitcoinExchange::displayBtcRates() {
	for (std::map<std::string, double>::iterator it = _bitcoinRates.begin(); it != _bitcoinRates.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void	BitcoinExchange::getBtc(std::string key) {
	std::map<std::string, double>::iterator it = _bitcoinRates.find(key);

	if (it != _bitcoinRates.end())
		std::cerr << "Found Date: " << it->first << " Value: " << it->second << std::endl;
	else
		std::cerr << "Not found!" << std::endl;
}

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
