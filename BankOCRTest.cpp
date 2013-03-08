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
	vector<vector<string> > lineList = ocr.readLine("./resources/input.txt");
	/**
	for(std::vector<string>::size_type i = 0; i != 2; i++){
		for(std::vector<string>::size_type j = 0; j != lineList[i].size(); j++){
			cout << lineList[i][j] << endl;
		}
	}
	**/
	CHECK(ocr.readLine("./resources/input.txt").size() >= 1);
}

TEST(BankOCR, ItReturnsCorrectTranslationOfASingleAccountNumber){
	vector<vector<string> > lineList = ocr.readLine("./resources/zeroinput.txt");
	vector<int> out;
	for(std::vector<string>::size_type i = 0; i < lineList.size(); i++){
		out = ocr.parseNumberList(lineList[i]);
		for(std::vector<int>::size_type j=0; j < out.size(); j++){
			//cout << out[i];
		}
	}

	CHECK_EQUAL(000000000, ocr.translateAccountNumber(lineList[0], 0));
}

TEST(BankOCR, ItDoes){
	vector<vector<string> > lineList = ocr.readLine("./resources/input.txt");

	vector<int> out;
	for(std::vector<string>::size_type i = 0; i < lineList.size(); i++){
		out = ocr.parseNumberList(lineList[i]);
		for(std::vector<int>::size_type j=0; j < out.size(); j++){
			cout << out[i];
		}
		cout << endl;
	}
}

