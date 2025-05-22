#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	public:
	static void convert(const std::string& literal);

	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& cpy);
	ScalarConverter& operator=(const ScalarConverter& rhs);
	~ScalarConverter();
};

#endif