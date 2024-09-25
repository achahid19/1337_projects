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

#ifndef MAIN_H
#define MAIN_H

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0m"

void		cmdMenu();
void		addContact(PhoneBook &phoneBook);
void		getValue(const std::string prompt, std::string &value);
void		searchContact(PhoneBook phoneBook);
bool		isDigits(const std::string str);
std::string	resize(std::string value);
bool		getIndex(std::size_t &index, int contactsCounter);

#endif /* MAIN_H */
