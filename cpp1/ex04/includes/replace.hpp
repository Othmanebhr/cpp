#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

class replace
{
private:
    std::string _find;
    std::string _replace;

public:
    replace(std::string find, std::string replace);
    ~replace();
    std::string get_find() const;
    std::string get_replace() const;
};

#endif