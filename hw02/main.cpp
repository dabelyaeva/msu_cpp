
#include "calc.h"

bool Calculator::makeSumSub(std::istringstream& in, int64_t& arg) {
	int64_t arg1;
	if (!makeMulDiv(in, arg1))
		return false;
	char symbol;
	while ((in >> symbol) && (symbol == '+' || symbol == '-')) {
		int64_t arg2;
		if (!makeMulDiv(in, arg2))
			return false;
		if (symbol == '+')
			arg = arg1 + arg2;
		if (symbol == '-')
			arg = arg1 - arg2;
	}
	return true;
}

bool Calculator::makeMulDiv(std::istringstream& in, int64_t& arg) {
	int64_t arg1;
	if (!getArg(in, arg1))
		return false;
	char symbol;
	while ((in >> symbol) && (symbol == '*' || symbol == '/')) {
		int64_t arg2;
		if (!getArg(in, arg2))
			return false;
		if (symbol == '*')
			arg1 *= arg2;
		else if (symbol == '/') {
			if (arg2 == 0)
				return false;
			arg = arg1 / arg2;
		}
	}
	in.putback(symbol);
	return true;
}
	
bool Calculator::getArg(std::istringstream& in, int64_t& arg) {
	char sign;
	if (!(in >> sign))
		return false;
	int64_t number;
	if (sign == '-') {
		if (!(in >> number))
			return false;
		arg = -number;
		return true;
	}
	else {
		if (!isdigit(sign))
			return false;
		in.putback(sign);
		in >> number;
		arg = number;
		return true;
	}
}

Calculator::Calculator(std::string const& str) : res(0), in(str) {
	if (!makeSumSub(in, res))
		throw std::invalid_argument("Error!");
}
	
int64_t Calculator::getRes() {
	return this->res;
}


int main() {
	try {
		std::string in;
		std::cin >> in;
		Calculator calc(in);
		std::cout << calc.getRes();
	}
	catch (std::exception& e) {
		std::cout << "Error!";
		return 1;
	}
	return 0;
}