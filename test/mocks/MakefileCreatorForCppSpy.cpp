/**
 * MakefileCreatorForCppSpy.cpp
 *
 *  Created on: 2013/08/25
 *      Author: furukawayoshihiro
 */

#include "MakefileCreatorForCppSpy.h"

MakefileCreatorForCppSpy::MakefileCreatorForCppSpy() {
}

MakefileCreatorForCppSpy::MakefileCreatorForCppSpy(std::string targetName) : MakefileCreatorForCpp( targetName ){
}

MakefileCreatorForCppSpy::~MakefileCreatorForCppSpy() {
}

const IOutputter* MakefileCreatorForCppSpy::getOutputter() const {
	return outputter_;
}

