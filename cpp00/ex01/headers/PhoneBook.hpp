#include "Contact.hpp"

using namespace std;

class PhoneBook {
private:
	// only access it through a specified member function.
	string  contactsList[8][5];
public:
	// function members:
	void	add(Contact *newUser, int	index) {
		if (index == 8)
			index = 0;
		contactsList[index][0] = newUser->firstName;
		contactsList[index][1] = newUser->lastName;
		contactsList[index][2] = newUser->nickName;
		contactsList[index][3] = newUser->phoneNumber;
		contactsList[index][4] = newUser->darkestSecret;
		for (int j = 0; j < 5; j++) {
				cout << contactsList[index][j];
				cout << " | ";
		}
	}
	void	search(Contact userSearch) {
		
	}
};
