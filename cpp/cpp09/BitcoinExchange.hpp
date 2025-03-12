#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <vector>
#include <iostream>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double>	_bitcoinRates;
	
	void	loadBtcRates();

public:
    void    executeRequest(const char *fileName);

    // display method for the file in key - value way.
	void	displayBtcRates();
	void	getBtc(std::string key);
};


#endif /* BITCOINEXCHANGE_HPP */
