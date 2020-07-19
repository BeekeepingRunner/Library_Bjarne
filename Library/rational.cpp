#include "rational.h"

double Rational::toDouble() const
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

void Rational::reduce()
{
	int divisor{ gcd(m_numerator, m_denominator) };
	setNumerator(getNumerator() / divisor);
	setDenominator(getDenominator() / divisor);
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
	os << rational.getNumerator() << '/' << rational.getDenominator();
	return os;
}

Rational operator+(const Rational& elem1, const Rational& elem2)
{
	Rational outRational{ 1, 1 };
	
	outRational.setNumerator(elem1.getNumerator() * elem2.getDenominator() 
							+ elem2.getNumerator() * elem1.getDenominator());
	outRational.setDenominator(elem1.getDenominator() * elem2.getDenominator());

	return outRational;
}

Rational operator-(const Rational& elem1, const Rational& elem2)
{
	Rational outRational{ 1, 1 };

	outRational.setNumerator(elem1.getNumerator() * elem2.getDenominator()
		- elem2.getNumerator() * elem1.getDenominator());
	outRational.setDenominator(elem1.getDenominator() * elem2.getDenominator());

	return outRational;
}

Rational operator*(const Rational& elem1, const Rational& elem2)
{
	Rational outRational{ 1, 1 };

	outRational.setNumerator(elem1.getNumerator() * elem2.getNumerator());
	outRational.setDenominator(elem2.getDenominator() * elem2.getDenominator());

	return outRational;
}

Rational operator/(const Rational& elem1, const Rational& elem2)
{
	Rational invertedElem2{};
	invertedElem2.setNumerator(elem2.getDenominator());
	invertedElem2.setDenominator(elem2.getNumerator());

	return elem1 * invertedElem2;
}

bool operator==(const Rational& elem1, const Rational& elem2)
{
	Rational temp1 = elem1;
	Rational temp2 = elem2;
	temp1.reduce();
	temp2.reduce();

	return temp1.getNumerator() == temp2.getNumerator()
		&& temp1.getDenominator() == temp2.getDenominator();
}