#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal) {
	double	d;
	char*	endPtr = NULL;

	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		d = static_cast<double>(literal[0]);
	} else {
		d = std::strtod(literal.c_str(), &endPtr);

		if (*endPtr != '\0' && !(*endPtr == 'f' && *(endPtr + 1) == '\0')) {
			if (literal != "nan" && literal != "nanf" &&
				literal != "inf" && literal != "inff" &&
				literal != "-inf" && literal != "-inff") {
				std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
				return;
			}
		}
	}
	
}