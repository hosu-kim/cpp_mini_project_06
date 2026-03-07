#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib> // strtod
# include <climits> // INT_MIN, INT_MAX
# include <cmath> // isnan, isinf
# include <iomanip> // setprecision

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();

	public:
		static void	convert(const std::string& literal);
};

#endif