/*
220hw2.cpp
Assignment: COS220_Homework2
Programmer: Kody Moseley
Description:This program takes in the number of beef meals,	
			chicken meals, and vegan meals. It then determines
			the correct room based on how many people are there.
			The room tax is calculated by using a constant state tax.
			The costs of all of the meals are displayed. If there was 
			0 of any meals, it isn't included in the output table.
			Food gratuity is calculated by using another constant. 
			Finally, the total of everything is calculated. 
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>   

using namespace std;

int main()
{
	int beefMeals = 0;		//number of beef meals, used to determine costs
	int chickenMeals = 0;	//number of chicken meals, used to determine costs
	int veganMeals = 0;		//number of chicken meals, used to determine costs
	double roomCost = 0;	//cost of the room, determined by how many meals are ordered

	const double STATE_TAX = 0.065;	//constant state tax
	const double GRATUITY = 0.18;	//constant gratuity

	//gets number of meals for each type of food
	cout << "Enter number of beef meals: ";
	cin >> beefMeals;
	cout << "Enter number of chicken meals: ";
	cin >> chickenMeals;
	cout << "Enter number of vegan meals: ";
	cin >> veganMeals;

	cout << "\nCaswell Caterers by Kody Moseley\n" << endl;

	double beefCost = beefMeals * 12.95;		//cost of all beef meals
	double chickenCost = chickenMeals * 10.95;	//cost of all chicken meals
	double veganCost = veganMeals * 8.95;		//cost of all vegan meals

	double foodGratuity = (beefCost + chickenCost + veganCost) * GRATUITY;	//cost of all food, times gratuity

	int numberInParty = beefMeals + chickenMeals + veganMeals;	//number of party, determined by meals added up

	//determines if numbers are nonnegative
	if ((beefMeals < 0) || (chickenMeals < 0) || (veganMeals < 0)) {
		cout << "Error: invalid data" << endl;
		return 1;
	}
	//determines if there is a room available
	if (numberInParty > 200) {
		cout << "Error: no room large enough" << endl;
		return 1;
	}
	cout << setprecision(2) << fixed;

	cout << "Number in party: " << setw(15) << numberInParty <<endl;	//number of party output

	if (numberInParty <= 30 && numberInParty > 0) {			//room 4
		roomCost = 50.00;
	}
	else if (numberInParty <=100 && numberInParty > 30) {	//room 3
		roomCost = 100.00;
	}
	else if (numberInParty <= 150 && numberInParty > 100) {	//room 2
		roomCost = 200.00;
	}
	else if (numberInParty <= 200 && numberInParty > 150) {	//room 1
		roomCost = 250.00;
	}

	//room information outputs, cost and tax
	cout << "Room cost: " << setw(30) << "$" << roomCost << endl;
	cout << "Room tax: " << setw(31) << "$" << roomCost * STATE_TAX << endl;

	//following 3 if statements output meals and costs for each meal if the meal != 0
	if (beefMeals != 0) {
		cout << "Number of beef dinners: " << setw(8) << beefMeals << endl;
		cout << "Cost of beef dinners: " << setw(19) << "$" << beefCost << endl;
	}
	if (chickenMeals != 0) {
		cout << "Number of chicken dinners: " << setw(5) << chickenMeals << endl;
		cout << "Cost of chicken dinners: " << setw(16) << "$" << chickenCost << endl;
	}
	if (veganMeals != 0) {
		cout << "Number of vegan dinners: " << setw(7) << veganMeals << endl;
		cout << "Cost of vegan dinners: " << setw(18) << "$" << veganCost <<endl;
	}

	double total = foodGratuity + beefCost + chickenCost+ veganCost + roomCost * STATE_TAX + roomCost;	//total of everything, including roomcost+tax and all foodcosts

	cout << "Food gratuity: " << setw(26) << "$" << foodGratuity << endl;		//food gratuity output 
	
	for (int k = 0; k < 60; k++) {		//formatting line output
		cout << "-";	

	}
	cout << "\nTotal: " << setw(34) << "$" << total <<endl;	//total output

	system("pause");
	return 0;

}

