#include "headers/main.hpp"
#include "headers/Contact.hpp"
#include "headers/PhoneBook.hpp"
#include <iostream>

int	PhoneBook::contactsCounter = 0;

int	main(void) {
	std::string	command;
	PhoneBook	phoneBook;

	while (true) {
		getline(std::cin, command);
		if (command == "ADD") {
			addContact(phoneBook);
		}
		else if (command == "SEARCH") {

		}
		else if (command == "EXIT") {

		}
		if (std::cin.eof() == true)
			break ;
	};
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
 * addFirstName -
 */
void	PhoneBook::addFirstName(std::string firstName){
	contacts[contactsCounter].setFName(firstName);
}

/**
 * addLastName -
 */
void	PhoneBook::addLastName(std::string lastName) {
	contacts[contactsCounter].setLName(lastName);
}

/**
 * addNickName -
 */
void	PhoneBook::addNickName(std::string nickName) {
	contacts[contactsCounter].setNName(nickName);
}

/**
 * addPhoneNumber -
 */
void	PhoneBook::addPhoneNumber(std::string phoneNumber) {
	contacts[contactsCounter].setPNumber(phoneNumber);
}

/**
 * addSecretPhrase -
 */
void	PhoneBook::addSecretPhrase(std::string secretPhrase) {
	contacts[contactsCounter].setSPhrase(secretPhrase);
}

/**
 * bumpCounter -
 */
void	PhoneBook::bumpCounter() {
	contactsCounter++;
	if (contactsCounter >= 8)
		contactsCounter = 0;
}

/**
 * setFName -
 */
void	Contact::setFName(std::string firstName) {
	this->firstName = firstName;
}

/**
 * setLName -
 */
void	Contact::setLName(std::string lastName) {
	this->lastName = lastName;
}

/**
 * setNName -
 */
void	Contact::setNName(std::string nickName) {
	this->nickName = nickName;
}

/**
 * setPNumber -
 */
void	Contact::setPNumber(std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

/**
 * setSPhrase -
 */
void	Contact::setSPhrase(std::string secretPhrase) {
	this->secretPhrase = secretPhrase;
}
