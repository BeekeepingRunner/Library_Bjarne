#pragma once
#include <string>
#include "chrono.h"

class Book {

public:

	enum class Genre {
		fiction,
		nonfiction,
		periodical,
		biography,
		children
	};

	Book(std::string isbn, std::string title,
		std::string author, Genre genre, Chrono::Date copyrightDate);

	std::string getIsbn()			const { return m_isbn; }
	std::string getTitle()			const { return m_title; }
	std::string getAuthor()			const { return m_author; }
	Genre		getGenre()			const { return m_genre; }

	Chrono::Date getCopyrightDate()	const { return m_copyrightDate; }

	void checkOut() { isCheckedOut = true; }
	void checkIn()	{ isCheckedOut = false; }

private:

	std::string m_isbn;
	std::string m_title;
	std::string m_author;
	Genre		m_genre;
	Chrono::Date m_copyrightDate;

	bool isCheckedOut{ 0 };

	void validation();

	void checkIsbn();
	void isbnError();
};

int toInt(std::string digitString);

bool operator==(const Book& b1, const Book& b2);
bool operator!=(const Book& b1, const Book& b2);

std::ostream& operator<<(std::ostream& os, const Book& b);

std::string enterIsbn();