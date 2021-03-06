//LabOne: Outputting certain elements of a file
//Emily Gorman
//Computer Science II
//No Help Recieved 
//9-17-2018

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string filename;
	ifstream numFile;
	int count = 0;                                                     //The counter that provides the incrementation for this program
	double firstNum, secondNum, num, lastNum, lastlastNum;          
	cout << "Please enter a file name: "; 
	getline(cin, filename);                                            //Name of file is retrieved from the user and opened as a file
	numFile.open(filename);
	if (numFile.fail())         
	{
		cerr << "This file could not be opened." << endl;             //If file fails to open an error message is displayed
	}
	else {
		while (numFile >> num)                                        //Loop runs through file
		{
			if (count == 0)                                           //First, second, and last number are stored in their respective variables
			{
				firstNum = num;
			}
			else if (count == 1)
			{
				secondNum = num;
			}
			count++;
			lastlastNum = num;
		}
		numFile.clear();                                             //File is reset so a second loop can be initialized
		numFile.seekg(0, numFile.beg);
		for (int i = 0; i < count + 1; i++ && (numFile >> num))     //For loop is used to store the second to last number in its proper variable
		{
			if (i == (count))
			{
				lastNum = num;
			}
		}
		
		cout << "Total amount of numbers in the file: " << count << endl;                          //Output is delivered to the user
		cout << "First two numbers in the file: " << firstNum << " and " << secondNum << endl;
		cout << "Last two numbers in the file: " << lastNum << " and " << lastlastNum << endl;
	}
	numFile.close();                                                                               //File is closed

	return 0;
}
