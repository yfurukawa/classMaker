/**
 * ClassFileMakerSpy.cpp
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#include "ClassFileMakerFromTemplateSpy.h"

ClassFileMakerFromTemplateSpy::ClassFileMakerFromTemplateSpy() {
}

ClassFileMakerFromTemplateSpy::ClassFileMakerFromTemplateSpy(std::string name) : ClassFileMakerFromTemplate(name) {

}

ClassFileMakerFromTemplateSpy::~ClassFileMakerFromTemplateSpy() {
}

const std::string ClassFileMakerFromTemplateSpy::getHeaderName() const {
	return headerName_;
}

const std::string ClassFileMakerFromTemplateSpy::getHeaderSkeleton() const {
	return headerSkeleton_;
}

const std::string ClassFileMakerFromTemplateSpy::getCppSkeleton() const {
	return cppSkeleton_;
}

const IOutputter* ClassFileMakerFromTemplateSpy::getOutputter() const {
	return outputter_;
}

