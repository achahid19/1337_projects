#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact		contacts[8];
	static int	contactsCounter;
public:
	// functionalities / Interface user.
	void	addFirstName(std::string firstName);
	void	addLastName(std::string lastName);
	void	addNickName(std::string nickName);
	void	addPhoneNumber(std::string phoneNumber);
	void	addSecretPhrase(std::string secretPhrase);
	void	bumpCounter();
	void	showContact(std::size_t	index);
	std::string truncateString(size_t index, std::size_t width);
};

#endif /* PHONEBOOK_HPP */
