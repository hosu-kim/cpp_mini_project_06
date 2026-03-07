#include "ScalarConverter.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		std::cerr << "Example: ./convert 42.0f" << std::endl;
		return 1;
	}

	ScalarConverter:: convert(argv[1]);

	return 0;
}