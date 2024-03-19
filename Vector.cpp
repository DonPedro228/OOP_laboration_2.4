#include "Vector.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

Vector::Vector() : size(0)  {};

Vector::Vector(int arr[], int N)
{
	size = (N > MAX_SIZE) ? MAX_SIZE : N;
	for (int i = 0; i < size; ++i) {
		data[i] = arr[i];
	}
}

Vector::Vector(const Vector& other) : size(other.size)
{
	for (int i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}

Vector::~Vector() {};


Vector& Vector::operator = (const Vector& other)
{
	if (this != &other) {
		size = other.size;
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}
	}

	return *this;
}

ostream& operator << (ostream& os, const Vector& vec)
{
	os << "Element in vector: ";
	for (int i = 0; i < vec.size; i++) {
		os << " " << vec.data[i];
	}
	return os;
}

istream& operator>>(istream& is, Vector& vec) {
	cout << "Enter the size of the vector: ";
	is >> vec.size;

	vec.size = min(vec.size, Vector::MAX_SIZE);

	cout << "Enter " << vec.size << " elements:" << endl;
	for (int i = 0; i < vec.size; ++i) {
		is >> vec.data[i];
	}
	return is;
}

Vector::operator string() const
{
	string result = "Vector elements: ";
	for (int i = 0; i < size; i++) {
		result += " " + to_string(data[i]);
	}
	return result;
}

Vector Vector::operator ++()
{
	for (int i = 0; i < size; i++) {
		++data[i];
	}
	return *this;
}

Vector Vector::operator --()
{
	for (int i = 0; i < size; i++) {
		--data[i];
	}
	return *this;
}

Vector& Vector::operator ++(int)
{
	Vector tmp(*this);
	++(*this);
	return tmp;
}

Vector& Vector::operator --(int)
{
	Vector tmp(*this);
	--(*this);
	return tmp;
}

Vector& Vector::operator-(const Vector& other) const
{
	Vector result;
	int max_size = max(size, other.size);
	result.size = max_size;

	for (int i = 0; i < size; ++i) {
		result.data[i] = (i < size ? data[i] : 0) - (i < other.size ? other.data[i] : 0);
	}

	return result;
}

bool Vector::operator==(const Vector& other) const
{
	if (size != other.size) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (data[i] != other.data[i])
			return false;
	}
	return true;
}

int Vector::operator /(const Vector& other) const
{
	if (size == 0 || other.size == 0) {
        return 0;
    }

    int min_val1 = *std::min_element(data, data + size);
    int max_val1 = *std::max_element(data, data + size);
    int min_val2 = *std::min_element(other.data, other.data + other.size);
    int max_val2 = *std::max_element(other.data, other.data + other.size);

    int norm_1 = abs(max_val1 - min_val1);
    int norm_2 = abs(max_val2 - min_val2);

    return abs(norm_1 - norm_2);
}

const int& Vector::operator[](const int index) const
{
	if (index >= 0 && index < size) {
		return data[index];
	}
	else {
		throw out_of_range("Index out of range!");
	}
}
