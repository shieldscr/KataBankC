/*
 * BankOCR.cpp
 *
 *  Created on: Mar 6, 2013
 *      Author: cshields
 */

#include "BankOCR.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

BankOCR::BankOCR() {
	zero = " _ \n| |\n|_|\n";
	one = "   \n  |\n  |\n";
	two = " _ \n _|\n|_ \n";
	three = " _ \n _|\n _|\n";
	four = "   \n|_|\n  |\n";
	five = " _ \n|_ \n _|\n";
	six = " _ \n|_ \n|_|\n";
	seven = " _ \n  |\n  |\n";
	eight = " _ \n|_|\n|_|\n";
	nine = " _ \n|_|\n _|\n";
}

BankOCR::~BankOCR() {
	// TODO Auto-generated destructor stub
}

int BankOCR::getTranslation(string input){
	if(input == zero){
		return 0;
	}
	if (input == one){
		return 1;
	}
	if (input == two){
		return 2;
	}
	if (input == three){
		return 3;
	}
	if (input == four){
		return 4;
	}
	if (input == five){
		return 5;
	}
	if (input == six){
		return 6;
	}
	if (input == seven){
		return 7;
	}
	if (input == eight){
		return 8;
	}
    if (input == nine){
		return 9;
	}

    return -1;
}

vector<string> BankOCR::readLine(string filename){
	vector<string> line;
	string top;
	string middle;
	string bottom;

	ifstream inFile;
	inFile.open(filename.c_str());

	if(inFile.is_open()){
		while (inFile.good()){
			getline(inFile, top);
			getline(inFile, middle);
			getline(inFile, bottom);

			line.push_back(top);
			line.push_back(middle);
			line.push_back(bottom);
		}
	}

	return line;

	inFile.close();
}

