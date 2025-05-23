#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& cpy) { (void)cpy; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {(void)rhs; return *this;}
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& literal)
{
	if (isPseudoLiteral(literal))
	{
		std::string lit = literal;
		handleLiteralValue(lit);
		return ;
	}
	if (isChar(literal))
	{
		char c = literal[0];
		convFromChar(c);
	}
	else if (isInt(literal))
	{
		int i = std::atoi(literal.c_str());
		convFromInt(i);
	}
	else if (isFloat(literal))
	{
		float f = std::atof(literal.c_str());
		convFromFloat(f);
	}
	else if (isDouble(literal))
	{
		double d = std::atof(literal.c_str());
		convFromDouble(d);
	}
	else
	{
		std::cout << "char is impossible." << std::endl;
		std::cout << "int is impossible." << std::endl;
		std::cout << "float is impossible" << std::endl;
		std::cout << "double is impossible" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	size_t i = 0;

	if (literal.empty())
		return false;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	for (; literal[i]; i++)//
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	size_t i = 0;
	bool hasDot = false;

	if (literal.empty() || literal.length() - 1 != 'f')
		return false;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; literal[i]; i++)//
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		if (!std::isdigit(literal[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t i = 0;
	bool hasDot = false;

	if (literal.empty())
		return false;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; literal[i]; i++)//
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		if (!std::isdigit(literal[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	return literal == "nan" || literal == "nanf" || literal == "inf" || literal == "+inf" ||
			literal == "-inf" || literal == "inff" || literal == "+inff" || literal == "-inff";
}