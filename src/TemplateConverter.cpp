/**
 * TemplateConverter.cpp
 *
 *  Created on: 2015/08/01
 *      Author: vagrant
 */

#include "boost/regex.hpp"
#include "TemplateConverter.h"

TemplateConverter::TemplateConverter() : className_("") {
}

TemplateConverter::TemplateConverter(std::string className) : className_(className){
}

TemplateConverter::~TemplateConverter() {
}

std::string TemplateConverter::convert(const std::string targetString) {
	boost::regex r;
	r.assign( "#{CLASS}" );
	return boost::regex_replace(targetString, r, className_);
}
