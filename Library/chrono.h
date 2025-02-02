#pragma once
#include <iostream>

// Main part of this namespace is a Date class which enables us to create objects
// that represent dates which we can set between MIN_YEAR and MAX_YEAR.
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

	static constexpr int MIN_YEAR{ 1970 };
	static constexpr int MAX_YEAR{ 2200 };

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

		int m_monthLength;
		void setMonthLength();
	};

	// helper functions

	static bool isDate(int day, Month month, int year);
	static bool isLeapYear(int year);

	int monthLength(Month month, int year);

	bool operator==(const Date& date1, const Date& date2);
	bool operator!=(const Date& date1, const Date& date2);

	std::ostream& operator<<(std::ostream& os, const Date& date);
	std::istream& operator>>(std::istream& is, Date& date);

	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	std::ostream& operator<<(std::ostream& os, const Day& day);

	Day day_of_week(const Chrono::Date& d);
	Date next_workday(const Chrono::Date& d);
	int week_of_year(const Chrono::Date& d);

};	// Chrono