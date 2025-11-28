#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
void	Account::displayAccountsInfos( void )
{
	std::cout << "bye bye!\n";
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	// [19920104_091532] index:0;amount:42;created
}
Account::~Account( void )
{
	std::cout << "bye bye!\n";
	// [19920104_091532] index:0;amount:47;closed
}

void	makeDeposit( int deposit );
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
bool	makeWithdrawal( int withdrawal );
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
int		checkAmount( void ) const;
void	displayStatus( void ) const;
// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
