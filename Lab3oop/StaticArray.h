#pragma once

#ifndef STATICARRAY_H
#define STATICARRAY_H

#include <stdexcept>

class StaticArray {
public:
	static const size_t CAPACITY = 10;
private:
	char arr[CAPACITY ] = { 0 };
	size_t arrSize = 0;
public:
	StaticArray();
	StaticArray(const StaticArray& other);
	~StaticArray();

	bool resize(size_t newSize);
	bool push_back(char c);
	bool set_value(size_t index, char c);

	size_t size() const;
	char get_value(size_t index) const;
	int find(char c) const;

	StaticArray& operator=(const StaticArray& other);
	char& operator[](size_t ind);
};

//#include "StaticArray.cpp"

#endif