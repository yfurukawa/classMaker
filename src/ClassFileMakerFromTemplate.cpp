/*
 * ClassFileMakerFromTemplate.cpp
 *
 *  Created on: 2015/08/02
 *      Author: vagrant
 */

#include "ClassFileMakerFromTemplate.h"
#include "IOutputter.h"
#include "FileDAO.h"
#include "TemplateConverter.h"

ClassFileMakerFromTemplate::ClassFileMakerFromTemplate(std::string name) : name_(name), classFilename_(name+".cpp"),
			headerName_(name+".h"), objectName_(name+".o"), headerSkeleton_(""), cppSkeleton_(""), outputter_(NULL), inputter_(NULL),
			converter_(NULL) {
	converter_ = new TemplateConverter(name);
}

ClassFileMakerFromTemplate::ClassFileMakerFromTemplate() : name_(""), classFilename_(""), headerName_(""),
			objectName_(""), headerSkeleton_(""), cppSkeleton_(""), outputter_(NULL), inputter_(NULL), converter_(NULL) {
}

ClassFileMakerFromTemplate::~ClassFileMakerFromTemplate() {
	if( outputter_ != NULL ){
		delete outputter_;
		outputter_ = NULL;
	}
}

void ClassFileMakerFromTemplate::createFiles() {
	converter_->convert("");
}

const std::string ClassFileMakerFromTemplate::getName() const {
	return name_;
}

const std::string ClassFileMakerFromTemplate::getClassName() const {
	return classFilename_;
}

const std::string ClassFileMakerFromTemplate::getObjectName() const {
	return objectName_;
}

void ClassFileMakerFromTemplate::setOutputter(IOutputter* outputter) {
	outputter_ = outputter;
}

void ClassFileMakerFromTemplate::createHeaderFile(){
}

void ClassFileMakerFromTemplate::createImplementsFile(){
}

bool ClassFileMakerFromTemplate::isOutputterSet(){
	return false;
}
