/*
220assignmentX.cpp
Assignment:  COS220_AssignmentX
Programmer:  Kody Moseley
Description: This program reads in user input drades,
			stores it into an array and calculates the 
			letter grade for each grade. It then ouputs
			it into a formatted chart. It then calculates
			standard deviation as well as mean, and outputs
			both in a formatted fashion as well.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>


using namespace std;

//PRE: 1 <= size <= 8
//POST: return the arithmetic average of numbers in array
double mean(double values[], int size) {
	double total = 0;
	for (int i = 0; i < size; i++) {
		total += values[i];
	}
	
	return total / size;
}

//PRE: 1 <= size <= 8, m is the mean
//POST: return the standard deviation of numbers in array given mean m
double stddev(double values[], int size, double m) {
	double total = 0;
	for (int i = 0; i < size; i++) {
		total += pow((values[i] - m), 2);
	}
	total = total / (size - 1);
	
	return sqrt(total);
}

//POST: return letter grade for score with mean m and standard deviation s
char grade(double score, double m, double s) {
	if (score < m - 1.5*s) {
		return 'F';
	}
	if (m - 1.5*s <= score && score < m - 0.5*s) {
		return 'D';
	}
	if (m - 0.5*s <= score && score < m + 0.5*s) {
		return 'C';
	}
	if (m + 0.5*s <= score && score < m + 1.5*s) {
		return 'B';
	}
	if (m + 1.5*s <= score) {
		return 'A';
	}
}

int main()
{
	cout << "Grade Scores by Kody Moseley" << endl << endl;
	cout << "Enter scores seperated by spaces: ";

	double array[8];//initialize array

	for (int i = 0; i < 8; i++) {//read in array
		cin >> array[i];
	}
	cout << fixed << left << setprecision(1);
	

	cout << setw(10) << "Score" << setw(15) << "Grade" << endl;//output for header
	for (int i = 0; i < 20; i++) {
		cout << "-";
	}
	cout << endl;

	for (int j = 0; j < 8; j++) {//output formatted to chart, using the above functions functions
		cout << setw(10) << array[j] << setw(15) << 
			grade(array[j], mean(array, 8), stddev(array, 8, mean(array, 8))) << endl;
	}
	cout << endl;

	cout << "The mean is " << mean(array, 8) << endl;//output for mean
	cout << "standard deviation is " << stddev(array, 8, mean(array, 8)) << endl << endl;//output for standard deviation
	system("pause");
    return 0;
}