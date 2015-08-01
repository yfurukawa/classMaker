/**
 * FileDAOSpy.cpp
 *
 *  Created on: 2013/12/10
 *      Author: M825504
 */

#include "FileDAOSpy.h"

FileDAOSpy::FileDAOSpy(){
}

FileDAOSpy::~FileDAOSpy(){
}

bool FileDAOSpy::isClosedInputStream(){
	return inputStream_.is_open();
}


