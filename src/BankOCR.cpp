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
#include <sstream>

using namespace std;

const int ROWS = 3;
const int TOTAL_NUMBERS = 9;

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

/**
 * Takes a group of digital numbers, breaks them up one by one, and returns a list of integers representing each number
 *
 * @param inputList The string list representing digital numbers that will be translated
 */
vector<int> BankOCR::parseNumberList(vector<string> lines){
	vector<int> translateList;
    for(int i=0;i<TOTAL_NUMBERS;i++){
    	if(translateAccountNumber(lines, i) != -1){
    		translateList.push_back(translateAccountNumber(lines, i));
    	}
    	else{
    		translateList.push_back(-1);
    	}
    }
	return translateList;
}

/**
*Takes one digital number and translates it to an integer
*
*@param inList The string list that represents a digital number
*@param startPoint An integer that specifies where the translation should start from provided input
*
*@return int The integer that represents the input boolean list or -1 if no match was found
**/
int BankOCR::translateAccountNumber(vector<string> lines, int startPoint){
	string match;
	for(std::vector<string>::size_type i = 0; i < lines.size(); i++){
		for(int j=0; j<ROWS; j++){
			match += lines[i][j + (startPoint*3)];
		}
		match += "\n";
	}
	return getTranslation(match);
}

/**
 * Verifies that account number is valid by use of checksum. Returns 0 if valid and -1 otherwise
 *
 * @param inputList The list of account number to be verified
 * @return 0 if account number is valid, -1 otherwise
*/
int BankOCR::verifyAccountNumberChecksum(vector<int> inputList){
	int sum;
	int nine = inputList[inputList.size()-1];
	int eight = inputList[inputList.size()-2];
	sum = nine + eight;
	for(int i=inputList.size()-2;i>0;i--){
		sum = sum * (inputList[i-1] + inputList[i]);
	}
	if(sum%11 == 0){
		return 0;
	}
	return -1;
}

/**
 * Searches list for -1 int values and returns -1 if found (true) or 0 if not found (false). Represents bad character reading.
 *
 * @param inputList List to be checked for bad characters
 * @return int -1 if bad character found, 0 all characters are valid
 */
int BankOCR::verifyAccountNumberReading(vector<int> inputList){
	for(std::vector<string>::size_type i = 0; i < inputList.size(); i++){
		if(inputList[i] == -1){
			return -1;
		}
	}
	return 0;
}

/**
 * Finds a match for given digital number. Returns that int match
 *
 * @param string input The int translation of input string
 */
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

/**
* Reads file of underscores and pipes and creates a list of top, middle, and bottom portions for each entry
*
* @param fileName The path and name of the file to be read
*/
vector<vector<string> > BankOCR::readLine(string filename){
	vector<vector<string> > wholeFile;
	string top;
	string middle;
	string bottom;
	string temp;

	ifstream inFile;
	inFile.open(filename.c_str());

	if(inFile.is_open()){
		while (inFile.good()){
			getline(inFile, top);
			getline(inFile, middle);
			getline(inFile, bottom);
			vector<string> addList;
			addList.push_back(top);
			addList.push_back(middle);
			addList.push_back(bottom);
			wholeFile.push_back(addList);
			if(inFile.good()){
				getline(inFile, temp);
			}
			else{
				break;
			}
		}
		inFile.close();
	}
	return wholeFile;
}

/**
 * Appends either "ERR" if number does not pass checksum, OR "ILL" if number is not valid and returns a vector<string> for each number in read input. Replaces all unreadable
 * numbers with a "?" character
 *
 * @param inList The list to be printed out
 * @return vector<string> The generated list ready for printing
 */
vector<string> BankOCR::generatePrintOCR(vector<int> inputList){
	vector<string> convertedList;
	ostringstream convert;

	for(std::vector<string>::size_type i = 0; i < inputList.size(); i++){
		if(inputList[i] == -1){
			convertedList.push_back("?");
		}
		else{
			convert << inputList[i];
			convertedList.push_back(convert.str());
			convert.str("");
			convert.clear();
		}
	}
	if(verifyAccountNumberReading(inputList) == -1){
		convertedList.push_back(" ILL");
		return convertedList;
	}
	if(verifyAccountNumberChecksum(inputList) == -1){
		convertedList.push_back(" ERR");
		return convertedList;
	}
	return convertedList;
}

