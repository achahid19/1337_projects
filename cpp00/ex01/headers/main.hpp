/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:47:36 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/21 10:47:38 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void		addContact(PhoneBook &phoneBook);
void		getValue(std::string prompt, std::string &value);
void		searchContact(PhoneBook phoneBook);
bool		isDigits(std::string str);
std::string	resize(std::string value);
bool		getIndex(std::size_t &index, int contactsCounter);
void		cmdMenu();
