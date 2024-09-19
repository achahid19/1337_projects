#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact		contacts[8];
	static int	contactsCounter;
public:
	// functionalities
	void	addFirstName(std::string firstName);
	void	addLastName(std::string lastName);
	void	addNickName(std::string nickName);
	void	addPhoneNumber(std::string phoneNumber);
	void	addSecretPhrase(std::string secretPhrase);
	void	bumpCounter();
};

#endif
