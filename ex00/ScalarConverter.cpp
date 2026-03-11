#include "ScalarConverter.hpp"

// Orthodox canonical form 
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { *this = src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	(void)src;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& literal) {
	// this 'if' condition handles special values
	if (literal == "nan" || literal == "nanf" ||
		literal == "inf" || literal == "+inf" || literal == "-inf" ||
		literal == "inff" || literal == "+inff" || literal == "-inff") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			// find(): 몇 번째 인덱스에 처음 나타나는지
			// 못찾으면 npos를 반환한다
			if (literal.find("ff") != std::string::npos || literal == "nanf") {
				std::cout << "float: " << literal << std::endl;
				// substr(): 문자열을 자른다 substr(시작 인덱스, 길이)
				// 그러므로 +inff를 입력했을 때 double에서는 마지막 f가 잘린다.
				std::cout << "double: " << literal.substr(0, literal.length() -1) << std::endl;
			} else {
				// +inf를 입력했을 때 float에서는 f가 추가된다.
				std::cout << "float: " << literal << "f" << std::endl; // float e.g., +inf => + inff
				std::cout << "double: " << literal << std::endl; // double e.g., +inf => +inf
			}
			return ;
		}

	// conversion (literal -> double)
	char* endptr = NULL;
	// strtod(): str to double; 문자열을 double 타입의 실수로 바꿔줌.
	// strtod(문자열, 변환이 멈춘 지점의 주소)
	// vv: finds the last char of literal
	double value = std::strtod(literal.c_str(), &endptr);

	// Single character exception handling (e.g., 'a')
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		value = static_cast<double>(literal[0]); // ('a' = 97.0)
	} else if (*endptr != '\0' && std::string(endptr) != "f") { // e.g. 42abc, 42.42abc
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}

	// printing each types on the console
	// 1. CHAR CONVERSION
	std::cout << "char: ";
	// isnan(): is not a number? returns true or false
	// isinf(): is infinite (overflow)? returns true or false
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	// isprint(): is printable? returns true or false
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
// -----------------------------------------------------------------------------
	// 2. INT CONVERSION
	std::cout << "int: ";
	// numeric_limits<type>::min()/max): returns the min/max value which the type can have
	if (value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>:: max() ||
		// int can't have NaN
		std::isnan(value))
		std::cout << "impossible" << std::endl;
	else // success
		std::cout << static_cast<int>(value) << std::endl;
// -----------------------------------------------------------------------------
	// 3. FLOAT & DOUBLE CONVERSION
	// std::fixed + std::setpresicion:
	//   e.g., if value is 42 -> after: 42.0
	//         if value is 42.42 -> after: 42.4
	std::cout << std::fixed << std::setprecision(1); // this code sets up input mode. doesn't print anything.
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl; // +f => convention
	std::cout << "double: " << value << std::endl;
}
