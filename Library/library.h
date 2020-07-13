#pragma once

#include <iostream>
#include <vector>

#include "Book.h"
#include "patron.h"
#include "chrono.h"
#include "library.h"

struct Transaction {
	Book book;
	Patron patron;
	Chrono::Date date;
};

class Library {

public:
	// classes to be thrown as exceptions
	class BookIsMissing {};
	class PatronIsMissing {};
	class TransactionFail {};

	void addBook(Book &book)			{ books.push_back(book); }
	void addPatron(Patron &patron)	{ patrons.push_back(patron); }

	void bookCheckout(std::string title, std::string userName, Chrono::Date date);

	std::vector<std::string> getDebtorNames();

private:

	std::vector<Book> books;
	std::vector<Patron> patrons;
	std::vector<Transaction> transactions;

	// for bookCheckout(string, string)
	Book getBook(std::string title);
	Patron getPatron(std::string name);
};