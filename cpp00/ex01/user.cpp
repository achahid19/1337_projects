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
