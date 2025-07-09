#pragma once

#include <iostream>
#include <cstdlib>
#include <stack>

class RPN
{
	public:
	RPN(std::string calcul) : _calcul(calcul) {};
	RPN(const RPN& cpy) { *this = cpy; };
	RPN& operator=(const RPN& rhs)
	{
		if (this != & rhs)
		{
			this->_contain = rhs._contain;
			this->_calcul = rhs._calcul;
		}
		return *this;
	}
	~RPN() {};

	/*member fuction*/
	bool calculate();

	private:
	std::stack<int> _contain;
	std::string _calcul;

};
