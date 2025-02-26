/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpikkov <fpikkov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:50:33 by fpikkov           #+#    #+#             */
/*   Updated: 2025/02/13 16:50:35 by fpikkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	// Static member variables
	_nbAccounts++;
	_totalAmount += initial_deposit;

	// Local member
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit \
	<< ";created" << std::endl;
}

Account::~Account( void )
{
	// Bank keeps the money on account closure
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

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
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount \
	<<";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	prev;

	// Static member
	_totalNbDeposits++;
	_totalAmount += deposit;

	// Local member
	prev = _amount;
	_nbDeposits++;
	_amount += deposit;

	// Status
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << prev << ";deposit:" \
	<< deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	prev;

	prev = _amount;
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << prev << ";withdrawal:refused" << std::endl;
		return (false);
	}
	// Static member
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	// Local member
	_nbWithdrawals++;
	_amount-= withdrawal;

	// Status
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << prev << ";withdrawal:" << withdrawal \
	<< ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount \
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	time;
	char		buffer[19];
	tm			*ptr;

	time = std::time(NULL);
	ptr = localtime(&time);
	std::strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", ptr);
	std::cout << buffer ;
}
