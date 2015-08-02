/*
 * ClassFileMakerFromTemplate.cpp
 *
 *  Created on: 2015/08/02
 *      Author: vagrant
 */

#include "ClassFileMakerFromTemplate.h"
#include "IOutputter.h"

ClassFileMakerFromTemplate::ClassFileMakerFromTemplate(std::string name) : name_(""), className_(""), headerName_(""), objectName_(""), headerSkeleton_(""), cppSkeleton_(""), outputter_(NULL) {
}

ClassFileMakerFromTemplate::ClassFileMakerFromTemplate() : name_(""), className_(""), headerName_(""), objectName_(""), headerSkeleton_(""), cppSkeleton_(""), outputter_(NULL){
}

ClassFileMakerFromTemplate::~ClassFileMakerFromTemplate() {
}

void ClassFileMakerFromTemplate::createFiles() {
}

const std::string ClassFileMakerFromTemplate::getName() const {
	return "";
}

const std::string ClassFileMakerFromTemplate::getClassName() const {
	return "";
}

const std::string ClassFileMakerFromTemplate::getObjectName() const {
	return "";
}

void ClassFileMakerFromTemplate::setOutputter(IOutputter* outputter) {
}

void ClassFileMakerFromTemplate::createHeaderFile(){
}

void ClassFileMakerFromTemplate::createImplementsFile(){
}

bool ClassFileMakerFromTemplate::isOutputterSet(){
	return false;
}
