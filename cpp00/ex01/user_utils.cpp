/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:00:09 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/21 11:00:10 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.hpp"

void		addContact(PhoneBook &phoneBook);
void		searchContact(PhoneBook phoneBook);

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
 * showContact -
 */
bool	PhoneBook::showContacts() {
	if (contacts[0].getFName().empty() == true)
		return false;
	std::cout << std::setw(TABLE_WIDTH) << std::right << "Index" << "|";
	std::cout << std::setw(TABLE_WIDTH) << std::right << "First Name" << "|";
	std::cout << std::setw(TABLE_WIDTH) << std::right << "Last Name" << "|";
	std::cout << std::setw(TABLE_WIDTH) << std::right << "Nick Name" << std::endl;
	for (std::size_t index = 0; index < contactsCounter; index++) {
		std::cout << std::setw(TABLE_WIDTH) << std::right << index << "|";
		std::cout << std::setw(TABLE_WIDTH) << std::right << resize(contacts[index].getFName()) << "|";
		std::cout << std::setw(TABLE_WIDTH) << std::right << resize(contacts[index].getLName()) << "|";
		std::cout << std::setw(TABLE_WIDTH) << std::right << resize(contacts[index].getNName()) << std::endl;
	};
	return true;
}

/**
 * displayContact -
 */
void	PhoneBook::displayContact(std::size_t index) {
	std::cout << "-> First Name   : " << contacts[index].getFName() << std::endl;
	std::cout << "-> Last Name    : " << contacts[index].getLName() << std::endl;
	std::cout << "-> Nick Name    : " << contacts[index].getNName() << std::endl;
	std::cout << "-> Phone Number : " << contacts[index].getPNumber() << std::endl;
	std::cout << "-> Secret Phrase: " << contacts[index].getSPhrase() << std::endl;
}

/**
 * counterInit -
 */
void	PhoneBook::counterInit(void) {
	contactsCounter = 0;
	contactsIndex = 0;
}

/**
 * bumpCounter -
 */
void	PhoneBook::bumpCounter() {
	if (contactsCounter < MAX_CONTACTS)
		contactsCounter++;
	contactsIndex++;
	if (contactsIndex >= MAX_CONTACTS)
		contactsIndex = 0;
}

/**
 * getContactsCounter -
 */
int		PhoneBook::getContactsCounter() {
	return (contactsCounter);
}
