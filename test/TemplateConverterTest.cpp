/*
 * TemplateConverterTest.cpp
 *
 *  Created on: 2015/08/01
 *      Author: vagrant
 */

#include <string>
#include "TemplateConverterTest.h"

TemplateConverterTest::TemplateConverterTest() : sut(NULL) {
}

TemplateConverterTest::~TemplateConverterTest() {
}

void TemplateConverterTest::SetUp() {
	sut = new TemplateConverter();
}

void TemplateConverterTest::TearDown() {
	delete sut;
}

TEST_F(TemplateConverterTest, DoNotNeedConvert_DueToNoTags) {
	std::string targetString("class Hoge {");
	std::string expectedString(targetString);

	EXPECT_EQ(expectedString, sut->convert(targetString));
}
