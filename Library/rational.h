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

	void setNumerator(int num) { m_numerator = num; }
	void setDenominator(int den) { m_denominator = den; }

	double toDouble() const;

	void reduce(); //TODO

	// Rational& operator=(Rational& otherRational);
	// Rational& operator+(Rational& rational2);
	// Rational operator-(Rational rational2);
	// Rational operator*(Rational rational2);
	//Rational operator/(Rational rational2);
	//bool operator==(Rational rational2);

private:

	int m_numerator;
	int m_denominator;
};

std::ostream& operator<<(std::ostream& os, const Rational& rational);

Rational operator+(Rational elem1, Rational elem2);
Rational operator-(Rational elem1, Rational elem2);
Rational operator*(Rational elem1, Rational elem2);
Rational operator/(Rational elem1, Rational elem2);
bool operator==(Rational elem1, Rational elem2);