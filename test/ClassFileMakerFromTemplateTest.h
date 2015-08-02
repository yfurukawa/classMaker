/**
 * ClassFileMakerTest.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERFROMTEMPLATETEST_H_
#define CLASSFILEMAKERFROMTEMPLATETEST_H_

#include <string>
#include <gtest/gtest.h>
#include "mocks/ClassFileMakerFromTemplateSpy.h"

class ClassFileMakerFromTemplateTest : public ::testing::Test {
public:
	ClassFileMakerFromTemplateTest();
	virtual ~ClassFileMakerFromTemplateTest();

protected:
	ClassFileMakerFromTemplateSpy* sut;

	virtual void SetUp();
	virtual void TearDown();
	std::string createExpectedHeader(std::string className);

};

#endif /* CLASSFILEMAKERTEST_H_ */
