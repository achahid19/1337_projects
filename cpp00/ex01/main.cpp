/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:47:16 by achahid-          #+#    #+#             */
/*   Updated: 2024/09/21 10:47:17 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/main.hpp"

int	main(void) {
	std::string	command;
	PhoneBook	phoneBook;

	phoneBook.counterInit();
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
