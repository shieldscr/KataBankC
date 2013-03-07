/*
 * BankOCR.h
 *
 *  Created on: Mar 6, 2013
 *      Author: cshields
 */

#ifndef BANKOCR_H_
#define BANKOCR_H_
#include <string>
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
	virtual ~BankOCR();
};

#endif /* BANKOCR_H_ */
