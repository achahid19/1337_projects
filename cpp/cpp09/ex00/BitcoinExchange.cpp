#include "BitcoinExchange.hpp"

// c++98 does not support this methods - split & trim.
static inline std::string*				split( std::string& str, const std::string delimiters);
static inline void						trim( std::string& input );
static inline bool						isNumber( std::string &n );
static inline void						inputFileChecking( std::ifstream &inputFile, std::string &request );
static inline bool						checkValue( int &value, std::string& request );
static inline bool						checkDate( std::string &date, std::string &request );
static inline size_t					gridSize(std::string *ptr, size_t maxSize);

// Canonical form
BitcoinExchange::BitcoinExchange( void ) {};
BitcoinExchange::BitcoinExchange( BitcoinExchange& copy ) { *this=(copy); };
BitcoinExchange&	BitcoinExchange::operator=( BitcoinExchange& copy ) {
	(void)copy; return *this;
};
BitcoinExchange::~BitcoinExchange( void ) {};

// Methods
void    BitcoinExchange::executeRequest(const char *fileName) {
	std::ifstream							inputFile(fileName);
	std::string								request, key;
	int										value;
	std::string								*key_value = NULL;
	
	inputFileChecking(inputFile, request);
	this->loadBtcRates();
	while(std::getline(inputFile, request, '\n')) {
		key_value = ::split(request, "|");
		if (gridSize(key_value, 3) != 2 || ::isNumber(key_value[1]) == false) {
			std::cerr <<  "Error: bad input -> " << request << std::endl;
			goto here;
		};
		::trim(key_value[0]);
		key = key_value[0];
		value = std::atoi(key_value[1].c_str());
		if (::checkDate(key, request) && ::checkValue(value, request))
			BitcoinExchange::findBtcRates(key, value);
here:	request.clear();
		delete [] key_value;
	}
}

// private-methods
void	BitcoinExchange::loadBtcRates() {
	std::ifstream	csvFile("./data.csv");
	std::string		row;
	
	if (!csvFile) throw std::runtime_error("Error: Btc rates DB not found");
	std::getline(csvFile, row, '\n'), row.clear();
	while (std::getline(csvFile, row, '\n')) {
		std::string *key_value = split(row, ",");

		_bitcoinRates.insert(
			std::make_pair(key_value[0], std::atof(key_value[1].c_str()))
		);
		row.clear();
		delete [] key_value;
	}
}

void	BitcoinExchange::findBtcRates( std::string &key, int &value ) const {
	std::map<std::string, double>::const_iterator	it;

	it = _bitcoinRates.find(key);
	if (it != _bitcoinRates.end()) {
		std::cout << key << " => " << value << " = ";
		std::cout << std::fixed << std::setprecision(2) << value * it->second << std::endl;
	}
	else {
		// find on the map the closet date, use the lower date not the upper
		it = _bitcoinRates.lower_bound(key);

		if (it != _bitcoinRates.begin()) it--;
		std::cout << it->first << " => " << value << " = ";
		std::cout << std::fixed << std::setprecision(2) << value * it->second << std::endl;
	}
}

// public-methods

void	BitcoinExchange::displayBtcRates() const {
	for (	
			std::map<std::string, double>::const_iterator it = _bitcoinRates.begin();
			it != _bitcoinRates.end();
			it++
		) {
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void	BitcoinExchange::getBtc(std::string key) const {
	std::map<std::string, double>::const_iterator it = _bitcoinRates.find(key);

	if (it != _bitcoinRates.end())
		std::cerr << "Found Date: " << it->first << " Value: " << it->second << std::endl;
	else
		std::cerr << "Not found!" << std::endl;
}

// hepler functions

static inline std::string*	split(std::string& str, const std::string delimiters) {
	std::string					*tokens = new std::string [5];
	size_t						index = 0;
	size_t 						start = 0;
	size_t 						end = str.find_first_of(delimiters);

	while (end != std::string::npos) {
		if (end != start) { // Avoid empty tokens
			tokens[index++] = str.substr(start, end - start);
			if (index == 5) return tokens;
		}
		start = end + 1;
		end = str.find_first_of(delimiters, start);
	}

	if (start < str.length()) {
		tokens[index] = (str.substr(start));
	}

	return tokens;
}

static inline void trim(std::string& input) {
	// Trim trainling spaces
	std::string::iterator	ite = input.end() - 1;
	std::string::iterator	it = input.begin() - 1;

	while (ite != it && *ite == ' ') {
		input.erase(ite);
		ite--;
	}
	// Trim leading spaces
	size_t start = input.find_first_not_of(' ');
	if (start != std::string::npos) {
		input.erase(0, start);
	}
}

static inline bool	isNumber(std::string &n) {
	bool	isNum = true;

	trim(n);
	for (std::string::iterator it = n.begin(); it != n.end(); it++) {
		if (it == n.begin() && *it == '-') continue;
		if (isdigit(*it) == false) return false;
	}
	return isNum;
}

static inline void	inputFileChecking(std::ifstream &inputFile, std::string &request) {
	if (!inputFile) throw std::runtime_error("Error: file not found!");
	std::getline(inputFile, request, '\n');
	if (request.empty()) throw std::runtime_error("Error: Empty file");
	else if (request.find("Date | Value") == std::string::npos)
		throw std::runtime_error("Error: Invalid Format!");
	request.clear();
}

static inline bool	checkValue(int &value, std::string& request) {
	bool status = (value <= 0 || value > 1000) ? false : true;

	if (value == 0) std::cerr << "Error: bad input -> " << request  << std::endl;
	else if (value < 0) std::cerr << "Error: not a positive number!" << std::endl;
	else if(value > 1000) std::cerr << "Error: too large number!" << std::endl;

	return status;
}

static inline bool	checkDate(std::string &key, std::string &request) {
	std::string*	dateCheck = split(key, "-");
	int							month, day;

	// (date format -> year-month-day)
	if (gridSize(dateCheck, 4) != 3 || dateCheck[0].size() != 4
		|| dateCheck[1].size() != 2 || dateCheck[2].size() != 2) {
		goto INV_FORMAT;
	}
	month = std::atoi(dateCheck[1].c_str());
	day = std::atoi(dateCheck[2].c_str());
	if ( ( month > 12 || month < 0 )
		|| ( day > 31 || day < 0 ) ) {
		goto INV_FORMAT;
	}
	return (delete [] dateCheck, true);

INV_FORMAT: {
	std::cerr <<  "Error: bad input -> " << request << std::endl; 
	return (delete [] dateCheck ,false);
	}
}

static inline size_t	gridSize(std::string *ptr, size_t maxSize) {
	size_t s = 0;

	if (ptr == NULL || maxSize == 0) return s;
	while (!ptr->empty()) {
		s++;
		if (s == maxSize) break ;
		ptr++;
	}
	return s;
}
