#pragma once
#include <string>

class Book {

public:

	Book(std::string isbn, std::string title, std::string author, std::string copyrightDate)
		: m_isbn{ isbn }, m_title{ title }, m_author{ author }, m_copyrightDate{ copyrightDate }
	{
		validation();


	}

	std::string getIsbn() { return m_isbn; }
	std::string getTitle() { return m_title; }
	std::string getAuthor() { return m_author; }
	std::string getCopyrightDate() { return m_copyrightDate; }

	void checkOut() { isCheckedOut = true; }
	void checkIn() { isCheckedOut = false; }


private:

	std::string m_isbn;
	std::string m_title;
	std::string m_author;
	std::string m_copyrightDate;

	bool isCheckedOut{ 0 };

	void validation();
};