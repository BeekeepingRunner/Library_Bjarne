#pragma once

#include <iostream>

// Class for calculations involving dollars and cents.
// Arithmetic accurate to the last cent using 4/5 rounding rule.
// Input and output in dollars and cents, internal representation in cents.
class Money {

public:

	Money(int cents = 0);

	long int getCents() const { return m_cents; }

private:

	long int m_cents;
};
// TODO

double toDollars(long int cents);
long int toCents(double dollars);

std::ostream& operator<<(std::ostream& out, const Money& money);
std::istream& operator>>(std::istream& in, Money& money);