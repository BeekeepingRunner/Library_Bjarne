#pragma once
#include <iostream>

class Patron {

public:

	Patron(std::string userName, std::string libCardNum, int libFees);

	std::string getUserName()		const { return m_userName; }
	std::string getUserLibCardNum() const { return m_libCardNum; }
	int			getLibFees()		const { return m_libFees; }

	void setLibFee(int fee) { m_libFees += fee; }
	bool hasFee() const { (m_libFees > 0) ? true : false; }

private:

	std::string m_userName;
	std::string m_libCardNum;
	int			m_libFees;
};