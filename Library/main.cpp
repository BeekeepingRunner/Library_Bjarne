#include <iostream>
#include <vector>

#include "Book.h"

// TODO:
// 1. How to pass input to Book
// 2. How to validate that input

int main()
{
	try {
		Book book{ "123-412-324-A", "title", "author", "copyrightDate" };
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}

	return 0;
}

