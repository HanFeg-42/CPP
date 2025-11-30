#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created\n";
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account( void )
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed\n";
}

/**
 * Defining static memeber attributes
 */
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* definition of getters*/
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
/**
 * The localtime() function returns a pointer to a structure
 * representing the time in the computer's time zone.
 */
void	Account::_displayTimestamp( void )
{
  time_t timestamp = time(NULL);
  struct tm datetime = *localtime(&timestamp);

  std::cout << "[" << datetime.tm_year + 1900;
  std::cout << std::setfill('0') << std::setw(2) << datetime.tm_mon + 1;
  std::cout << std::setfill('0') << std::setw(2) << datetime.tm_mday;
  std::cout << "_";
  std::cout << std::setfill('0') << std::setw(2) << datetime.tm_hour;
  std::cout << std::setfill('0') << std::setw(2) << datetime.tm_min;
  std::cout << std::setfill('0') << std::setw(2) << datetime.tm_sec << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << ++_nbDeposits << std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (checkAmount() > withdrawal)
	{
		std::cout << withdrawal;
		_amount -= withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
	}
	else
		std::cout << "refused\n";
	return true;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}
