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
			searchContact(phoneBook);
		}
		else if (command == "EXIT") {
			std::cout << "Program exited Succesfully!" << std::endl;
			break ;
		}
		if (std::cin.eof() == true)
			break ;
	};
	return 0;
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

/**
 * searchContact -
 */
void	searchContact(PhoneBook phoneBook) {
	std::string	value;
	int			index;

	while (true) {
		getValue("Enter Contact's index: ", value);
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
		// now we have the appropriate index.
		phoneBook.showContact(index);
	}
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
 * getFName -
 */
std::string	Contact::getFName() {
	return (this->firstName);
};

/**
 * getLName -
 */
std::string	Contact::getLName() {
	return (this->lastName);
}

/**
 * getNName -
 */
std::string	Contact::getNName() {
	return (this->nickName);
}

/**
 * getPNumber -
 */
std::string	Contact::getPNumber() {
	return (this->phoneNumber);
}

/**
 * getSPhrase -
 */
std::string	Contact::getSPhrase() {
	return (this->secretPhrase);
}

/**
 * showContact -
 */
void	PhoneBook::showContact(std::size_t index) {
	if (contacts[index].getFName().empty() == true)
	{
		std::cout << "Empty index: no registred contact yet!" << std::endl;
		return ;
	}
	std::cout << contacts[index].getFName() << std::endl;
	std::cout << contacts[index].getLName() << std::endl;
	std::cout << contacts[index].getNName() << std::endl;
}
