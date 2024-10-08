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

inline void	displayMsg(const std::string msg, const char* color);

int	main(void) {
	std::string	command;
	PhoneBook	phoneBook;

	while (true) {
		cmdMenu();
		getline(std::cin, command);
		if (command == "ADD") {
			addContact(phoneBook);
		}
		else if (command == "SEARCH") {
			searchContact(phoneBook);
		}
		else if (command == "EXIT") {
			displayMsg("Program Exited Succesfully!", GREEN);
			break ;
		}
		if (std::cin.eof() == true)
			break ;
	};
	return 0;
};

/**
 * displayMsg -
 */
inline void	displayMsg(const std::string msg, const char* color) {
	std::cout << color << msg << RESET << std::endl;
}
