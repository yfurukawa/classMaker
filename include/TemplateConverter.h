/*
 * TemplateConverter.h
 *
 *  Created on: 2015/08/01
 *      Author: vagrant
 */

#ifndef SRC_TEMPLATECONVERTER_H_
#define SRC_TEMPLATECONVERTER_H_

#include <string>

class TemplateConverter {
public:
	TemplateConverter();
	virtual ~TemplateConverter();
	std::string convert(std::string targetString);
};

#endif /* SRC_TEMPLATECONVERTER_H_ */
