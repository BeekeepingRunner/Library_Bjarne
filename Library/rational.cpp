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

Rational operator+(Rational elem1, Rational elem2)
{
	Rational outRational{ 1, 1 };
	
	outRational.setNumerator(elem1.getNumerator() * elem2.getDenominator() 
							+ elem2.getNumerator() * elem1.getDenominator());
	outRational.setDenominator(elem1.getDenominator() * elem2.getDenominator());

	return outRational;
}

Rational operator-(Rational elem1, Rational elem2)
{
	Rational outRational{ 1, 1 };

	outRational.setNumerator(elem1.getNumerator() * elem2.getDenominator()
		- elem2.getNumerator() * elem1.getDenominator());
	outRational.setDenominator(elem1.getDenominator() * elem2.getDenominator());

	return outRational;
}

Rational operator*(Rational elem1, Rational elem2)
{
	Rational outRational{ 1, 1 };

	outRational.setNumerator(elem1.getNumerator() * elem2.getNumerator());
	outRational.setDenominator(elem2.getDenominator() * elem2.getDenominator());

	return outRational;
}

Rational operator/(Rational elem1, Rational elem2)
{
	// invert elem2
	int temp{ elem2.getNumerator() };
	elem2.setNumerator(elem2.getDenominator());
	elem2.setDenominator(temp);

	return elem1 * elem2;
}

// TO IMPROVE WITH REDUCE()
bool operator==(Rational elem1, Rational elem2)
{
	return elem1.getNumerator() == elem2.getNumerator()
		&& elem1.getDenominator() == elem2.getDenominator();
}