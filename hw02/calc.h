#pragma once

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <stdexcept>
#include <string>

class Calculator {
private:
	int64_t res;
	std::istringstream in;

	bool makeSumSub(std::istringstream& in, int64_t& arg);
	bool makeMulDiv(std::istringstream& in, int64_t& arg);
	bool getArg(std::istringstream& in, int64_t& arg);

public:
	Calculator(std::string const& str);
	int64_t getRes();
};
