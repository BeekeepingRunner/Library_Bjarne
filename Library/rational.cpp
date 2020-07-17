#include "rational.h"

double Rational::toDouble() const
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
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