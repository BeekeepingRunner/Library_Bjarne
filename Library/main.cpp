#include <iostream>
#include <vector>

#include "Book.h"
#include "chrono.h"

// TODO:
// 0. Test Chrono::Date
// 1. How to pass input to Book
// 2. How to validate that input

int main()
{
	try {
		// Book book2{ "3-3-4-f", "Lalka", "Boleslaw Prus", Book::Genre::nonfiction, "01-02-2010" };

		// std::cout << book << '\n' << book2 << '\n';
		
		Chrono::Date date{ 12, Chrono::Month::jul, 2020 };
		Book book{ "123-412-324-A", "Dziady", "Mickiewitch", Book::Genre::nonfiction, date };

		std::cout << book << '\n';
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}

	return 0;
}

