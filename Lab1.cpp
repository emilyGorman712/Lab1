// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string filename;
	ifstream numFile;
	int totalNumbers = 0;
	double firstTwo, lastTwo, num;
	cout << "Please enter a file name: ";
	getline(cin, filename);
	numFile.open(filename);
	if (!numFile)
	{
		cerr << "This file could not be opened." << endl;
		numFile.close();
	}
	else {
		while (numFile >> num)
		{
			totalNumbers++;
		}
		numFile.close();
	}
	cout << totalNumbers;


	return 0;
}
