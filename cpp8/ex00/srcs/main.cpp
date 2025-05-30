#include "../includes/easyfind.hpp"

int main()
{
	try
	{
		std::cout << "Test just for vectors: " << std::endl;
		std::vector<int> vec;
		for (size_t i = 1; i <= 10; i++)
			vec.push_back(i);
		std::cout << "vector contain: " << std::endl;
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Good test : Finding <int> element in a vector container: " << std::endl;
		std::vector<int> vec;
		vec.push_back(56);
		vec.push_back(89);
		vec.push_back(85);
		vec.push_back(98);
		std::cout << "Vector contain:" << std::endl;
		for (size_t j = 0; j < vec.size(); j++)
			std::cout << vec[j] << " ";
		std::cout << std::endl;
		std::cout << "value searched = 89" << std::endl;
		std::cout << "Value found : " << std::endl;
		std::vector<int>::iterator it = easyfind(vec, 89);
		std::cout << "'" << *it << "'" << ", at position: " << (it - vec.begin()) <<std::endl;

		std::cout << std::endl;
		std::cout << "test perso: " << "*it = " << *it << " it = non affichable " << " &it = " << &it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Bad test : Finding <int> element in a vector container: " << std::endl;
		std::vector<int> vec;
		vec.push_back(56);
		vec.push_back(89);
		vec.push_back(85);
		vec.push_back(98);
		std::cout << "Vector contain:" << std::endl;
		for (size_t j = 0; j < vec.size(); j++)
			std::cout << vec[j] << " ";
		std::cout << std::endl;
		std::cout << "value searched = 77" << std::endl;
		std::cout << "Value found : " << std::endl;
		std::vector<int>::iterator it = easyfind(vec, 77);
		std::cout << "'" << *it << "'" << ", at position: " << (it - vec.begin()) <<std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Good test : Finding <char> element in a vector container: " << std::endl;
		std::vector<char> charTest;
		charTest.push_back('T');
		charTest.push_back('e');
		charTest.push_back('s');
		charTest.push_back('t');
		std::cout << "Vector contain:" << std::endl;
		for (size_t j = 0; j < charTest.size(); j++)
			std::cout << charTest[j];
		std::cout << std::endl;
		std::cout << "value searched = 'T'" << std::endl;
		std::vector<char>::iterator it = easyfind(charTest, 'T');
		std::cout << "Value found : " << std::endl;
		std::cout << "'" << *it << "'" << ", at position: " << (it - charTest.begin()) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << "Bad test : Finding <char> element in a vector container: " << std::endl;
		std::vector<char> charTest;
		charTest.push_back('T');
		charTest.push_back('e');
		charTest.push_back('s');
		charTest.push_back('t');
		std::cout << "Vector contain:" << std::endl;
		for (size_t j = 0; j < charTest.size(); j++)
			std::cout << charTest[j];
		std::cout << std::endl;
		std::cout << "value searched = 'Q'" << std::endl;
		std::vector<char>::iterator it = easyfind(charTest, 'Q');
		std::cout << "Value found : " << std::endl;
		std::cout << "'" << *it << "'" << ", at position: " << (it - charTest.begin()) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}