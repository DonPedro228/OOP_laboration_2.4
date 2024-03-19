#include "Vector.h"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;


int menu()
{
	int i;
	cout << endl;
	cout << "Enter your choise:" << endl << endl;
	cout << " 1 - input data" << endl;
	cout << " 2 - print data" << endl;
	cout << " 3 - vector subtraction" << endl;
	cout << " 4 - same or other" << endl;
	cout << " 5 - vector norm" << endl;
	cout << " 6 - to string" << endl;
	cout << " 7 - indexation" << endl;
	cout << " 0 - exit" << endl << endl;
	cin >> i;
	return i;
}

int main() {
	Vector vec_1, vec_2, vec_3;
	
	int index;
	string str_vec1, str_vec2;

	int i;
	do {
		switch (i = menu())
		{
		case 1:
			cin >> vec_1;
			cin >> vec_2;
			break;
		case 2:
			cout << vec_1 << endl;
			cout << vec_2 << endl;
			break;
		case 3:
			vec_3 = vec_1 - vec_2;
			cout << vec_3;
			break;
		case 4:
			if (vec_1 == vec_2) { 
				cout << "Same" << endl;
			}
			else {
				cout << "Other" << endl;
			}
			break;
		case 5:
			int norma; 
			norma = vec_1 / vec_2;
			cout << "Norma is: " << norma << endl;
			break;
		case 6:
			str_vec1 = static_cast<string>(vec_1);
			str_vec2 = static_cast<string>(vec_2);
			cout << "Vector 1: " << str_vec1 << endl;
			cout << "Vector 2: " << str_vec2 << endl;
			break;
		case 7:
			cout << "Input index: ";  cin >> index;
			try {
				cout << "Index vec_1: " << vec_1[index] << endl;
			}
			catch (const out_of_range& ex) {
				cout << "Error: " << ex.what() << endl;
			}
			break;
		}
	} while (i != 0);

	return 0;
}