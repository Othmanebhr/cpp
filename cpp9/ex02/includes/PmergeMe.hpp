#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <cctype>

class PmergeMe
{
	public:
	PmergeMe() {}; //a voir si on init pas vector et deque;
	PmergeMe(const PmergeMe& cpy);
	PmergeMe& operator=(const PmergeMe& rhs);
	~PmergeMe() {};

	bool getInput(char *str);
	
	bool parseInput(std::string input);

	private:
	std::vector<int> _vector;
	std::deque<int> _deque;
};