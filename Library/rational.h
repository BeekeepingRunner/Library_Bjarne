#pragma once

#include <iostream>

class Rational {

public:

	Rational(int num = 0, int den = 1)
		: m_numerator{ num }, m_denominator{ den }
	{
	}

	int getNumerator() const { return m_numerator; }
	int getDenominator() const { return m_denominator; }

	Rational& operator=(Rational& otherRational);

private:

	int m_numerator;
	int m_denominator;
};

std::ostream& operator<<(std::ostream& os, const Rational& rational);