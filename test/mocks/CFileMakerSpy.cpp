/**
 * CFileMakerSpy.cpp
 *
 *  Created on: 2013/09/26
 *      Author: furukawayoshihiro
 */

#include "CFileMakerSpy.h"

CFileMakerSpy::CFileMakerSpy() {
}

CFileMakerSpy::~CFileMakerSpy() {
}

CFileMakerSpy::CFileMakerSpy(std::string name) : CFileMaker(name) {
}

const std::string CFileMakerSpy::getHeaderName() const {
	return headerName_;
}

const std::string CFileMakerSpy::getHeaderSkeleton() const {
	return headerSkeleton_;
}

const std::string CFileMakerSpy::getCppSkeleton() const {
	return cSkeleton_;
}

const IOutputter* CFileMakerSpy::getOutputter() const {
	return outputter_;
}
