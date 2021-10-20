#ifndef STATICARRAY_CPP
#define STATICARRAY_CPP

#include "StaticArray.h"

StaticArray::StaticArray() {}

StaticArray::StaticArray(const StaticArray &other) {}

StaticArray::~StaticArray() {}

bool StaticArray::resize(size_t newSize) {
	if (newSize > CAPACITY)
		arrSize = CAPACITY;
	else
		arrSize = newSize;

	return newSize <= CAPACITY;
}

bool StaticArray::push_back(char c) {
	if (resize(this->size() + 1) == false)
		return false;
	set_value(size() - 1, c);
	return true;
}

bool StaticArray::set_value(size_t ind, char c) {
	if (ind < CAPACITY) {
		arr[ind] = c;
		return true;
	}
	return false;
}

size_t StaticArray::size() const {
	return arrSize;
}

char StaticArray::get_value(size_t ind) const {
	return arr[ind];
}

int StaticArray::find(char c) const {
	for (size_t i = 0; i < size(); i++) {
		if (arr[i] == c)
			return i;
	}
	return -1;
}

StaticArray& StaticArray::operator=(const StaticArray& other) {
	if (this == &other)
		return *this;

	if (size() != other.size()) {         // resource in *this cannot be reused
		resize(0);
		for (size_t i = 0; i < other.size(); i++)
			push_back(other.get_value(i));
;	}
	return *this;
}

char& StaticArray::operator[](size_t ind) {
	return arr[ind];
}

#endif