#ifndef MAKEFILECREATORFORCPPTEST_H_
#define MAKEFILECREATORFORCPPTEST_H_

#include <gtest/gtest.h>
#include "MakeFileCreatorForCpp.h"

class MakeFileCreatorForCppTest : public ::testing::Test {
protected:
	MakeFileCreatorForCpp* sut;
	void SetUp();
	void TearDown();

public:
	MakeFileCreatorForCppTest();
	virtual ~MakeFileCreatorForCppTest();

};

#endif
