/**
 * SubMakefileCreatorSpy.cpp
 *
 *  Created on: 2013/11/26
 *      Author: M825504
 */

#include "SubMakefileCreatorSpy.h"

SubMakefileCreatorSpy::SubMakefileCreatorSpy() {
}

SubMakefileCreatorSpy::~SubMakefileCreatorSpy() {
}

const IOutputter* SubMakefileCreatorSpy::getOutputter() const {
	return outputter_;
}
