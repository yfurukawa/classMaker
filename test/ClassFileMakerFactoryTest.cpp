/**
 * ClassFileMakerFactoryTest.cpp
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#include <typeinfo>
#include "mocks/CommandLineArgumentsParserMock.h"
#include "ClassFileMakerFactoryTest.h"
#include "ClassFileMaker.h"
#include "FileMakerList.h"

ClassFileMakerFactoryTest::ClassFileMakerFactoryTest() : sut(NULL), mock(NULL) {
}

ClassFileMakerFactoryTest::~ClassFileMakerFactoryTest() {
	delete sut;
	delete mock;
}

void ClassFileMakerFactoryTest::prepareSutForCppTest() {
	char* argv[] = {(char*)"command", (char*)"Hoge"};
	int argc(2);
	mock = 	new CommandLineArgumentsParserMock();
	mock->parseArguments(argc, argv);
	sut = new ClassFileMakerFactory(mock);
}

void ClassFileMakerFactoryTest::prepareSutForCTest() {
	char* argv[] = {(char*)"command", (char*)"--lang=c", (char*)"Hoge"};
	mock = 	new CommandLineArgumentsParserMock();
	mock->parseArguments(3, argv);
	sut = new ClassFileMakerFactory(mock);
}

void ClassFileMakerFactoryTest::prepareSutForTemplateTest() {
}

TEST_F(ClassFileMakerFactoryTest, createClassFileMaker_cpp) {
	prepareSutForCppTest();
	FileMakerList list;
	sut->buildClassList(&list);
	EXPECT_EQ("Hoge.cpp ", list.getClassFileList());
}

TEST_F(ClassFileMakerFactoryTest, createTestClassFileMaker_cpp) {
	prepareSutForCppTest();
	FileMakerList list;
	sut->buildClassList(&list);
	EXPECT_EQ("../test/HogeTest.cpp ", list.getTestClassFileList());
}

TEST_F(ClassFileMakerFactoryTest, createClassFileMaker_c) {
	prepareSutForCTest();
	FileMakerList list;
	sut->buildClassList(&list);
	EXPECT_EQ("Hoge.c ", list.getClassFileList());
}
