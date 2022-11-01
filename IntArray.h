#pragma once

#include <exception>
#include <iostream>
#include <cstdint>

class bad_range final : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Out of range!\a\n";
	}
};


class bad_length final : public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Unlogic length!\a\n";
	}
};



class IntArray
{
public:
	IntArray() = default;
	IntArray(int32_t length);
	IntArray(int32_t length, int32_t val);
	~IntArray();


	IntArray(IntArray const& other);
	IntArray& operator=(IntArray const& other);

	IntArray(IntArray const&& other) = delete;
	IntArray& operator=(IntArray const&& other) = delete;

	auto operator[](int32_t index)       -> int&;
	auto operator[](int32_t index) const -> int const&;

private:
	int32_t    _length{};
	int*       _arr{};
	
	auto erase()                         -> void;
	auto realloc(int32_t newLength)      -> void;

public:	
	auto resize(int32_t newLength)       -> void;
	auto insert(int32_t index, int val)  -> void;
	auto push_back(int32_t value)        -> void;
	auto push_front(int32_t value)       -> void;
	auto remove(int32_t index)           -> void;
	auto clear()                         -> void;
	auto size() const                    -> int32_t;

};



