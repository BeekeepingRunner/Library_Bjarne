#pragma once
#include <string>

class Book {

public:

	Book(std::string isbn, std::string title,
		std::string author, std::string copyrightDate);

	std::string getIsbn() const { return m_isbn; }
	std::string getTitle() const { return m_title; }
	std::string getAuthor() const { return m_author; }
	std::string getCopyrightDate() const { return m_copyrightDate; }

	void checkOut() { isCheckedOut = true; }
	void checkIn() { isCheckedOut = false; }

private:

	std::string m_isbn;
	std::string m_title;
	std::string m_author;
	std::string m_copyrightDate;

	bool isCheckedOut{ 0 };

	void validation();
	void parseIsbn();
};

std::string enterIsbn();