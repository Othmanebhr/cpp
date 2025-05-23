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

	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length() - 1; i++)//
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t i = 0;
	bool hasDot = false;

	if (literal.empty())
		return false;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) //
{
	return literal == "nan" || literal == "nanf" || literal == "inf" || literal == "+inf" ||
			literal == "-inf" || literal == "inff" || literal == "+inff" || literal == "-inff";
}

void ScalarConverter::convFromChar(char value)
{
	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: '" << static_cast<int>(value) << "'" << std::endl;
	std::cout << "float: '" << static_cast<float>(value) << ".0f'" << std::endl;
	std::cout << "double: '" << static_cast<double>(value) << ".0'" << std::endl;
}

void ScalarConverter::convFromInt(int value)
{
	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: '" << value << "'" << std::endl;
	std::cout << "float: '" << static_cast<float>(value) << ".0f'" << std::endl;
	std::cout << "double: '" << static_cast<double>(value) << ".0'" << std::endl;
}

void ScalarConverter::convFromFloat(float value)
{
	/*char*/
	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 && value <= 127)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	/*int*/
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || value != value) //Valeur NaN != NaN
		std::cout << "int: impossible." << std::endl;
	else
		std::cout << "int: '" << static_cast<int>(value) << "'" << std::endl;

	/*float/double*/
	if (value - static_cast<int>(value) == 0)//
	{
		std::cout << "float: '" << value << ".0f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(value) << ".0'" << std::endl;
	}
	else
	{
		std::cout << "float: '" << value << "f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(value) << "'" << std::endl;
	}
}

void ScalarConverter::convFromDouble(double value)
{
		/*char*/
	if (value >= 32 && value >= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else if (value >= 0 & value <= 127)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	/*int*/
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || value != value) //Valeur NaN != NaN
		std::cout << "int: impossible." << std::endl;
	else
		std::cout << "int: '" << static_cast<int>(value) << "'" << std::endl;

	/*float/double*/
	if (value - static_cast<int>(value) == 0)//
	{
		std::cout << "float: '" << static_cast<float>(value) << ".0f'" << std::endl;
		std::cout << "double: '" << value << ".0'" << std::endl;
	}
	else
	{
		std::cout << "float: '" << static_cast<float>(value) << "f'" << std::endl;
		std::cout << "double: '" << value << std::endl;
	}
}

void ScalarConverter::handleLiteralValue(std::string& literal)
{
	if (literal[literal.length() - 1] == 'f')
		literal = literal.substr(0, literal.length() - 1);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: '" << literal << "f'" << std::endl;
	std::cout << "double: '" << literal << "'" << std::endl;
}