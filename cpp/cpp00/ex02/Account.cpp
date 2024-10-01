/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:12:47 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/25 09:12:56 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * Constructor by parameter -
 */
Account::Account( int initial_deposit )  {
	this->_displayTimestamp();
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

/**
 * Constructor by default -
 */
Account::Account( void ) {
	this->_displayTimestamp();
	_amount = 0;
	_accountIndex = _nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

/**
 * Destructor -
 */
Account::~Account( void ) {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << _accountIndex << ";";
	std::cout << "amount:";
	std::cout << _amount << ";";
	std::cout << "closed" << std::endl;
}

/**
 * member functions -
 */
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:";
	std::cout << Account::getNbAccounts() << ";";
	std::cout << "total:";
	std::cout << Account::getTotalAmount() << ";";
	std::cout << "deposits:";
	std::cout << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:";
	std::cout << Account::getNbWithdrawals() << std::endl;
};

void	Account::displayStatus( void ) const {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << _accountIndex << ";";
	std::cout << "amount:";
	std::cout << this->checkAmount() << ";";
	std::cout << "deposits:";
	std::cout << _nbDeposits << ";";
	std::cout << "withdrawals:";
	std::cout << _nbWithdrawals << std::endl;
};

void	Account::makeDeposit( int deposit ) {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << _accountIndex << ";";
	std::cout << "p_amount:";
	std::cout << this->checkAmount() << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "deposit:";
	std::cout << deposit << ";";
	std::cout << "amount:";
	std::cout << this->checkAmount() << ";";
	std::cout << "nb_deposits:";
	std::cout << ++_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	this->_displayTimestamp();
	std::cout << "index:";
	std::cout << _accountIndex << ";";
	std::cout << "p_amount:";
	std::cout << this->checkAmount() << ";";
	if (this->checkAmount() < withdrawal) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:";
	std::cout << withdrawal << ";";
	std::cout << "amount:";
	std::cout << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:";
	std::cout << _nbWithdrawals << std::endl;
	return (true);
}

/**
 * static functions of Account class.
 */
int		Account::getNbAccounts( void ) {
	return ( _nbAccounts );
};

int		Account::getTotalAmount( void ) {
	return ( _totalAmount );
};

int		Account::getNbDeposits ( void ) {
	return ( _totalNbDeposits );
};

int		Account::getNbWithdrawals ( void ) {
	return ( _totalNbWithdrawals );
};

int		Account::checkAmount ( void ) const {
	return ( _amount );
};

void Account::_displayTimestamp( void ) {
	std::time_t now = std::time(0);
	std::tm* 	timeinfo = std::localtime(&now);

	std::cout << "[" << (timeinfo->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << timeinfo->tm_sec;
	std::cout << "] ";
}
