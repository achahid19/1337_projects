/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:47:04 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/21 10:47:06 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.hpp"

void		getValue(std::string prompt, std::string &value);
bool		isDigits(std::string str);
std::string	resize(std::string value);
bool		getIndex(std::size_t &index, int contactsCounter);

/**
 * getValue - retrieve the value of the current prompt
 */
void	getValue(std::string prompt, std::string &value) {
	if (std::cin.eof())
		return ;
	while (true) {
		std::cout << prompt;
		getline(std::cin, value);
		if (std::cin.eof())
			return ;
		if (value.empty())
			continue ;
		break ;
	}
};

/**
 * isDigits -
 */
bool	isDigits(std::string str) {
	int	index = 0;

	while (str[index]) {
		if (str[index] < '0' || str[index] > '9')
			return (false);
		index++;
	}
	return (true);
}

/**
 * resize -
 */
std::string	resize(std::string value) {
	if (value.length() > 10) {
		value = value.substr(0, 9);
		value += '.';
	}
	return (value);
}

/**
 * getIndex -
 */
bool	getIndex(std::size_t &index, int contactsCounter) {
	std::string	value;

	while (true) {
		getValue("Enter Contact's index: ", value);
		// EOF
		if (std::cin.eof())
			return (false);
		// check the length.
		if (value.length() > 1) {
			if (isDigits(value) == false) {
				std::cout << "Enter only digits values" << std::endl;
				continue ;
			}
			std::cout << "Not a valid index! Retry (0-7)" << std::endl;
			continue ;
		}
		// check if only digits values entered.
		if (isDigits(value) == false) {
			std::cout << "Enter only digits values" << std::endl;
			continue ;
		}
		// convert the character to digit.
		index = value[0] - 48;
		// check if its a valid number.
		if (index >= 8) {
			std::cout << "Not a valid index! Retry (0-7)" << std::endl;
			continue ;
		}
		// Display the contact's index.
		else if (index >= contactsCounter)
			std::cout << "No registred contact for this index." << std::endl;
		else
			break ;
	}
	return (true);
}
