#include "./src/BankOCR.h"

#include <CppUTest/TestHarness.h>
#include <iostream>

BankOCR ocr;

TEST_GROUP(BankOCR){
};

/**
 * Verify that the OCR can translate a zero
 */
TEST(BankOCR, ItReturnsZeroWhenGivenZero){
	CHECK_EQUAL(0, ocr.getTranslation(" _ \n| |\n|_|\n"));
}

/**
 * Verify that the OCR can translate a one
 */
TEST(BankOCR, ItReturnsOneWhenGivenOne){
	CHECK_EQUAL(1, ocr.getTranslation("   \n  |\n  |\n"))
}

/**
 * Verify that the OCR can translate a two
 */
TEST(BankOCR, ItReturnsTwoWhenGivenTwo){
	CHECK_EQUAL(2, ocr.getTranslation(" _ \n _|\n|_ \n"))
}

/**
 * Verify that the OCR can translate a three
 */
TEST(BankOCR, ItReturnsThreeWhenGivenThree){
	CHECK_EQUAL(3, ocr.getTranslation(" _ \n _|\n _|\n"))
}

/**
 * Verify that the OCR can translate a four
 */
TEST(BankOCR, ItReturnsFourWhenGivenFour){
	CHECK_EQUAL(4, ocr.getTranslation("   \n|_|\n  |\n"))
}

/**
 * Verify that the OCR can translate a five
 */
TEST(BankOCR, ItReturnsFiveWhenGivenFive){
	CHECK_EQUAL(5, ocr.getTranslation(" _ \n|_ \n _|\n"))
}

/**
 * Verify that the OCR can translate a six
 */
TEST(BankOCR, ItReturnsSixWhenGivenSix){
	CHECK_EQUAL(6, ocr.getTranslation(" _ \n|_ \n|_|\n"))
}

/**
 * Verify that the OCR can translate a seven
 */
TEST(BankOCR, ItReturnsSevenWhenGivenSeven){
	CHECK_EQUAL(7, ocr.getTranslation(" _ \n  |\n  |\n"))
}

/**
 * Verify that the OCR can translate a eight
 */
TEST(BankOCR, ItReturnsEightWhenGivenEight){
	CHECK_EQUAL(8, ocr.getTranslation(" _ \n|_|\n|_|\n"))
}

/**
 * Verify that the OCR can translate a nine
 */
TEST(BankOCR, ItReturnsNineWhenGivenNine){
	CHECK_EQUAL(9, ocr.getTranslation(" _ \n|_|\n _|\n"))
}

/**
 * Verify that the OCR can translate an invalid number. Returns -1
 */
TEST(BankOCR, ItReturnsNegativeOneWhenNoMatch){
	CHECK_EQUAL(-1, ocr.getTranslation("_____________"));
}

/**
 * It reads in a file and returns a list of things greater than 1
 */
TEST(BankOCR, ItReadsFileAndReturnsNonEmptyList){
	vector<vector<string> > lineList = ocr.readLine("./resources/input.txt");

	CHECK(ocr.readLine("./resources/input.txt").size() >= 1);
}

/**
 *Correctly translates a list of bank account numbers that are identical to a correct integer list. (Zeros)
 */
TEST(BankOCR, ItReturnsCorrectTranslationOfAStringOfZeros){
	vector<vector<string> > lineList = ocr.readLine("./resources/zeroinput.txt");
	vector<int> out;

	CHECK_EQUAL(000000000, ocr.translateAccountNumber(lineList[0], 0));
}

/**
 *Correctly translates a list of bank account numbers that are identical to a correct integer list. (Fives)
 */
TEST(BankOCR, ItReturnsCorrectTranslationOfAStringOfFives){
	vector<vector<string> > lineList = ocr.readLine("./resources/fiveinput.txt");
	vector<int> out;
	int testArray[9] = {5,5,5,5,5,5,5,5,5};

	for(std::vector<string>::size_type i = 0; i < lineList.size(); i++){
			out = ocr.parseNumberList(lineList[i]);
	}

	bool valid = true;
	for(std::vector<string>::size_type i = 0; i < out.size(); i++){
		if(out[i] != testArray[i]){
			valid = false;
		}
	}
	CHECK_EQUAL(valid, true);
}

/**
 * Reads in a list of different numbers, translates into integers, and returns correct translation
 */
TEST(BankOCR, ItTranslatesFileOfNumbers){
	vector<vector<string> > lineList = ocr.readLine("./resources/comboinput.txt");
	vector<int> out;
	int testArray[9] = {1,2,3,4,5,6,7,8,9};

	out = ocr.parseNumberList(lineList[0]);

	bool valid = true;
	for(std::vector<string>::size_type i = 0; i < out.size(); i++){
		if(out[i] != testArray[i]){
			valid = false;
		}
	}
	CHECK_EQUAL(valid, true);
}

/**
 * Tests for correct account numbers, and that they are judged as so
 */
TEST(BankOCR, ItVerifiesAccountNumberSuccess){
	vector<int> testList;
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);

	CHECK_EQUAL(0, ocr.verifyAccountNumberChecksum(testList))
}

/**
 * Tests for incorrect account numbers, and that they are judged as so
 */
TEST(BankOCR, ItVerifiesAccountNumberFail){
	vector<int> testList;
	testList.push_back(0);
	testList.push_back(1);
	testList.push_back(0);
	testList.push_back(1);
	testList.push_back(0);
	testList.push_back(1);
	testList.push_back(0);
	testList.push_back(1);
	testList.push_back(0);

	CHECK_EQUAL(-1, ocr.verifyAccountNumberChecksum(testList))
}

/**
 * Prints out and tests for correct output of a valid number
 */
TEST(BankOCR, ItPrintsCorrectOutput){
	vector<int> testList;
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	testList.push_back(0);
	bool valid = true;
	vector<string> out = ocr.generatePrintOCR(testList);
	string testArray[9] = {"0","0","0","0","0","0","0","0","0"};
	for(std::vector<string>::size_type i = 0; i < out.size(); i++){
		if(out[i] != testArray[i]){
			valid = false;
		}
	}
	CHECK_EQUAL(valid, true);
}

/**
 * Takes a number which would fail the OCR checksum, and shows that print output will append proper error code to end before printing.
 */
TEST(BankOCR, ItFailsChecksumAndPrintsCorrectFailOutput){
	vector<int> testList;
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	bool valid = true;
	vector<string> out = ocr.generatePrintOCR(testList);
	string testArray[10] = {"9","9","9","9","9","9","9","9","9"," ERR"};
	for(std::vector<string>::size_type i = 0; i < out.size(); i++){
		if(out[i] != testArray[i]){
			valid = false;
		}
	}
	CHECK_EQUAL(valid, true);
}

/**
 * Takes a number which contains an invalid number, and shows that print output will append proper error code to end before printing.
 */
TEST(BankOCR, ItFindsAnInvalidNumberAndPrintsCorrectFailOutput){
	vector<int> testList;
	testList.push_back(9);
	testList.push_back(-1);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(-1);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	testList.push_back(9);
	bool valid = true;
	vector<string> out = ocr.generatePrintOCR(testList);
	string testArray[10] = {"9","?","9","9","?","9","9","9","9"," ILL"};
	for(std::vector<string>::size_type i = 0; i < out.size(); i++){
		if(out[i] != testArray[i]){
			valid = false;
		}
	}
	CHECK_EQUAL(valid, true);
}
