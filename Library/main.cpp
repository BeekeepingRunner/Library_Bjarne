#include <iostream>
#include <vector>

#include "library.h"

// TODO:
// 0. Test Chrono::Date
// 1. How to pass input to Book
// 2. How to validate that input

int main()
{
	try {
		Chrono::Date date{ 12, Chrono::Month::dec, 2020 };
		Book book{ "123-412-324-A", "Dziady", "Mickiewicz", Book::Genre::nonfiction, date };

		date.addMonth(3);
		Book book2{ "3-3-4-f", "Lalka", "Boleslaw Prus", Book::Genre::nonfiction, date };

		Patron patron1{ "Bartek", "012532", 0 };
		Patron patron2{ "Justyna", "352533", 20 };

		Library lib{};
		lib.addBook(book);
		lib.addBook(book2);
		lib.addPatron(patron1);
		lib.addPatron(patron2);
		lib.addPatron(patron2);

		lib.bookCheckout("Dziady", "Bartek", date);

		std::vector<std::string> vec{ lib.getDebtorNames() };
		for (std::string s : vec)
			std::cout << s << "\n\n";

		std::cout << Chrono::week_of_year(Chrono::Date{24, Chrono::Month::sep, 2024}) << '\n';
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	catch (Library::TransactionFail) {
		std::cerr << "Library: Transaction failed";
	}
	return 0;
}

