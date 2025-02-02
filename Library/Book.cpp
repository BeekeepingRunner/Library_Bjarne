#include "Book.h"

#include <iostream>

// TODO:
// 1. Try to connect the date validation with a Date class in Chrono.h

// Constructor takes all necessary information about a book
// and checks if it is correct (throws runtime-error otherwise).
// Note:
// Copyright date - a Date object which don't need a validation here (we can be sure that it is correct).
Book::Book(std::string isbn, std::string title, std::string author, Genre genre, Chrono::Date copyrightDate)
	: m_isbn{ isbn }, m_title{ title }, m_author{ author }, m_genre{ genre }, m_copyrightDate{ copyrightDate }
{
	validation();
}

// Validation of book's ISBN
// TODO: validation of book's title and author
void Book::validation()
{
	checkIsbn();
}

// Parses book's ISBN.
// ISBN shoud take the following form: n-n-n-x
// where n are sequences of decimal digits
// and x is either a digit or a letter.
// Throws runtime-error if ISBN is corrupted.
void Book::checkIsbn()
{
	char delimiter{ '-' };
	int delimitCount{ 0 }; // there should be 3 delimeters in an ISBN

	std::size_t pos{ 0 };
	std::string isbn = m_isbn;
	std::string token;

	// check substrings separated by '-', without a last one
	while ((pos = isbn.find(delimiter)) != std::string::npos)
	{
		++delimitCount;
		token = isbn.substr(0, pos);

		if (token.length() == 0)
			isbnError();

		// check if token is a sequence of decimal digits
		for (char c : token)
		{
			if (!std::isdigit(c))
				isbnError();
		}

		// break a loop to preserve pos value
		if (delimitCount == 3) {
			isbn.erase(0, pos + 1);
			break;
		}

		isbn.erase(0, pos + 1);
	}

	if (delimitCount != 3)
		isbnError();

	// check if the isbn remainder is a single digit or letter
	if (isbn.length() != 1)
		isbnError();

	char c{ isbn[0] };
	if (!std::isalnum(c))
		isbnError();
}

void Book::isbnError() {
	throw std::runtime_error("Book: checkIsbn(): invalid isbn");
}

// Converts a string to an integer.
// Assumes that digitString is a sequence of decimal digits.
int toInt(std::string digitString)
{
	int outInteger{ 0 };
	
	int multiplier{};
	if (digitString.length() > 1)
	{
		multiplier = 10 * (digitString.length() - 1);
	}
	else
		multiplier = 1;

	for (char c : digitString)
	{
		outInteger += (static_cast<int>(c) - static_cast<int>('0')) * multiplier;
		multiplier /= 10;
	}

	return outInteger;
}

// OVERLOADED OPERATORS

bool operator==(const Book& b1, const Book& b2)
{
	if (b1.getIsbn() == b2.getIsbn())
		return true;
	else
		return false;
}

bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1 == b2);
}

std::ostream& operator<<(std::ostream& os, const Book& b)
{
	os << b.getTitle() << '\n' << b.getAuthor() << '\n';
	
	switch (b.getGenre())
	{
	case Book::Genre::fiction:
		os << "fiction\n";
		break;
	case Book::Genre::nonfiction:
		os << "nonfiction\n";
		break;
	case Book::Genre::periodical:
		os << "periodical\n";
		break;
	case Book::Genre::biography:
		os << "biography\n";
		break;
	case Book::Genre::children:
		os << "children\n";
		break;
	}

	os << b.getIsbn();
	return os;
}

// todo someday
std::string enterIsbn()
{
	return "";
}