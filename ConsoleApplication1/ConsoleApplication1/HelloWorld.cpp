// HelloWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main() {
	
	int number = 0;
	int result = 0;
	
	cout << "Enter a number: ";
	cin >> number;
	result = number * 10;
	cout << "Result: " << result << endl;

	return 0;
}


