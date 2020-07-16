#include "chrono.h"
#include <math.h>

namespace Chrono {

	// Be aware of the default value of the m_monthLength
	Date::Date(int dd, Month mm, int yy)
		: m_day{ dd }, m_month{ mm }, m_year{ yy }, m_monthLength{ monthLength(mm, yy) }
	{
		if (!isDate(dd, mm, yy))
			throw Invalid{};
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
	void Date::addDay(int n)
	{
		if (n < 0)
			throw std::runtime_error("Date: addDay(): argument must be a non-negative integer");

		m_day = m_day + n;

		while (m_day > m_monthLength)
		{
			// days remaining to add
			m_day = m_day - m_monthLength;
			// we have to change a month to the next one
			if (m_month == Month::dec)
			{
				++m_year;
				m_month = Month::jan;
			}
			else
				m_month = static_cast<Month>(static_cast<int>(m_month) + 1);

			// setting the new value of m_monthLength
			setMonthLength(); // doesn't rely on m_days so it is safe
		}
	}

	// Adds n months to the current date.
	// Takes leap years and amounts of days in particular months into consideration.
	// Fully functional function, i'm proud of it.
	void Date::addMonth(int n)
	{
		if (n < 0) throw std::runtime_error("Date: addMonth(): argument must be a non-negative integer");

		int intMonth{ static_cast<int>(m_month) + n }; // calculation help

		int yearsPassed{ 0 };
		while (intMonth > 12)
		{
			++yearsPassed;
			intMonth -= 12;
		}
		m_year += yearsPassed;

		int prevMonthLen{ m_monthLength };
		m_month = static_cast<Month>(intMonth);	// back to the Month form
		setMonthLength();						// setting a length of a new Month

		// Obtained month can have 28, 29, 30 or 31 days
		if (m_day > m_monthLength)
		{
			// we encountered a month that has less days than the previous one
			// so we change a month again to the next one
			m_day = m_day - m_monthLength;
			// we can be sure that we didn't jump from December to January
			// so it is safe to do this:
			m_month = static_cast<Month>(static_cast<int>(m_month) + 1);
			setMonthLength(); // setting the ultimate month length due to the change of m_month
		}
	}

	void Date::addYear(int n)
	{
		if (m_month == Month::feb && m_day == 29 && !isLeapYear(m_year + n)) {
			m_month = Month::mar;
			m_day = 1;
		}
		m_year += n;
	}

	// Automatically sets amount of days in a month
	// based on m_month and m_year of a Date object.
	// Must be called when there is a modification of m_month or m_year.
	void Date::setMonthLength()
	{
		m_monthLength = monthLength(m_month, m_year);
	}

	// helper functions:

	bool isDate(int dd, Month mm, int yy)
	{
		// assume that y is valid
		if (dd <= 0) return false;

		if (mm < Month::jan || Month::dec < mm) return false;

		if (monthLength(mm, yy) < dd) return false;

		if (yy < MIN_YEAR || MAX_YEAR < yy)
			return false;

		return true;
	}

	bool isLeapYear(int y)
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

	// Returns an amount of days in a given month, regarding leap years.
	int monthLength(Month month, int year)
	{
		switch (month)
		{
		case Month::feb:
			if (isLeapYear(year))
				return 29;
			else
				return 28;
		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			return 30;
		default:
			return 31;
		}
	}

	bool operator==(const Date& a, const Date& b)
	{
		return (a.getYear() == b.getYear())
			&& (a.getMonth() == b.getMonth())
			&& (a.getDay() == b.getDay());
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

	// Ask for a date in the following format: (dd, mm, yy)
	std::istream& operator>>(std::istream& is, Date& date)
	{
		int yy, mm, dd;
		char ch1, ch2, ch3, ch4;

		is >> ch1 >> dd >> ch2 >> mm >> ch3 >> yy >> ch4;

		if (!is) return is;

		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{
			is.clear(std::ios_base::failbit);
			return is;
		}

		date = Date(dd, static_cast<Month>(mm), yy);

		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Day& day)
	{
		switch (day)
		{
		case Day::sunday:
			os << "Sunday";
			break;
		case Day::monday:
			os << "Monday";
			break;
		case Day::tuesday:
			os << "Tuesday";
			break;
		case Day::wednesday:
			os << "Wednesday";
			break;
		case Day::thursday:
			os << "Thursday";
			break;
		case Day::friday:
			os << "Friday";
			break;
		case Day::saturday:
			os << "Saturday";
			break;
		}

		return os;
	}


	// Determines a day of the week for a given Date using the Zeller's Rule
	Day day_of_week(const Chrono::Date& date)
	{
		// Day of the Month
		int k{ date.getDay() };
		// Month number
		// Warning: for Zeller's Rule we start counting Months from March (1) to February(12)
		int m{ static_cast<int>(date.getMonth()) - 2 };
		int year{ date.getYear() };
		if (m == 0) { // february
			m = 12;
			--year;
		}
		if (m == -1) { // january
			m = 11;
			--year;
		}
		// last two digits of the year (regarding new month counting)
		int d{ year % 100 };
		// first two digits of the year (century)
		int c{ year / 100 };
		// formula
		double f{ k + floor((13 * m - 1) / 5.0) + d
			+ floor(d / 4.0) + floor(c / 4.0) - 2 * c };

		int remainder{ static_cast<int>(f) % 7 };
		// if a remainder is negative we have to find the 
		// greatest multiple of 7 that is LESS than f
		// e.g. if f = -17, remainder = 4 because -21 + 4 = -17
		if (remainder < 0)
			remainder += 7;

		// change remainder to the day of the month (Sunday == 0)
		return static_cast<Day>(remainder);
	}

	Date next_workday(const Chrono::Date& date)
	{
		Day currDay{ day_of_week(date) };
		Date nextWorkday{ date }; // to be modified

		switch (currDay)
		{
		case Day::friday:
			nextWorkday.addDay(3);
			return nextWorkday;
		case Day::saturday:
			nextWorkday.addDay(2);
			return nextWorkday;
		default:
			nextWorkday.addDay(1);
			return nextWorkday;
		}
	}

	int week_of_year(const Chrono::Date& date)
	{
		// 1st, naive method
		/*
		int week{ 1 };
		Date iDate{ 1, Month::jan, date.getYear() };
		int i{ 0 };
		while (iDate != date)
		{
			iDate.addDay(1);
			++i;
			if (i == 7)
			{
				i = 0;
				++week;
			}
		}
		return week;
		*/

		// 2nd method
		// We have to count days from 1st of jan to the current date
		int currMonth{ 1 }; // jan
		bool longerMonth{ true }; // jan has 31 days
		int days{ 0 };
		while (currMonth != static_cast<int>(date.getMonth()))
		{
			if (currMonth == 8)
				longerMonth = true;
			
			if (currMonth == 2)
			{
				if (isLeapYear(date.getYear()))
					days += 29;
				else
					days += 28;
			}
			else if (longerMonth)
				days += 31;
			else
				days += 30;

			++currMonth;
			longerMonth = !longerMonth;
		}
		// adds days from the current month
		days += date.getDay();

		return ((days - 1) / 7) + 1; // week of the year number
	}

}	// Chrono