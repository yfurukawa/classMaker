/**
 * FileMakerListSpy.cpp
 *
 *  Created on: 2013/08/15
 *      Author: furukawayoshihiro
 */

#include "FileMakerListSpy.h"

FileMakerListSpy::FileMakerListSpy() : numberOfCall_(0) {
}

FileMakerListSpy::~FileMakerListSpy() {
}

IClassFileMaker* FileMakerListSpy::getClassFileMaker() {
	return classFileMaker_[numberOfCall_++];
}

IClassFileMaker* FileMakerListSpy::getTestClassFileMaker() {
	return testClassFileMaker_[numberOfCall_++];
}

const int FileMakerListSpy::getNumberOfClassFileMaker() {
	return classFileMaker_.size();
}

const int FileMakerListSpy::getNumberOfTestClassFileMaker() {
	return testClassFileMaker_.size();
}

void FileMakerListSpy::destroyClassList() {
	FileMakerList::destroyClassList();
}

void FileMakerListSpy::destroyTestClassList() {
	FileMakerList::destroyTestClassList();
}
