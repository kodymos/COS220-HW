/*
220assignment5.cpp
Assignment:  COS220_Assignment5
Programmer:  Kody Moseley
Description: This program reads in weather.txt, organizes
			and writes an orderly chart to another txt file,
			in this case output.txt. Number of readings, average
			wind speeds, average temperature in both celcius and farenheit,
			are calculated and outputed as well. Another file is then
			read in, and another chart with the winter months is written
			to output.txt. This program includes functions for celcius to
			farenheit, the reverse, and wind chill. 
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>


using namespace std;

//PRE: pass in celciusTemp
//POST: return farenheit temperature = 1.8 * celciusTemp + 32.0
double celciusToFarenheit(double celciusTemp);

//PRE: pass in farenheit temperature
//POST: return celcius temperature = 5.0/9.0 * (farenheitTemp - 32.0)
double farenheitToCelcius(double farenheitTemp);

//PRE: windspeed in m/sec, temperature in celsius and <= 10
//POST: return windchill in celcius = 33 - (10sqrt(windSpeed) - windSpeed + 10.5)(33-temperature)/23.1
double windChill(double windSpeed, double celciusTemp);

int main()
{
	int counter = 0;						//counter for number of readings
	double totalWindSpeed = 0;			//double windSpeed, as file is read in
	double farenheitTemp = 0;				//farenheit temp, updated as file is read in
	double celciusTemp = 0;					//celcius temp, updated as file is read in
	double totalTemp = 0;					//sum of all temps
	double historicalMonth2Average = 0;		//average for month 2 in weather file
	
	ifstream weatherInput("weather.txt");//input stream for weather.txt
	ifstream averagesInput("averages.txt");//input stream for averages.txt

	ofstream output;//output stream for output.txt
	output.open("output.txt");

	output << fixed << left << setprecision(2);

	//-----------output header-----------
	output << "Wind Measurements for Month 2 by Kody Moseley" << endl << endl;
	output << setw(25) << "Wind Speed (m/sec)" << 
			setw(20) << "Direction" << 
			setw(20) << "Temp (F)" << 
			setw(20) << "Temp (C)" << 
			setw(20) << "Wind Chill (F)" <<
			setw(20) << "Wind Chill (C)" << endl;
	for (int i = 0; i < 122; i++) {
		output << "-";
	}
	output << endl;
	

	while (!weatherInput.eof()) {//read in file while not empty
		string townName;//strine town name
		string date;//string date (not used)
		double windSpeed = 0;//double for wind speed,initialized to 0
		string windDirection;//string wind direction
		double temperature;//double for read in temperature, changed to celcius/farenheit
		string temperatureKey;//string temperature key, read in as C or F
		string firstName;//string first name
		string lastName;//string last name

		counter += 1;//increment counter

		//---------read in file using above variables-----------
		weatherInput >> townName >> date >> windSpeed >> windDirection >> 
			temperature >> temperatureKey >> firstName >> lastName;

		string name = firstName + " " + lastName;//combine first and last name

		if (temperatureKey == "C") {//if read in temp is in celcius
			celciusTemp = temperature;
			farenheitTemp = celciusToFarenheit(celciusTemp);
		}
		if (temperatureKey == "F") {//if read int temp is in farenheit
			farenheitTemp = temperature;
			celciusTemp = farenheitToCelcius(farenheitTemp);
		}

		//----------output chart to file----------
		output << setw(25) << windSpeed <<
			setw(20) << windDirection <<
			setw(20) << farenheitTemp <<
			setw(20) << celciusTemp <<
			setw(20) <<  celciusToFarenheit(windChill(windSpeed, celciusTemp)) <<
			setw(20) << windChill(windSpeed, celciusTemp) << endl;

		totalTemp += farenheitTemp;//increment totaltemp
		totalWindSpeed += windSpeed;//increment total windspeed

	}
	
	//--------after chart outputs----------
	output << endl << "Number of readings: " << counter << endl;
	output << "Average wind speed (m/sec): " << (totalWindSpeed/counter) << endl;
	output << "Average temperature (F): " << (totalTemp/counter) << endl;
	output << "Average temperature (C): " << farenheitToCelcius(totalTemp / counter) << endl;
	output << endl << setw(15) << "Month" << setw(20) << "Temp Average (F)" << endl;
	for (int i = 0; i < 30; i++) {
		output << "-";
	}
	output << endl;


	while (!averagesInput.eof()) {//while averages file is not empty
		string monthNumber;//string month number
		double monthAverage = 0;//double monthAverage


		averagesInput >> monthNumber >> monthAverage;//read in month number and month average

		if (monthNumber == "1" || monthNumber == "2" 
			|| monthNumber == "3" || monthNumber == "12") {//only write to file if its a winter month
			output << setw(15) << monthNumber << setw(20) << monthAverage << endl;
		}

		if (monthNumber == "2") {
			historicalMonth2Average = monthAverage;
		}
		
	}

	output << endl << "The difference from historical average for month 2 is " 
		<< (totalTemp / counter) - historicalMonth2Average << "F" << endl;

	return 0;
}

//PRE: pass in farenheit temperature
//POST: return celcius temperature = 5.0/9.0 * (farenheitTemp - 32.0)
double farenheitToCelcius(double farenheitTemp) {
	double celcius = (5.0 / 9.0) * (farenheitTemp - 32.0);
	return celcius;
}

//PRE: pass in celciusTemp
//POST: return farenheit temperature = 1.8 * celciusTemp + 32.0
double celciusToFarenheit(double celciusTemp) {
	double farenheit = 1.8 * celciusTemp + 32.0;
	return farenheit;
}

//PRE: windspeed in m/sec, temperature in celsius and <= 10
//POST: return windchill in celcius = 33 - (10sqrt(windSpeed) - windSpeed + 10.5)(33-temperature)/23.1
double windChill(double windSpeed, double celciusTemp) {
	double windchil = 33 - (((10 * sqrt(windSpeed) - windSpeed + 10.5) * (33 - celciusTemp)) / 23.1);
	return windchil;
}