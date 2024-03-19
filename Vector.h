#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Vector
{
private:
	static const int MAX_SIZE = 100;
	int data[MAX_SIZE];
	int size;
public:
	Vector();
	Vector(int arr[], int N);
	Vector(const Vector& other);

	~Vector();


	Vector& operator = (const Vector& other);
	friend ostream& operator << (ostream&, const Vector&);
	friend istream& operator >> (istream&, Vector&);

	operator string() const;

	Vector operator++();
	Vector operator--();
	Vector& operator++(int);
	Vector& operator--(int);

	Vector& operator-(const Vector& other) const;
	bool operator==(const Vector& other) const;
	int operator /(const Vector& other) const;


	const int& operator [](const int index) const;


};