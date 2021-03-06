/*
220assignment4.cpp
Assignment:  COS220_Assignment4
Programmer:  Kody Moseley
Description: This function reads in cooking.txt file,
			and reads it into a nice looking chart, using
			functions like swap/sort, to fight the right 
			order of numbers. It also takes in the string
			of the form LastName,FirstName, and correctly
			splits them up. It is then turned into the form
			FirstName LastName for chart output. The winner
			and their score is updated as the txt file is read
			in, and is outputted at the end. 
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std; 

//POST: exchange the values in v1 and v2
void swap(double& v1, double& v2) {
	double temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

//POST: reorder values such that v1 <= v2 <= v3
void sort(double& v1, double& v2, double& v3) {
	if (v1 >= v3) {
		swap(v1, v3);
	}
	if (v1 >= v2) {
		swap(v1, v2);
	}
	if (v2 >= v3) {
		swap(v2, v3);
	}
}

//PRE: v1 <= v2 <= v3
//POST: return the weighted sim: 1/2v1 + v2 + 1/2v3
double final(double v1, double v2, double v3) {
	return (0.5)*v1 + v2 + (0.5)*v3;
}

//PRE: full name in form last,first (ex. Smiths,Carl)
//POST: return the last name (ex. Smith)
string lastName(string fullName) {
	size_t position = fullName.find(",");
	return fullName.substr(0, (position));
}

//PRE: full name in form last,first (ex. Smiths,Carl)
//POST: return the first name (ex. Carl)
string firstName(string fullName) {
	size_t position = fullName.find(",");
	return fullName.substr((position)+1, string::npos);
}


int main()
{
	double dHighestScore = 0;					//keep track of highest score
	string sHighestWinnerName;					//keep track of name of highest score

	ifstream input("cooking.txt");				//create stream for cooking.txt

	if (input.fail()) {							//if statement, input fail
		cout << "File does not exist" << endl;	
		system("pause");
		return 0;
	}
	cout << setprecision(1) << fixed;					//set precision and fix decimal

	cout << "Cooking Contest by Kody Moseley" << endl;	//basic header
	cout << "Name " << right << setw(20) 
		<< "Score 1" << right << setw(10) 
		<< "Score 2" << right << setw(10) 
		<< "Score 3 " << right << setw(10) 
		<< "Final Score" << endl;
	cout << "---------------------------------------------------------" << endl;

	while (!input.eof()) {				//while loop runs until the file is finished
		string fullName;				//string for LastName,FirstName
		double score1;					//first score
		double score2;					//second score
		double score3;					//third score

		input >> fullName >> score1 >> score2 >> score3;	//read in name and scores from file

		string sFirstName;									//declare string for first name
		string sLastName;									//declare string for last name

		sFirstName = firstName(fullName);					//find first name by splitting fullname
		sLastName = lastName(fullName);						//find last name by splitting fullname

		sort(score1, score2, score3);						//sort the scores from lowest to highest
		
		double finalScore = 0;					
		finalScore = final(score1, score2, score3);			//set finalScore to final function

		string sFullName = sFirstName + " " + sLastName;	//concat first name and last name
		
		cout << setw(22) << left << sFullName				//display names and scores in chart
			<< score1 << right << setw(10) 
			<< score2 << right << setw(9) 
			<< score3 << right << setw(12) 
			<< finalScore << endl;
															//if needed:
		if (finalScore > dHighestScore) {					//update highest score and winner
			dHighestScore = finalScore;
			sHighestWinnerName = sFullName;
		}
	}

	cout << endl;
															//output for the winnder
	cout << "The winner is " << sHighestWinnerName 
		<< " with a score of " << dHighestScore << endl;
	
	system("pause");
    return 0;
}