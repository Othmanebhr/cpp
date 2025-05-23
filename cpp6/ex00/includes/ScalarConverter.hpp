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

	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isPseudoLiteral(const std::string& literal);

	static void convFromChar(char value);
	static void convFromInt(int value);
	static void convFromFloat(float value);
	static void convFromDouble(double value);
	static void handleLiteralValue(std::string& literal);
};

#endif