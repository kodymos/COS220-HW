// test.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	double x = 2.0;
	double y = 1.5;
	int m = 15;
	int n = 4;

	string a = to_string(n++ * 4 / 3);
	string b = to_string(x+m*n-1);
	string c = to_string(33 % 7 - (1 + x) * n);
	string d = to_string(15 + x / y + n);
	string e = to_string(int(3.0 / 4.0) + double(1 / 2));

	cout << a << endl << b << endl << c << endl << d << endl << e << endl;
	system("pause");
	return 0;
}
