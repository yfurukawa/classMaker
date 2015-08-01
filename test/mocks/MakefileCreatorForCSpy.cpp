/**
 * MakefileCreatorForCSpy.cpp
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#include <iostream>

#include "MakefileCreatorForCSpy.h"

MakefileCreatorForCSpy::MakefileCreatorForCSpy() {
}

MakefileCreatorForCSpy::~MakefileCreatorForCSpy() {
}

MakefileCreatorForCSpy::MakefileCreatorForCSpy(std::string targetName) : MakefileCreatorForC(targetName){
}

const IOutputter* MakefileCreatorForCSpy::getOutputter() const {
	return outputter_;
}
