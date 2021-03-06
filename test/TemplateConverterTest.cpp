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
	sut = new TemplateConverter("Hoge");
}

void TemplateConverterTest::TearDown() {
	delete sut;
}

TEST_F(TemplateConverterTest, DoNotNeedConvert_DueToNoTags) {
	std::string targetString("No Tag line");
	std::string expectedString(targetString);

	EXPECT_EQ(expectedString, sut->convert(targetString));
}

TEST_F(TemplateConverterTest, DoNotNeedConvert_includeLine) {
	std::string targetString("#include <iostream>");
	std::string expectedString(targetString);

	EXPECT_EQ(expectedString, sut->convert(targetString));
}

TEST_F(TemplateConverterTest, Convert_ClassName) {
	std::string targetString("class #{CLASS} {");
	std::string expectedString("class Hoge {");

	EXPECT_EQ(expectedString, sut->convert(targetString));
}

TEST_F(TemplateConverterTest, Convert_ConstructorDefinition_usingTAB) {
	std::string targetString("	#{CLASS}();");
	std::string expectedString("	Hoge();");

	EXPECT_EQ(expectedString, sut->convert(targetString));
}

TEST_F(TemplateConverterTest, Convert_ConstructorDefinition_usingSpace) {
	std::string targetString("    #{CLASS}();");
	std::string expectedString("    Hoge();");

	EXPECT_EQ(expectedString, sut->convert(targetString));
}

TEST_F(TemplateConverterTest, Convert_Constructor) {
	std::string targetString("#{CLASS}::#{CLASS}(){");
	std::string expectedString("Hoge::Hoge(){");

	EXPECT_EQ(expectedString, sut->convert(targetString));
}
