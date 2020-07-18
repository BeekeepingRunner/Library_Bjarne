#include "money.h"

double toDollars(long int cents)
{
	double dollars{ cents / 100.0 };
	dollars += (cents % 100) / 100.0;

	return dollars;
}

long int toCents(double dollars)
{

	return 1;
}