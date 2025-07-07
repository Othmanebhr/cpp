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
	static void fordJohnsonSortVector(std::vector<int>& vec);
	static void fordJohnsonSortDeque(std::deque<int>& deque);
	
	static std::vector<int> generateJabobsthalsequence(int n);

	static void binaryInsertion(std::vector<int>& container, int value, int end);


	private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	double _vectorTime;
	double _dequeTime;
};