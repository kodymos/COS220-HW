/*
220assignment6.cpp
Assignment:  COS220_AssignmentX
Programmer:  Kody Moseley
Description: This program parses intput password
			checking to see if it meets certain 
			criteria like length, special chars etc.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>


using namespace std;
int main()
{
	string userPassword;			//user input password
	string errorMessage;			//error message, added to as password is parsed
	int howManyWrong = 0;			//counter for how many errors


	bool length = false;			//initialize all bools to false
	bool upper = false;				//	|
	bool lower = false;				//	|
	bool digit = false;				//	|
	bool specialChars = false;		//	V

	cout << "Password checker by Kody Moseley" << endl;

	cout << "Please enter you preferred password: ";
	cin >> userPassword;

	if (userPassword.size() >= 8) {//length checker
		length = true;
	}
	
	
	for (int i = 0; i < userPassword.size(); i++) {//iterate through password, checking every index
		if (islower(userPassword[i])) {
			lower = true;
		}
		
		if (isupper(userPassword[i])) {
			upper = true;
		}
		
		if (isdigit(userPassword[i])) {
			digit = true;
		}
		
		if (userPassword[i] == '!' || userPassword[i] == '@' 
			|| userPassword[i] == '#' || userPassword[i] == '$') {
			specialChars = true;
		}
		
	}
	
	if (specialChars && length && upper && lower && digit) {//if everything is true, password is valid
		cout << "Valid" << endl;
		system("pause");
		return 0;//end program
	}

	else {
		cout << "Invalid" << endl;
	}

	//the next if statements produce the error messages
	if(length == false) {
		howManyWrong += 1;
		errorMessage.append("Reason");
		errorMessage.append(to_string(howManyWrong));
		errorMessage.append(": your password should contain at least eight characters. \n");
	}

	if(lower == false) {
		howManyWrong += 1;
		errorMessage.append("Reason");
		errorMessage.append(to_string(howManyWrong));
		errorMessage.append(": your password should contain a lowercase letter. \n");
	}

	if(upper == false) {
		howManyWrong += 1;
		errorMessage.append("Reason");
		errorMessage.append(to_string(howManyWrong));
		errorMessage.append(": your password should contain an uppercase letter. \n");
	}

	if(digit == false) {
		howManyWrong += 1;
		errorMessage.append("Reason");
		errorMessage.append(to_string(howManyWrong));
		errorMessage.append(": your password should contain a digit. \n");
	}

	if(specialChars == false) {
		howManyWrong += 1;
		errorMessage.append("Reason");
		errorMessage.append(to_string(howManyWrong));
		errorMessage.append(": your password should contain at least one of the four special characters \"! @  # $\" \n");
	}

	cout << errorMessage << endl;

	system("pause");
    return 0;
}