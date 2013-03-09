/*
 * BankOCR.h
 *
 *  Created on: Mar 6, 2013
 *      Author: cshields
 */

#ifndef BANKOCR_H_
#define BANKOCR_H_
#include <string>
#include <vector>

using namespace std;

class BankOCR {
public:
	string zero;
    string one;
    string two;
    string three;
    string four;
    string five;
    string six;
    string seven;
    string eight;
    string nine;

	BankOCR();
	int getTranslation(string input);
	vector<vector<string> > readLine(string filename);
	vector<int> parseNumberList(vector<string> lines);
	string getNumber(string accountNumber);
	int verifyAccountNumberChecksum(vector<int> inputList);
	int verifyAccountNumberReading(vector<int> inputList);
	vector<string> generatePrintOCR(vector<int> inputList);
	int translateAccountNumber(vector<string> lines, int startPoint);

	virtual ~BankOCR();
};

#endif /* BANKOCR_H_ */
