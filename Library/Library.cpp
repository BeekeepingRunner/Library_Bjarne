#include "library.h"

// 3. Create a Transaction, and add it to a vector
void Library::bookCheckout(std::string title, std::string userName, Chrono::Date date)
{
	try {
		Book book = getBook(title);
		Patron patron = getPatron(userName);
		
		if (patron.getLibFees())
			throw TransactionFail{};

		// Now we have a book and a patron with no fees
		Transaction t{ book, patron, date };
		transactions.push_back(t);
	}
	catch (BookIsMissing) {
		std::cerr << "Library: bookCheckout(): Book doesn't exist in a library.\n";
		throw TransactionFail{};
	}
	catch (PatronIsMissing) {
		std::cerr << "Library: bookCheckout(): Book doesn't exist in a library.\n";
		throw TransactionFail{};
	}
}

// Checks if a book exists in a library.
// If it does, returns a reference to it, throws error otherwise.
// Linear search, not very efficient, to be improved in the future.
Book Library::getBook(std::string title)
{
	for (Book b : books)
	{
		if (b.getTitle() == title)
		{
			return b;
		}
	}
	
	throw BookIsMissing();
}

// Checks if a patron exists in a library.
// Linear search, not very efficient, to be improved in the future.
Patron Library::getPatron(std::string name)
{
	for (Patron p : patrons)
	{
		if (p.getUserName() == name)
		{
			return p;
		}
	}

	throw PatronIsMissing();
}

// Returns a vector that contains the names of all Patorns who owe fees.
std::vector<std::string> Library::getDebtorNames()
{
	std::vector<std::string> debtorNames;

	for (Patron patron : patrons)
	{
		if (patron.getLibFees())
		{
			debtorNames.push_back(patron.getUserName());
		}
	}

	return debtorNames;
}