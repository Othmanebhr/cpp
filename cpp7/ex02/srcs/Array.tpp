/*Constructor*/

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << "Default constructor called: creating a NULL array" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) //Verif unsigned
{
	if (static_cast<int>(n) < 0)
		throw InvalidArgs();
	this->_size = n;
	if (n > 0)
		_array = new T[n];
	else
		_array = NULL;
}

template <typename T>
Array<T>::Array(const Array& cpy) : _array(NULL), _size(0)
{
	*this = cpy;
}

/*Operator*/

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		if (this->_array)
			delete[] _array;
		this->_size = rhs._size;
		if (rhs._size > 0)
		{
			this->_array = new T[rhs._size];
			for (size_t i = 0; i < rhs._size; i++)
				this->_array[i] = rhs._array[i];
		}
		else
			this->_array = NULL;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= _size || !_array)
		throw OutOfArray();
	return _array[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= _size || !_array)
		throw OutOfArray();
	return _array[idx];
}

/*Destructor*/

template <typename T>
Array<T>::~Array()
{
	if (_array)
		delete[] _array;
}

/*Function*/

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}

/*Exceptions*/

template <typename T>
const char *Array<T>::OutOfArray::what() const throw()
{
	return "error: Out of array";
}

template <typename T>
const char *Array<T>::InvalidArgs::what() const throw()
{
	return "error: invalid args";
}