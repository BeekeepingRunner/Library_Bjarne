#include "rational.h"

Rational& Rational::operator=(Rational& otherRational)
{

}

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
	os << rational.getNumerator() << '/' << rational.getDenominator();
	return os;
}

