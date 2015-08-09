/**
 * ClassFileMakerFactoryTest.h
 *
 *  Created on: 2013/09/22
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERFACTORYTEST_H_
#define CLASSFILEMAKERFACTORYTEST_H_

#include <gtest/gtest.h>

#include "ClassFileMakerFactory.h"

class ClassFileMakerFactoryTest: public ::testing::Test {
public:
	ClassFileMakerFactoryTest();
	virtual ~ClassFileMakerFactoryTest();

protected:
	ClassFileMakerFactory* sut;
	CommandLineArgumentsParserMock* mock;

	void prepareSutForCppTest();
	void prepareSutForCTest();
	void prepareSutForTemplateTest();
};

#endif /* CLASSFILEMAKERFACTORYTEST_H_ */
