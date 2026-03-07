/*
This project is about learning C++ type casts using
1. `static_cast`: most used
2. `dynamic_cast`: used to convert the type of classes
3. `reinterpret_cast`: forced conversion
4. `const_cast`: used to temporarily remove the const property

And what the difference between using them and using C type casting (`(type)variable`)
The difference is 
1. C-style casting allows dangerous convert for e.g., from pointer to int
but C++ type casts checks if the type casting is really possible
2. easy to seach: when you search just `int` there're a lot of int keyword in the code,
   so it's difficult to find where I cast variables.
3. Clarify the intent: conveys the intent of type conversion (static_..., dynanic_...))

*/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <cmath>
# include <cstdlib>

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