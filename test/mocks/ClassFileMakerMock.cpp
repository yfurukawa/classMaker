/**
 * ClassFileMakerMock.cpp
 *
 *  Created on: 2013/08/16
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerMock.h"

ClassFileMakerMock::ClassFileMakerMock() : numberOfCretatedFiles_(0) {
}

ClassFileMakerMock::~ClassFileMakerMock() {
}

void ClassFileMakerMock::createFiles() {
	++numberOfCretatedFiles_;
}

const unsigned int ClassFileMakerMock::getNumberOfCreatedFile() {
	return numberOfCretatedFiles_;
}
