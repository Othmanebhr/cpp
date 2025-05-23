#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

class Data
{
	public:
	Data(int n, std::string s) : nb(n), str(s) {};
	Data(const Data& cpy) { (void)cpy; };
	Data& operator=(const Data& rhs) { (void)rhs; return *this; }
	~Data() {};

	int nb;
	std::string str;
	private:
};

class Serializer
{
	public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

	private:
	Serializer();
	Serializer(const Serializer& cpy);
	Serializer& operator=(const Serializer& rhs);
	~Serializer();
	
};

#endif