#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * Constructor by parameter -
 */
Account::Account( int initial_deposit )  {
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

/**
 * Deconstructor -
 */
Account::~Account( void ) {
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


