#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <deque>
#include <iostream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <cmath>

class BitcoinExchange {
private:
	std::map<std::string, double>	_bitcoinRates;
	
	void	loadBtcRates();
	void	findBtcRates( std::string &key, double &value ) const;

public:
	// canonical form
	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange& copy );
	BitcoinExchange& operator=( BitcoinExchange& copy );
	~BitcoinExchange( void );

    void    executeRequest(const char *fileName);

    // display method for the file in key - value format.
	void	displayBtcRates() const;
	void	getBtc(std::string key) const;
};

#endif /* BITCOINEXCHANGE_HPP */
