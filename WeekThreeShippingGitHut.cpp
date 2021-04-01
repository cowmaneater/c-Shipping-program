// WeekThreeShippingGitHut.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;


//constants
double kYfrag = 2.00;
double kNfrag = 0.00;

double kusa1 = 6.00;
double kusa2 = 9.00;
double kusa3 = 12.00;
double kusa4 = 0.00;

double kcan1 = 8.00;
double kcan2 = 12.00;
double kcan3 = 15.00;
double kcan4 = 0.00;


double kaus1 = 10.00;
double kaus2 = 14.00;
double kaus3 = 17.00;
double kaus4 = 0.00;

double kvenus1 = 1000000;
double kvenus2 = 2000000;
double kvenus3 = 3000000;
double kvenus4 = 3.50;





int main()
{
	// variables
	ofstream outFile;
	string ItemName;
	string frag;
	double ItemValue;
	string destin;
	double fragship;
	double totalShip1;
	double totalShip2;
	double totalShip3;


	//opening/creating out file
	outFile.open("Order.txt");
	//print intro with fill characters
	cout.width(50);
	cout << setfill('.') << setw(50);
	cout << "" << endl;
	cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
	cout << setfill('.') << setw(50);
	cout << "" << endl;
	cout << endl;
	cout << endl;
	//outfile the same thing
	outFile.width(50);
	outFile << setfill('.') << setw(50);
	outFile << "" << endl;
	outFile << "ITCS 2530 - Programming Assignment for week #3" << endl;
	outFile << setfill('.') << setw(50);
	outFile << "" << endl;
	outFile << endl;
	outFile << endl;


	//puts numbers in $0.00 format
	cout.precision(2);

	//user inputs
	cout << "Please enter the item name (no spaces)" << setw(12) << setfill('.') << ":"; cin >> ItemName;
	cout << "Is the item fragile? (y=yes/n=no)" << setw(17) << setfill('.') << ":"; cin >> frag;

	//outfile the same thing
	outFile << "Please enter the item name (no spaces)" << setw(12) << setfill('.') << ":" << ItemName << endl;
	outFile << "Is the item fragile? (y=yes/n=no)" << setw(17) << setfill('.') << ":" << frag << endl;
	//compare lower case strings for frag
	transform(frag.begin(), frag.end(), frag.begin(), ::tolower);
	//closing program and txt doc if wrong input
	if ((frag != "y") && (frag != "n"))
	{
		cout << "Invalid entry, exiting" << endl;
		outFile.close();
		system("pause");
		return 0;
	}
	cout << "Please enter your order total" << setw(21) << setfill('.') << ":"; cin >> ItemValue;
	cout << "Please enter destination. (usa/can/aus/venus)" << setw(5) << setfill('.') << ":"; cin >> destin;
	//outfile the same thing
	outFile << "Please enter your order total" << setw(21) << setfill('.') << ":" << ItemValue << endl;
	outFile << "Please enter destination. (usa/can/aus/venus)" << setw(5) << setfill('.') << ":" << destin << endl;
	//compare string no matter the case
	transform(destin.begin(), destin.end(), destin.begin(), ::tolower);
	//closing program and text doc if wrong input
	if ((destin != "aus") && (destin != "can") && (destin != "usa") && (destin !="venus"))
	{
		cout << "Invalid entry, exiting" << endl;
		outFile.close();
		system("pause");
		return 0;
	}


	//caculations
	//usa
	if ((ItemValue < 50) && (destin == "usa"))
		totalShip1 = kusa1;
	else if ((ItemValue < 100) && (destin == "usa"))
		totalShip1 = kusa2;
	else if ((ItemValue < 150) && (destin == "usa"))
		totalShip1 = kusa3;
	else if ((ItemValue > 150) && (destin == "usa"))
		totalShip1 = kusa4;
	//canada
	else if ((ItemValue < 50) && (destin == "can"))
		totalShip1 = kcan1;
	else if ((ItemValue < 100) && (destin == "can"))
		totalShip1 = kcan2;
	else if ((ItemValue < 150) && (destin == "can"))
		totalShip1 = kcan3;
	else if ((ItemValue > 150) && (destin == "can"))
		totalShip1 = kcan4;
	//austrailia
	else if ((ItemValue < 50) && (destin == "aus"))
		totalShip1 = kaus1;
	else if ((ItemValue < 100) && (destin == "aus"))
		totalShip1 = kaus2;
	else if ((ItemValue < 150) && (destin == "aus"))
		totalShip1 = kaus3;
	else if ((ItemValue > 150) && (destin == "aus"))
		totalShip1 = kaus4;
	//venus
	else if ((ItemValue < 50) && (destin == "venus"))
		totalShip1 = kvenus1;
	else if ((ItemValue < 100) && (destin == "venus"))
		totalShip1 = kvenus2;
	else if ((ItemValue < 150) && (destin == "venus"))
		totalShip1 = kvenus3;
	else if ((ItemValue > 150) && (destin == "venus"))
		totalShip1 = kvenus4;
	//fragile
	if (frag == "y")
		fragship = kYfrag;
	else
		fragship = kNfrag;
	//creates shipping cost
	totalShip2 = totalShip1 + fragship;
	//creates total
	totalShip3 = ItemValue + totalShip2;

	transform(ItemName.begin(), ItemName.end(), ItemName.begin(), ::toupper);
	transform(destin.begin(), destin.end(), destin.begin(), ::toupper);

	//print statments
	cout << endl;
	cout << "Your item is" << internal << setw(40) << setfill('.') << ItemName << endl;
	cout << "Your shipping cost is" << internal << setw(23) << setfill('.') << fixed << "$" << totalShip2 << endl;
	cout << "You are shipping to" << internal << setw(27) << setfill('.') << destin << endl;
	cout << "Your total shipping costs are" << internal << setw(15) << setfill('.') << fixed << "$" << totalShip3 << endl;
	cout << endl;
	cout << setw(53) << setfill('-') << "Thank You!" << endl;
	//print to text doc same thing
	outFile << endl;
	outFile << "Your item is" << internal << setw(40) << setfill('.') << ItemName << endl;
	outFile << "Your shipping cost is" << internal << setw(23) << setfill('.') << fixed << "$" << totalShip2 << endl;
	outFile << "You are shipping to" << internal << setw(27) << setfill('.') << destin << endl;
	outFile << "Your total shipping costs are" << internal << setw(15) << setfill('.') << fixed << "$" << totalShip3 << endl;
	outFile << endl;
	outFile << setw(53) << setfill('-') << "Thank You!" << endl;


	//close file
	outFile.close();

	//pause
	system("pause");







	// not sure if there is a way to cout and print to file the same line of code


	return 0;
}

