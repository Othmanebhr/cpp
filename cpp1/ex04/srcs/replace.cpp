#include "../includes/replace.hpp"

replace::replace(std::string find, std::string replace) : _find(find), _replace(replace){}

replace::~replace(){}

std::string replace::get_find() const
{
    return this->_find;
}

std::string replace::get_replace() const
{
    return this->_replace;
}