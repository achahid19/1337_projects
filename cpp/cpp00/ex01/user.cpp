/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:56:19 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/21 10:56:20 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.hpp"

PhoneBook::PhoneBook() {
	contactsCounter = 0;
	contactsIndex = 0;
}

void	PhoneBook::addFirstName(const std::string firstName){
	contacts[contactsIndex].setFName(firstName);
}

void	PhoneBook::addLastName(const std::string lastName) {
	contacts[contactsIndex].setLName(lastName);
}

void	PhoneBook::addNickName(const std::string nickName) {
	contacts[contactsIndex].setNName(nickName);
}

void	PhoneBook::addPhoneNumber(const std::string phoneNumber) {
	contacts[contactsIndex].setPNumber(phoneNumber);
}

void	PhoneBook::addSecretPhrase(const std::string secretPhrase) {
	contacts[contactsIndex].setSPhrase(secretPhrase);
}

void	Contact::setFName(const std::string firstName) {
	this->firstName = firstName;
}

void	Contact::setLName(const std::string lastName) {
	this->lastName = lastName;
}

void	Contact::setNName(const std::string nickName) {
	this->nickName = nickName;
}

void	Contact::setPNumber(const std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void	Contact::setSPhrase(const std::string secretPhrase) {
	this->secretPhrase = secretPhrase;
}

std::string	Contact::getFName() const {
	return (this->firstName);
};

std::string	Contact::getLName() const {
	return (this->lastName);
}

std::string	Contact::getNName() const {
	return (this->nickName);
}

std::string	Contact::getPNumber() const {
	return (this->phoneNumber);
}

std::string	Contact::getSPhrase() const {
	return (this->secretPhrase);
}

bool	PhoneBook::showContacts() const {
	if (contacts[0].getFName().empty() == true)
		return false;
	std::cout << std::setw(TABLE_WIDTH) << std::right << "Index" << "|";
	std::cout << std::setw(TABLE_WIDTH) << std::right << "First Name" << "|";
	std::cout << std::setw(TABLE_WIDTH) << std::right << "Last Name" << "|";
	std::cout << std::setw(TABLE_WIDTH) << std::right << "Nick Name" << std::endl;
	for (std::size_t index = 0; (int)index < getContactsCounter(); index++) {
		std::cout << std::setw(TABLE_WIDTH) <<
			std::right << index << "|";
		std::cout << std::setw(TABLE_WIDTH) <<
			std::right << resize(contacts[index].getFName()) << "|";
		std::cout << std::setw(TABLE_WIDTH) <<
			std::right << resize(contacts[index].getLName()) << "|";
		std::cout << std::setw(TABLE_WIDTH) <<
			std::right << resize(contacts[index].getNName()) << std::endl;
	};
	return true;
}

void	PhoneBook::displayContact(std::size_t index) const {
	std::cout <<  PURPLE << "-> First Name     : " <<
		contacts[index].getFName() << std::endl;
	std::cout << "-> Last Name      : " <<
		contacts[index].getLName() << std::endl;
	std::cout << "-> Nick Name      : " <<
		contacts[index].getNName() << std::endl;
	std::cout << "-> Phone Number   : " <<
		contacts[index].getPNumber() << std::endl;
	std::cout << "-> Darkest Secret : " <<
		contacts[index].getSPhrase() << RESET << std::endl;
}

void	PhoneBook::bumpCounter(void) {
	if (contactsCounter < MAX_CONTACTS)
		contactsCounter++;
	contactsIndex++;
	if (contactsIndex >= MAX_CONTACTS)
		contactsIndex = 0;
}

int		PhoneBook::getContactsCounter(void) const {
	return (contactsCounter);
}
