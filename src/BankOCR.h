/*
 * BankOCR.h
 *
 *  Created on: Mar 6, 2013
 *      Author: cshields
 */

#ifndef BANKOCR_H_
#define BANKOCR_H_
#include <string>
class BankOCR {
public:
	BankOCR();
	int getTranslation(std::string input);
	virtual ~BankOCR();
};

#endif /* BANKOCR_H_ */
