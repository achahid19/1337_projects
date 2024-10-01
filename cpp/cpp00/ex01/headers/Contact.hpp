/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:47:28 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/21 10:47:29 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// setters.
	void		setFName(const std::string firstName);
	void		setLName(const std::string lastName);
	void		setNName(const std::string nickName);
	void		setPNumber(const std::string phoneNumber);
	void		setSPhrase(const std::string secretPhrase);
	// getters.
	std::string	getFName();
	std::string	getLName();
	std::string getNName();
	std::string	getPNumber();
	std::string	getSPhrase();
};

#endif
