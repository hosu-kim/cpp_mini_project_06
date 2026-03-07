#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal) {
	// handling special values
	if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
		literal == "+inff" || literal == "-inf" || literal == "-inff") {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (literal.find("ff") != std::string::npos || literal == "nanf") {
				std::cout << "float: " << literal << std::endl;
				std::cout << "double: " << literal.substr(0, literal.length() -1) << std::endl;
			} else {
				std::cout << "float: " << literal << "f" << std::endl;
				std::cout << "double: " << literal << std::endl;
			}
			return ;
		}
	
	// conversion (literal -> double)
	char* endptr = NULL;
	double val = std::strtod(literal.c_str(), &endptr);

	// Single character exception handling (e.g., 'a')
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		val = static_cast<double>(literal[0]);
	} else if (*endptr != '\0' && std::string(endptr) != "f") {
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}

	// printing each types on the console
	// 1. char
	std::cout << "char: ";
	if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(val)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

	// 2. int
	std::cout << "int: ";
	if (val < std::numeric_limits<int>::min() ||
		val > std::numeric_limits<int>:: max() ||
		std::isnan(val))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(val) << std::endl;
	
	// 3. float & double
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << val << std::endl;
}
