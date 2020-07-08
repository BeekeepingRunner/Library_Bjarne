#include "Book.h"

#include <iostream>

// Constructor takes all necessary information about a book
// and checks if it is correct (throws runtime-error otherwise).
Book::Book(std::string isbn, std::string title,
	std::string author, std::string copyrightDate)
	: m_isbn{ isbn }, m_title{ title },
	m_author{ author }, m_copyrightDate{ copyrightDate }
{
	validation();
}

// Validation of book's ISBN, title, author and copyright date.
void Book::validation()
{
	parseIsbn();
}

// Parses book's ISBN.
// ISBN shoud take the following form: n-n-n-x
// where n are sequences of decimal digits
// and x is either a digit or a letter.
// Throws runtime-error if ISBN is corrupted.
void Book::parseIsbn()
{
	char delimiter{ '-' };
	int delimitCount{ 0 };

	std::size_t pos{ 0 };
	std::string isbn = m_isbn;
	std::string token;

	// check substrings between '-' without a last one
	while ((pos = isbn.find(delimiter)) != std::string::npos)
	{
		++delimitCount;
		token = isbn.substr(0, pos);

		if (token.length() == 0)
			throw std::runtime_error("Book: invalid isbn");

		// check if token is an integer
		for (char c : token)
		{
			if (c < 48 || 57 < c)
				throw std::runtime_error("Book: invalid isbn");
		}

		// break a loop to preserve pos value
		if (delimitCount == 3) {
			isbn.erase(0, pos + 1);
			break;
		}

		isbn.erase(0, pos + 1);
	}

	if (delimitCount != 3)
		throw std::runtime_error("Book: invalid isbn");

	// check if the isbn remainder is a single digit or letter
	if (isbn.length() != 1)
		throw std::runtime_error("Book: invalid isbn");

	char c{ isbn[0] };
	if (!std::isalnum(c))
		throw std::runtime_error("Book: invalid isbn");
}

// todo someday
std::string enterIsbn()
{
	return "";
}