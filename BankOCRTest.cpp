#include "./src/BankOCR.h"

#include <CppUTest/TestHarness.h>
#include <iostream>

BankOCR ocr;

TEST_GROUP(BankOCR){
};

TEST(BankOCR, ItReturnsZeroWhenGivenZero){
	CHECK_EQUAL(0, ocr.getTranslation(" _ \n| |\n|_|\n"));
}

TEST(BankOCR, ItReturnsOneWhenGivenOne){
	CHECK_EQUAL(1, ocr.getTranslation("   \n  |\n  |\n"))
}

TEST(BankOCR, ItReturnsTwoWhenGivenOne){
	CHECK_EQUAL(2, ocr.getTranslation(" _ \n _|\n|_ \n"))
}

TEST(BankOCR, ItReturnsNegativeOneWhenNoMatch){
	CHECK_EQUAL(-1, ocr.getTranslation("_____________"));
}

TEST(BankOCR, ItReadsFileAndReturnsNonEmptyList){
	BankOCR ocr;
	vector<string> lineList = ocr.readLine("./input.txt");

	for(std::vector<string>::size_type i = 0; i != lineList.size(); i++){
		cout << lineList[i] << endl;
	}

	CHECK(ocr.readLine("./input.txt").size() >= 1);
}

