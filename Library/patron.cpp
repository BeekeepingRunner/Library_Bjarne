#include "patron.h"

// TODO:
// 1. Input data validation

Patron::Patron(std::string userName, std::string libCardNum, int libFees = 0)
	: m_userName{ userName }, m_libCardNum{ libCardNum }, m_libFees{ libFees }
{

}

bool operator==(const Patron& p1, const Patron& p2)
{
	return p1.getUserName() == p2.getUserName()
		&& p1.getUserLibCardNum() == p2.getUserLibCardNum()
		&& p1.getLibFees() == p2.getLibFees();
}

bool operator!=(const Patron& p1, const Patron& p2)
{
	return !(p1 == p2);
}