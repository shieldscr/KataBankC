#include "./src/BankOCR.h"

#include <CppUTest/TestHarness.h>

TEST_GROUP(BankOCR){
};

TEST(BankOCR, ItReturnsZeroWhenGivenZero){
	BankOCR ocr;
	CHECK_EQUAL(0, ocr.getTranslation(""));
}

