/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:47:41 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/21 10:47:42 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACTS 8
#define TABLE_WIDTH 12

class PhoneBook {
private:
	Contact	contacts[MAX_CONTACTS];
	int		contactsCounter;
	size_t	contactsIndex;

public:
	PhoneBook();

	void	addFirstName(std::string firstName);
	void	addLastName(std::string lastName);
	void	addNickName(std::string nickName);
	void	addPhoneNumber(std::string phoneNumber);
	void	addSecretPhrase(std::string secretPhrase);
	bool	showContacts() const;
	void	displayContact(std::size_t index) const;
	void	bumpCounter();
	int		getContactsCounter() const;
};

#endif /* PHONEBOOK_HPP */
