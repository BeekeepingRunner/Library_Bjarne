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

	std::vector<Book> books;
	std::vector<Patron> patrons;
	std::vector<Transaction> transactions;

	void addBook(Book book)			{ books.push_back(book); }
	void addPatron(Patron patron)	{ patrons.push_back(patron); }

	void bookCheckout(std::string title, std::string userName);

	std::vector<std::string> getDebtorNames();

private:


};