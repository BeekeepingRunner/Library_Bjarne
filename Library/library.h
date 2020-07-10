#pragma once

#include <iostream>
#include <vector>

#include "Book.h"
#include "patron.h"

struct Transaction {

};

class Library {

public:

	std::vector<Book> books;
	std::vector<Patron> patrons;

private:


};