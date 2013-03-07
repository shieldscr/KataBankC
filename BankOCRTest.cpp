#include "./src/BankOCR.h"

#include <CppUTest/TestHarness.h>

TEST_GROUP(BankOCR){
};

TEST(BankOCR, ItReturnsZeroWhenGivenZero){
	BankOCR ocr;
	CHECK_EQUAL(0, ocr.getTranslation(" _ \n| |\n|_|\n"));
}

TEST(BankOCR, ItReturnsOneWhenGivenOne){
	BankOCR ocr;
	CHECK_EQUAL(1, ocr.getTranslation("   \n  |\n  |\n"))
}

TEST(BankOCR, ItReturnsTwoWhenGivenOne){
	BankOCR ocr;
	CHECK_EQUAL(2, ocr.getTranslation(" _ \n _|\n|_ \n"))
}

TEST(BankOCR, ItReturnsNegativeOneWhenNoMatch){
	BankOCR ocr;
	CHECK_EQUAL(-1, ocr.getTranslation("_____________"));
}

