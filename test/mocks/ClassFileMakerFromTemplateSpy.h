/**
 * ClassFileMakerSpy.h
 *
 *  Created on: 2013/08/13
 *      Author: furukawayoshihiro
 */

#ifndef CLASSFILEMAKERFROMTEMPLATESPY_H_
#define CLASSFILEMAKERFROMTEMPLATESPY_H_

#include "ClassFileMakerFromTemplate.h"

class ClassFileMakerFromTemplateSpy: public ClassFileMakerFromTemplate {
private:
	ClassFileMakerFromTemplateSpy();
public:
	ClassFileMakerFromTemplateSpy(std::string name);
	virtual ~ClassFileMakerFromTemplateSpy();
	const std::string getHeaderName() const;
	const std::string getHeaderSkeleton() const;
	const std::string getCppSkeleton() const;
	const IOutputter* getOutputter() const;
};

#endif /* CLASSFILEMAKERSPY_H_ */
