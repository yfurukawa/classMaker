#include "MakeFileCreatorForCppTest.h"

MakeFileCreatorForCppTest::MakeFileCreatorForCppTest() {

}

MakeFileCreatorForCppTest::~MakeFileCreatorForCppTest() {

}

void MakeFileCreatorForCppTest::SetUp() {
	sut = new MakeFileCreatorForCpp();
}

void MakeFileCreatorForCppTest::TearDown() {
	delete sut;
}

TEST_F (MakeFileCreatorForCppTest, testNameIsHere_ChangeThis) {
/* Write a test code here. */

}
