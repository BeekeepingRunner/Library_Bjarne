#pragma once
#include <iostream>

// Class for calculations involving dollars and cents.
// Arithmetic accurate to the last cent using 4/5 rounding rule.
// Input and output in dollars and cents, internal representation in cents.
class Money {

public:
	// for future uses
	enum class currency {
		USD,
		PLN,
		DKK,
		EUR
	};

	// For dollars
	Money(long int cents = 0);
	// Money(currency curr, float quant);

	long int getCents() const { return m_cents; }
	void setCents(int cents) { m_cents = cents; }

	currency getCurrency() const { return m_currency; }

private:

	long int m_cents;
	currency m_currency;
};

double toDollars(long int cents);
long int toCents(double dollars);

// To improve with other currencies in the future
Money operator+(const Money& money1, const Money& money2);
Money operator-(const Money& money1, const Money& money2);
Money operator*(const Money& money1, const Money& money2);
Money operator*(const Money& money, long int elem);
Money operator*(long int elem, const Money& money);
Money operator/(const Money& money1, const Money& money2);
//

std::ostream& operator<<(std::ostream& out, const Money& money);
// std::istream& operator>>(std::istream& in, Money& money);