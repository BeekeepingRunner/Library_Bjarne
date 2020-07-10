#pragma once
#include <iostream>

namespace Chrono {

	enum class Month {
		jan = 1,
		feb,
		mar,
		apr,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		dec
	};

	class Date {

	public:
		class Invalid {};				// to throw as an exception

		Date(int dd, Month mm, int yy);	// checks for valid date and initializes
		Date();							
		// the default copy operations are fine

		int getDay() const { return m_day; }
		Month getMonth() const { return m_month; }
		int getYear() const { return m_year; }

		// modifying operations:
		void addDay(int n);
		void addMonth(int n);
		void addYear(int n);

	private:
		int m_day;
		Month m_month;
		int m_year;
	};

	static bool isDate(int day, Month month, int year);
	static bool leapyear(int year);

	bool operator==(const Date& date1, const Date& date2);
	bool operator!=(const Date& date1, const Date& date2);

	std::ostream& operator<<(std::ostream& os, const Date& date);
	std::istream& operator>>(std::istream& is, Date& date);

};	// Chrono