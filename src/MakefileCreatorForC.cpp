/**
 * MakefileCreatorForC.cpp
 *
 *  Created on: 2013/09/28
 *      Author: furukawayoshihiro
 */

#include "MakefileCreatorForC.h"

MakefileCreatorForC::MakefileCreatorForC()  : outputter_(NULL), inputter_(NULL), targetName_(""), targetNameForTest_("") {
}

MakefileCreatorForC::~MakefileCreatorForC() {
  if( outputter_ != NULL ){
    delete outputter_;
    outputter_ = NULL;
  }
  if( inputter_ != NULL ){
    delete inputter_;
    inputter_ = NULL;
  }
}

MakefileCreatorForC::MakefileCreatorForC(std::string targetName)  : outputter_(NULL), inputter_(NULL), targetName_(targetName), targetNameForTest_(targetName+"Test") {
}

void MakefileCreatorForC::setOutputter(IOutputter* outputter) {
  outputter_ = outputter;
}

void MakefileCreatorForC::setInputter(IInputter* inputter) {
  inputter_ = inputter;
  subCreator_.setInputter(inputter);
}

void MakefileCreatorForC::createFiles(const std::string& sourceClasses,
    const std::string& sourceObjects, const std::string& testClasses,
    const std::string& testObjects) {
  outputter_->outputContents("src/Makefile", createMakefileContents());
  subCreator_.setOutputter(outputter_);
  subCreator_.createFiles( sourceClasses, sourceObjects, testClasses, testObjects );
}

/////////////////////////////////////////////////////////////////////////////////////
std::string MakefileCreatorForC::createMakefileContents() {

  std::string contents;
  contents  = "CC = gcc\n";
  contents += "RM = rm -f\n";
  contents += "INCLUDE = -I/usr/incude -I/usr/local/include\n";
  contents += "LIB_DIR = -L/usr/lib64 -L/usr/local/lib64\n";
  contents += "LIB = -lpthread\n";
  contents += "OPT = -O0 -g3 -Wall -fmessage-length=0 -fprofile-arcs -ftest-coverage\n";
  contents += "TARGET = " + targetName_ + "\n";
  contents += "include productionSources.mk\n";
  contents += "\n";
  contents += "all: $(SRC:.c=.o) main.o\n";
  contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(LIB) $(OPT) -o $(TARGET) $(SRC:.c=.o) main.o";
  contents += "\n";
  contents += "$(SRC:.c=.o): $(SRC)\n";
  contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)\n";
  contents += "\n";
  contents += "main.o: main.c\n";
  contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c main.c\n";
  contents += "\n";
  contents += ".PHONY: clean\n";
  contents += "clean:\n";
  contents += "\t$(RM) *.o $(TARGET) $(TEST_TARGET) gmon.out *.gc* *.xml *.exe *.txt\n";
  contents += "\n";
  contents += "\n";
  contents += "TEST_CC = g++\n";
  contents += "TEST_TARGET = " + targetNameForTest_ + "\n";
  contents += "TEST_INCLUDE = -I../test -I.\n";
  contents += "TEST_LIB = -lgtest\n";
  contents += "TEST_OPT = -O0 -g3 -Wall -fmessage-length=0 -pg -fprofile-arcs -ftest-coverage\n";
  contents += "include testSources.mk\n";
  contents += "include testObjects.mk\n";
  contents += "\n";
  contents += "test: $(SRC:.c=.o) $(TEST_OBJ)\n";
  contents += "\t$(TEST_CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(TEST_OPT) -o $(TEST_TARGET) $(SRC:.c=.o) $(TEST_OBJ) $(LIB) $(TEST_LIB)\n";
  contents += "\n";
  contents += "$(SRC:.c=.o): $(SRC)\n";
  contents += "\t$(CC) $(INCLUDE) $(LIB_DIR) $(OPT) -c $(SRC)\n";
  contents += "\n";
  contents += "$(TEST_OBJ): $(TEST_SRC)\n";
  contents += "\t$(TEST_CC) $(INCLUDE) $(TEST_INCLUDE) $(LIB_DIR) $(LIB) $(TEST_LIB) $(TEST_OPT) -c $(TEST_SRC)\n";

  return contents;
}
