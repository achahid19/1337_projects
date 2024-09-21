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

void	PhoneBook::addFirstName(std::string firstName){
	contacts[contactsIndex].setFName(firstName);
}

void	PhoneBook::addLastName(std::string lastName) {
	contacts[contactsIndex].setLName(lastName);
}

void	PhoneBook::addNickName(std::string nickName) {
	contacts[contactsIndex].setNName(nickName);
}

void	PhoneBook::addPhoneNumber(std::string phoneNumber) {
	contacts[contactsIndex].setPNumber(phoneNumber);
}

void	PhoneBook::addSecretPhrase(std::string secretPhrase) {
	contacts[contactsIndex].setSPhrase(secretPhrase);
}

void	Contact::setFName(std::string firstName) {
	this->firstName = firstName;
}

void	Contact::setLName(std::string lastName) {
	this->lastName = lastName;
}

void	Contact::setNName(std::string nickName) {
	this->nickName = nickName;
}

void	Contact::setPNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void	Contact::setSPhrase(std::string secretPhrase) {
	this->secretPhrase = secretPhrase;
}

std::string	Contact::getFName() {
	return (this->firstName);
};

std::string	Contact::getLName() {
	return (this->lastName);
}

std::string	Contact::getNName() {
	return (this->nickName);
}

std::string	Contact::getPNumber() {
	return (this->phoneNumber);
}

std::string	Contact::getSPhrase() {
	return (this->secretPhrase);
}

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

void	PhoneBook::displayContact(std::size_t index) {
	std::cout << "-> First Name   : " << contacts[index].getFName() << std::endl;
	std::cout << "-> Last Name    : " << contacts[index].getLName() << std::endl;
	std::cout << "-> Nick Name    : " << contacts[index].getNName() << std::endl;
	std::cout << "-> Phone Number : " << contacts[index].getPNumber() << std::endl;
	std::cout << "-> Secret Phrase: " << contacts[index].getSPhrase() << std::endl;
}

void	PhoneBook::counterInit(void) {
	contactsCounter = 0;
	contactsIndex = 0;
}

void	PhoneBook::bumpCounter(void) {
	if (contactsCounter < MAX_CONTACTS)
		contactsCounter++;
	contactsIndex++;
	if (contactsIndex >= MAX_CONTACTS)
		contactsIndex = 0;
}

int		PhoneBook::getContactsCounter(void) {
	return (contactsCounter);
}
