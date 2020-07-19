#include "money.h"

Money::Money(long int cents)
	: m_cents{ cents }
{

}

// assume that cents number is correct
double toDollars(long int cents)
{
	return cents / 100.0;
}

// assume that dollars number is correct
long int toCents(double dollars)
{
	// unsafe conversion, to be improved in the future
	return dollars * 100;
}

Money operator+(const Money& money1, const Money& money2)
{
	return Money{ money1.getCents() + money2.getCents() };
}

Money operator-(const Money& money1, const Money& money2)
{
	return Money{ money1.getCents() - money2.getCents() };
}

Money operator*(const Money& money1, const Money& money2)
{
	return Money{ money1.getCents() * money2.getCents() };
}

Money operator/(const Money& money1, const Money& money2)
{
	// A precise result of division.
	double outCents{ static_cast<double>(money1.getCents()) / 
					static_cast<double>(money2.getCents()) };
	// The Result can contain a fraction of 1 cent, so we have to round it
	// using a 4/5 rounding rule.

	// holds the first digit after decimal point
	int afterDecPoint{ static_cast<int>(outCents * 10) % 10 };

	if (afterDecPoint < 5)
		return Money{ static_cast<int>(outCents) };
	else
		return Money{ static_cast<int>(outCents) + 1 };
}

std::ostream& operator<<(std::ostream& out, const Money& money)
{
	out << '$' << toDollars(money.getCents());
	return out;
}

// TODO
std::istream& operator>>(std::istream& in, Money& money)
{
	double dollars{};
	in >> dollars;
	money.setCents(toCents(dollars));
	return in;
}