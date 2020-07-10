#include "chrono.h"

// TODO:
// 1. Day, month, year addition

namespace Chrono {

	Date::Date(int dd, Month mm, int yy)
		: m_day{ dd }, m_month{ mm }, m_year{ yy }
	{
		if (!isDate(dd, mm, yy)) throw Invalid{};
	}

	const Date& default_date()
	{
		static Date dd{ 2001, Month::jan, 1 };
		return dd;
	}

	Date::Date()
		: m_day{ default_date().getDay() },
		m_month{ default_date().getMonth() },
		m_year{ default_date().getYear() }
	{}

	// Adds n days to the Date.
	// Assumes that 0 <= n < 32
	// TODO SOMEDAY:
	// let n be any non-negative integer
	void Date::addDay(int n)
	{
		if (0 < n < 32)
			throw std::runtime_error("Date: addDay(): 0 <= n < 32");

		int days_in_month{ 31 };

		switch (m_month) {

		case Month::feb:
			if (leapyear(m_year))
				days_in_month = 29;
			else
				days_in_month = 28;
			break;
		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			days_in_month = 30;
			break;
		}

		m_day = m_day + n;

		if (m_day > days_in_month)
		{
			m_day = m_day - days_in_month;
			addMonth(1);
		}
	}

	// TO IMPROVE
	void Date::addMonth(int n)
	{
		int intMonth{ static_cast<int>(m_month) + n }; // calculation help

		int yearsPassed{ 0 };
		while (intMonth > 12)
		{
			++yearsPassed;
			intMonth -= 12;
		}
		m_year += yearsPassed;
		m_month = static_cast<Month>(intMonth);	// back to the Month form

		// How many days should be in obtained month
		int days_in_month{ 31 };
		switch (m_month) {

		case Month::feb:
			if (leapyear(m_year))
				days_in_month = 29;
			else
				days_in_month = 28;
			break;
		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			days_in_month = 30;
			break;
		}

		if (m_day > days_in_month)
		{
			m_day -= days_in_month;
			// It's certain that there is no year addition here
			// and that m_day < days_in_month, so it's safe to do recursion
			addMonth(1);
		}
	}

	void Date::addYear(int n)
	{
		if (m_month == Month::feb && m_day == 29 && !leapyear(m_year + n)) {
			m_month = Month::mar;
			m_day = 1;
		}
		m_year += n;
	}

	// helper functions:

	// TODO
	bool isDate(int dd, Month mm, int yy)
	{
		// assume that y is valid

		if (dd <= 0) return false;

		if (mm < Month::jan || Month::dec < mm) return false;

		int days_in_month{ 31 };

		switch (mm) {

		case Month::feb:
			days_in_month = (leapyear(yy)) ? 29 : 28;
			break;

		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			days_in_month = 30;
			break;
		}

		if (days_in_month < dd) return false;

		return true;
	}

	bool leapyear(int y)
	{
		if (y % 4 == 0)
		{
			if ((y % 100 == 0) && (y % 400 != 0))
				return false;
			else
				return true;
		}
		else
			return false;
	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.getYear() == b.getYear()
			&& a.getMonth() == b.getMonth()
			&& a.getDay() == b.getDay();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream& os, const Month m)
	{
		return os << static_cast<int>(m);
	}

	std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		return os << '(' << date.getDay() << ',' << date.getMonth() << ',' << date.getYear() << ')';
	}

	std::istream& operator>>(std::istream& is, Date& date)
	{
		int yy, mm, dd;
		char ch1, ch2, ch3, ch4;

		is >> ch1 >> yy >> ch2 >> mm >> ch3 >> dd >> ch4;

		if (!is) return is;

		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		date = Date(dd, static_cast<Month>(mm), yy);

		return is;
	}

	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	/*
	Day day_of_week(const Date& d)
	{
		// ...
	}

	Date next_Sunday(const Date& d)
	{
		// ...
	}

	Date next_weekday(const Date& d)
	{
		// ...
	}
	*/

}	// Chrono