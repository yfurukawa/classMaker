/*
 * TemplateConverterTest.h
 *
 *  Created on: 2015/08/01
 *      Author: vagrant
 */

#ifndef TEST_TEMPLATECONVERTERTEST_H_
#define TEST_TEMPLATECONVERTERTEST_H_

#include <gtest/gtest.h>
#include "TemplateConverter.h"

class TemplateConverterTest : public ::testing::Test {
public:
	TemplateConverterTest();
	virtual ~TemplateConverterTest();
	void SetUp();
	void TearDown();

protected:
	TemplateConverter* sut;
};

#endif /* TEST_TEMPLATECONVERTERTEST_H_ */
