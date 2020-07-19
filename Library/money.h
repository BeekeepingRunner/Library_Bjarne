#pragma once
#include <iostream>

// Class for calculations involving dollars and cents.
// Arithmetic accurate to the last cent using 4/5 rounding rule.
// Input and output in dollars and cents, internal representation in cents.
class Money {

public:

	Money(long int cents = 0);

	long int getCents() const { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

private:

	long int m_cents;
};

double toDollars(long int cents);
long int toCents(double dollars);

// TODO
Money operator+(const Money& money1, const Money& money2);
Money operator-(const Money& money1, const Money& money2);
Money operator*(const Money& money1, const Money& money2);
Money operator/(const Money& money1, const Money& money2);
// ****

std::ostream& operator<<(std::ostream& out, const Money& money);
std::istream& operator>>(std::istream& in, Money& money);