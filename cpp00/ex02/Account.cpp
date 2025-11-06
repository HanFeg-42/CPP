#include <iostream>
#include "Account.hpp"

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
}

Account( int initial_deposit )
{
    std::cout << "ma3rft mandir mhm ana l constructor" << ini
}
~Account( void )
{
    std::cout << "bye bye!\n";
}

void	makeDeposit( int deposit );
bool	makeWithdrawal( int withdrawal );
int		checkAmount( void ) const;
void	displayStatus( void ) const;