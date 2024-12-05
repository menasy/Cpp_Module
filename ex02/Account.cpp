/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehmyilm <mehmyilm@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:50:12 by mehmyilm          #+#    #+#             */
/*   Updated: 2024/12/05 15:40:07 by mehmyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	t::_displayTimestamp();
	std::cout<<"index:"<<_nbAccounts++<<";amount:"
			<<t::checkAmount()<<";created"<<std::endl;
}
Account::Account(void)
{
	_accountIndex = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}
Account::~Account(void)
{
	t::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"
			<<t::checkAmount()<<";closed"<<std::endl;
}
int	Account::getNbAccounts(void)
{
	return(_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return(_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	t::_displayTimestamp();
	std::cout<<"accounts:"<<t::getNbAccounts()
			<<";total:"<<t::getTotalAmount()
			<<";deposits:"<<t::_totalNbDeposits
			<<";withdrawals:"<<t::_totalNbWithdrawals<<std::endl;
}
void	Account::_displayTimestamp(void)//ok
{
	std::time_t	currentTime;
	char buffer[20];

	currentTime = std::time(0);
	std::strftime(buffer,sizeof(buffer),"[%Y%m%d_%H%M%S] ",std::localtime(&currentTime));
	std::cout<<buffer;
}
void	Account::makeDeposit(int deposit)//ok
{
	t::_displayTimestamp();
	_amount+=deposit;
	std::cout<<"index:"<<t::_accountIndex<<";p_amount:"
			<<t::checkAmount()<<";deposit:"<<deposit
			<<";amount:"<<(_amount)
			<<";nb_deposits:"<<(++_nbDeposits)<<std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal(int withdrawal)//ok
{
	t::_displayTimestamp();
	if (_amount >= withdrawal)
	{
		_amount-=withdrawal;
		std::cout<<"index:"<<t::_accountIndex<<";p_amount:"
				<<t::_amount<<";withdrawal:"<<withdrawal
				<<";amount:"<<(_amount)
				<<";nb_withdrawals:"<<(++t::_nbWithdrawals)<<std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return(true);
	}
	std::cout<<"index:"<<t::_accountIndex<<";p_amount:"
			<<t::_amount<<";withdrawal:refused"<<std::endl;
	return(false);
}
int	Account::checkAmount(void) const
{
	return(_amount);
}

void	Account::displayStatus(void) const
{
	t::_displayTimestamp();
	std::cout<<"index:"<<t::_accountIndex<<";amount:"
			<<t::checkAmount()<<";deposits:"
			<<t::_nbDeposits<<";withdrawals:"
			<<t::_nbWithdrawals<<std::endl;
}

