#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <vector>
#include <iostream>

typedef std::vector< std::pair<std::string, int> > vector_pair;

class BitcoinExchange {
private:
    vector_pair _requestData;
public:
    void    loadRequestFile(const char *fileName);

    // display method for the file in key - value way.
    void    displayRequest();
};


#endif /* BITCOINEXCHANGE_HPP */
