#include "../includes/replace.hpp"

static bool lil_parse(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Please use it like this: ./replace <filename> <str_to_find> <str_to_replace_by>." << std::endl;
		return false;
	}
	if (strlen(av[2]) == 0)
	{
		std::cout << "Error: string to find cannot be empty." << std::endl;
		return false;
	}
	if (strlen(av[3]) == 0)
	{
		std::cout << "Error: string to replace cannot be empty." << std::endl;
		return false;
	}
	return true;
}

int main(int ac, char **av)
{
	if (!lil_parse(ac, av))
		return 1;

	//open
	std::ifstream infile(av[1]);
	if (!infile.is_open())
	{
		std::cout << "Error: cannot open file" << std::endl;
		return 1;
	}
	std::string outfileName = std::string(av[1]) + ".replace";
	std::ofstream outfile(outfileName.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error: cannot create outfile" << std::endl;
		infile.close();
		return 1;
	}

	//alg
	replace replace(av[2], av[3]);
	std::string content_infile((std::istreambuf_iterator<char>(infile)), 
							  std::istreambuf_iterator<char>());
	std::string find = replace.get_find();
	std::string replace_by = replace.get_replace();
	for (size_t pos = 0; (pos = content_infile.find(find, pos)) != std::string::npos; pos += replace_by.length())  // Change int to size_t
	{
		content_infile.erase(pos, find.length());
		content_infile.insert(pos, replace_by);
	}
	outfile << content_infile;
	
	//close
	infile.close();
	outfile.close();
	return 0;
}