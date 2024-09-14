#include <iostream>
#include <string>
#include "headers/PhoneBook.hpp"
#include "headers/main.h"
#include <cctype>

using namespace std;

int	main(void)
{
	PhoneBook	usersList;
	Contact		newUser;
	string		input;
	int			index = 0;

	while (true) {
		cin >> input;
		if (input == "add") {
			retrieveInfos(&newUser);
			// get the data saved on the Phone book.
			usersList.add(&newUser, index);
			index++;
			if (index == 9)
				index = 1;
		}
		else if (input == "search") {

		}
		else if (input == "exit") {
			break ;
		}
	}
	return 0;
}

/**
 * retriveInfos - get the new contact infos from the cli.
 * @newUser: pointes to the instance created from Contact class,
 * 			and holds the retrieved contact informations.
 * 
 * Return: void.
 */
void	retrieveInfos(Contact *newUser) {
	newUser->firstName = getInput("First name: ");
	newUser->lastName = getInput("Last name: ");
	newUser->nickName = getInput("Nick name: ");
	newUser->phoneNumber = getInput("Phone number: ");
	newUser->darkestSecret = getInput("Secret Phrase: ");
};

/**
 * getInput - Display the user prompt and get the input.
 * @prompt: message to display.
 * 
 * Return: Input retrieved.
 */
string	getInput(string prompt) {
	string		input;

	while (true) {
		// get 2 prompt on the first time!
		cout << prompt;
		getline(cin, input);
		// check for whitespaces.
		if (whitespacesChecker(input) == true)
			continue ;
		if (input.empty() == false)
			break ;
	}
	return (input);
};

/**
 * whitespacesChecker - checks if all the input contains only whitespaces.
 * @input: string to check (the input retrieved from the user).
 * 
 * Return: boolean.
 */
bool	whitespacesChecker(string input) {
	size_t	i = 0;
	
	while (i < input.length()) {
		if (isspace(input[i]) == false)
			return (false);
		i++;
	}
	return (true);
};
