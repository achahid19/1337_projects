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

void		addContact(PhoneBook &phoneBook);
void		getValue(std::string prompt, std::string &value);
void		searchContact(PhoneBook phoneBook);
bool		isDigits(std::string str);
std::string	resize(std::string value);
bool		getIndex(std::size_t &index, int contactsCounter);

/**
 * getInfos - prompt the user for infos required,
 * then add them to the phonebook as a new contact.
 */
void	addContact(PhoneBook &phoneBook) {
	std::string	value;

	getValue("Enter First Name: ", value);
	phoneBook.addFirstName(value);
	getValue("Enter Last Name: ", value);
	phoneBook.addLastName(value);
	getValue("Enter Nick Name: ", value);
	phoneBook.addNickName(value);
	getValue("Enter Phone Number: ", value);
	phoneBook.addPhoneNumber(value);
	getValue("Enter Secret Phrase: ", value);
	phoneBook.addSecretPhrase(value);
	phoneBook.bumpCounter();
};

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
 * searchContact -
 */
void	searchContact(PhoneBook phoneBook) {
	std::size_t	index;

	// show all the contacts
	if (phoneBook.showContacts() == false) {
		std::cout << "[Warning]: Empty table." << std::endl;
		return ;
	}
	// retrieve the index choosen by user.
	if (getIndex(index, phoneBook.getContactsCounter()) == false)
		return ;
	phoneBook.displayContact(index);
}

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
