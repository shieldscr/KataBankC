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
	vector<string> readLine(string filename);
	virtual ~BankOCR();
};

#endif /* BANKOCR_H_ */
