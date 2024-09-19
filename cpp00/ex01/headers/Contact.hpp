#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	secretPhrase;
public:
	// getters and setters.
	void	setFName(std::string firstName);
	void	setLName(std::string lastName);
	void	setNName(std::string nickName);
	void	setPNumber(std::string phoneNumber);
	void	setSPhrase(std::string secretPhrase);
};

#endif
