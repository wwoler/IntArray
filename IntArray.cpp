#include "IntArray.h"

IntArray::IntArray(int32_t length) :
	_length(length)
{
	if (_length < 0)
		throw bad_length();

	if (_length > 0)
		_arr = new int[length] {};
}

IntArray::IntArray(int32_t length, int32_t val) :
	_length(length)
{
	if (_length < 0)
		throw bad_length();

	if (_length > 0)
	{
		_arr = new int[_length] {};

		for (int i = 0; i < _length; ++i)
			_arr[i] = val;
	}

}

IntArray::~IntArray()
{
	delete[]_arr;
}

IntArray::IntArray(IntArray const& other)
{
	if (this == &other)
		return;

	_length = other._length;
	_arr = new int[_length] {};

	for (int i{ 0 }; i < _length; ++i)
		_arr[i] = other[i];


}

IntArray& IntArray::operator=(IntArray const& other)
{
	if (this == &other)
		return *this;

	erase();


	_length = other._length;
	_arr = new int[_length];

	for (int i{ 0 }; i < _length; ++i)
		_arr[i] = other[i];

}

auto IntArray::operator[](int32_t index) -> int&
{
	if (index < 0 || index >= _length)
		throw bad_range();

	return _arr[index];

}

auto IntArray::operator[](int32_t index) const -> int const&
{
	if (index < 0 || index >= _length)
		throw bad_range();

	return _arr[index];
}


auto IntArray::erase() -> void
{
	delete[] _arr;

	_length = 0;
	_arr = nullptr;
}


auto IntArray::realloc(int32_t newLength) -> void
{
	if (newLength < 0)
		throw bad_length();

	_length = newLength;
	_arr = new int[_length] {};

}

auto IntArray::resize(int32_t newLength) -> void
{
	if (newLength < 0)
		throw bad_length();

	int count_to_copy{ (newLength > _length) ? _length : newLength };
	IntArray temp = *this;
	erase();
	realloc(newLength);


	for (int i{ 0 }; i < count_to_copy; ++i)
		_arr[i] = temp[i];

}


auto IntArray::insert(int32_t index, int val) -> void
{
	if (index < 0 || index > _length)
		throw bad_range();

	int* newArr = new int[_length + 1];

	for (int before{ 0 }; before < index; ++before)
		newArr[before] = _arr[before];


	for (int after{ index }; after < _length; ++after)
		newArr[after + 1] = _arr[after];

	newArr[index] = val;

	delete[] _arr;
	_arr = newArr;
	++_length;

}

auto IntArray::push_back(int32_t value) -> void
{
	insert(_length, value);
}


auto IntArray::push_front(int32_t value) -> void
{
	insert(0, value);
}


auto IntArray::remove(int32_t index) -> void
{
	if (index < 0 || index >= _length)
		throw bad_range();

	if (_length == 1)
	{
		erase();
		return;
	}

	int* newArr = new int[_length - 1]{};

	for (int befor{ 0 }; befor < index; ++befor)
		newArr[befor] = _arr[befor];

	for (int after{ index + 1}; after < _length; ++after)
		newArr[after - 1] = _arr[after];


	delete[]_arr;
	--_length;
	_arr = newArr;
}


auto IntArray::clear() -> void
{
	delete[]_arr;
	_arr = new int[_length] {};
}



auto IntArray::size() const -> int32_t
{
	return _length;
}




