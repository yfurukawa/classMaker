/**
 * ClassFileMakerSpy.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerSpy.h"

ClassFileMakerSpy::ClassFileMakerSpy() {
}

ClassFileMakerSpy::ClassFileMakerSpy(std::string name) : ClassFileMaker(name) {

}

ClassFileMakerSpy::~ClassFileMakerSpy() {
}

const std::string ClassFileMakerSpy::getHeaderName() const {
	return headerName_;
}

const std::string ClassFileMakerSpy::getHeaderSkeleton() const {
	return headerSkeleton_;
}

const std::string ClassFileMakerSpy::getCppSkeleton() const {
	return cppSkeleton_;
}

const IOutputter* ClassFileMakerSpy::getOutputter() const {
	return outputter_;
}

