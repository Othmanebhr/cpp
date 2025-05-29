#include "../includes/iter.hpp"

class Awesome
{
	public:
	Awesome() : _n(42) {}
	int get() const {return _n;}

	private:
	int _n;

};
std::ostream& operator<<(std::ostream& o, const Awesome& rhs) {o << rhs.get(); return o;}

template <typename T>
void print(T &x) {std::cout << x << std::endl; return;}

int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);

	return 0;
}


// void ft_toupper(char &c)
// {
// 	c = std::toupper(c);
// }

// int main()
// {
// 	char str[] = "test";
// 	std::cout << "before: " << str << std::endl;
// 	::iter(str, strlen(str), ft_toupper);
// 	std::cout << "After: " << str << std::endl;
// }