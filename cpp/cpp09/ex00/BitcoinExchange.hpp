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
	void	findBtcRates( std::string &key, int &value ) const;

public:
    void    executeRequest(const char *fileName);

    // display method for the file in key - value way.
	void	displayBtcRates() const;
	void	getBtc(std::string key) const;
};


#endif /* BITCOINEXCHANGE_HPP */
