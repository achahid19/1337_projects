#include "MutantStack.hpp"

int	main( void ) {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	//std::cout << mstack.top() << std::endl;
	mstack.pop();
	//std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	MutantStack<int>::const_iterator const_it = mstack.begin();
	MutantStack<int>::const_iterator const_ite = mstack.end();

	++it;
	--it;
	--ite;
	while (ite != it)
	{
		std::cout << *ite << std::endl;
		--ite;
	}

	std::cout << "Const iterator testing:" << std::endl;
	const_ite--;
	for (; const_ite != const_it; const_ite--) {
		std::cout << *const_ite << std::endl;
	}
	
	return 0;
}

/* #include <list>
int	main( void ) {
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
} */
