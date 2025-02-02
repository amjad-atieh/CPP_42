/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatieh <aatieh@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 03:50:03 by aatieh            #+#    #+#             */
/*   Updated: 2025/02/02 18:05:41 by aatieh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount <<
		";deposits:" << _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << '\n';
}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
		_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";created\n";
}

Account::~Account( void )
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";closed\n";
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< _amount - deposit << ";deposit:" << deposit
		<< ";amount:" << _amount << ";nb_deposits:"
		<< _nbDeposits << '\n';
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
			<< _amount << ";withdrawal:refused\n";
		return false;
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:"
			<< _amount + withdrawal << ";withdrawal:" << withdrawal
			<< ";amount:" << _amount << ";nb_withdrawals:"
			<< _nbWithdrawals << '\n';
		return true;
	}
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits << ";withdrawals:"
		<< _nbWithdrawals << '\n';
}

void	Account::_displayTimestamp( void )
{
	std::time_t		now = std::time(0);
	std::tm			*ltm = std::localtime(&now);
	char			log_time[19];

	std::strftime (log_time, 19, "[%G%m%d_%H%M%S] ", ltm);
	std::cout << log_time;
}

Account::Account( void )
{
	_amount = 0;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";created\n";
}
