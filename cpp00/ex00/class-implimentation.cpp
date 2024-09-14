#include <iostream>

using namespace std;

class title {
private:
	string	t;

public:
	// Parameterized constructor
	title(string a) {
		setTitle(a);
	}
	void setTitle(string b) {
		t = b;
	}
	string getTitle() {
		return t;
	}
};

int	main(void)
{
	title film("best 2020 movie!");

	cout << film.getTitle();
	return 0;
}
