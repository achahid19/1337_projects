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

void		cmdMenu();
void		addContact(PhoneBook &phoneBook);
void		getValue(std::string prompt, std::string &value);
bool		spaceChecker(const std::string value);
bool		isSpace(char c);
void		searchContact(PhoneBook phoneBook);
bool		isDigits(const std::string str);
std::string	resize(std::string value);
bool		getIndex(std::size_t &index, int contactsCounter);

/**
 * displayMsg -
 */
inline void	displayMsg(const std::string msg, const char* color) {
	std::cout << color << msg << RESET << std::endl;
}

/**
 * commandMenu -
 */
void	cmdMenu() {
	displayMsg("[CHOOSE A COMMAND]", GREEN);
	std::cout << "-> ADD" << std::endl;
	std::cout << "-> SEARCH" << std::endl;
	std::cout << "-> EXIT" << std::endl;
};

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
void	getValue(const std::string prompt, std::string &value) {
	if (std::cin.eof())
		return ;
	while (true) {
		std::cout << prompt << std::endl;
		getline(std::cin, value);
		if (std::cin.eof())
			return ;
		if (value.empty())
			continue ;
		if (spaceChecker(value) == true)
			continue ;
		break ;
	}
};

/**
 * spaceChekcer -
 */
bool	spaceChecker(const std::string value) {
	bool	whiteSpaces = true;

	for (std::size_t index = 0; value[index]; index++) {
		if (isSpace(value[index]) == true)	{
			whiteSpaces = false;
			break ;
		}
	}
	return (whiteSpaces);
}

/**
 * isSpace -
 */
bool	isSpace(char c) {
	return ((c < 8 || c > 13) && c != ' ');
}

/**
 * searchContact -
 */
void	searchContact(PhoneBook phoneBook) {
	std::size_t	index;

	// show all the contacts
	if (phoneBook.showContacts() == false) {
		displayMsg("[WARNING]: Empty table.", RED);
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
bool	isDigits(const std::string str) {
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
				displayMsg("[WARNING]: Enter only digits values", RED);
				continue ;
			}
			displayMsg("[WARNING]: Not a valid index! Retry (0-7)", RED);
			continue ;
		}
		// check if only digits values entered.
		if (isDigits(value) == false) {
			displayMsg("[WARNING]: Enter only digits values", RED);
			continue ;
		}
		// convert the character to digit.
		index = value[0] - 48;
		// check if its a valid number.
		if (index >= 8) {
			displayMsg("[WARNING]: Not a valid index! Retry (0-7)", RED);
			continue ;
		}
		// Display the contact's index.
		else if ((int)index >= contactsCounter)
			displayMsg("[WARNING]: No registred contact for this index.", RED);
		else
			break ;
	}
	return (true);
}
