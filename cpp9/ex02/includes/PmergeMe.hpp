#pragma once

#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <cctype>
#include <ctime>
#include <limits.h>

class PmergeMe
{
	public:
	PmergeMe() : _vectorTime(0), _dequeTime(0) {}; //a voir si on init pas vector et deque;
	PmergeMe(const PmergeMe& cpy);
	PmergeMe& operator=(const PmergeMe& rhs);
	~PmergeMe() {};

	bool getInput(int ac, char **av);
	
	bool parseInput(std::string input);

	void printContainer(const std::string& name, bool before);
	void displayResults();

	void sortVector();
	void sortDeque();
	static void mergeInsertSortVector(std::vector<int>& vec, int left, int right);
	static void mergeInsertSortDeque(std::deque<int>& deque, int left, int right);

	private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	double _vectorTime;
	double _dequeTime;
};