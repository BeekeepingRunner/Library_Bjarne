#include <iostream>
#include <vector>

#include "Book.h"

// TODO:
// 1. How to pass input to Book
// 2. How to validate that input

int main()
{
	try {
		Book book{ "123-412-324-A", "Dziady", "Mickiewitch", "22-12-1999" };
		Book book2{ "3-3-4-f", "Lalka", "Boleslaw Prus", "01-02-2010" };

		std::cout << book << '\n' << book2 << '\n';
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}

	return 0;
}

