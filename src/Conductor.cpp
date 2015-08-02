/*
 * Conductor.cpp
 *
 *  Created on: 2015/08/02
 *      Author: vagrant
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <dirent.h>
#include <sys/stat.h>

#include "CommandLineArgumentsParser.h"
#include "ClassFileMakerFactory.h"
#include "MakefileCreatorFactory.h"
#include "IOutputter.h"
#include "IMakefileCreator.h"
#include "FileDAO.h"
#include "FileMakerList.h"
#include "TestMainMaker.h"
#include "Conductor.h"

Conductor::Conductor() {
}

Conductor::~Conductor() {
}

int Conductor::run(int argc, char* argv[]) {
	try {
		CommandLineArgumentsParser parser;
		parser.parseArguments(argc, argv);

		prepareSourceDirectory();

		ClassFileMakerFactory factory(&parser);
		FileMakerList list;
		factory.buildClassList(&list);
		list.createFiles();

		if(parser.isNecessaryToCreateMakefile()) {
			createMakefile(parser, list);
		}

		createTestMain();

		return 0;
	}
	catch(const std::invalid_argument& e) {
		std::cerr << e.what();
		std::cerr << std::endl;
		std::cout << "Usage: prepareFiles [--lang=cpp | --lang=c] [--target=targetName] [--without_Makefile] className ..." << std::endl;
		return -1;
	}
	catch(...) {
		std::cerr << "Unknown exceptions are there." << std::endl;
		return -1;
	}
}

void Conductor::prepareSourceDirectory() {
#ifdef __MINGW32__
	mkdir( "src" );
	mkdir( "test");
#else
	mkdir( "src", 0777 );
	mkdir( "test", 0777);
#endif
}

void Conductor::createMakefile(CommandLineArgumentsParser& parser, FileMakerList& list) {
	MakefileCreatorFactory makefileFactory(&parser);
	IMakefileCreator* makefileCreator = makefileFactory.createMakefileCreator();
	makefileCreator->createFiles(list.getClassFileList(), list.getObjectFileList(), list.getTestClassFileList(), list.getTestObjectFileList());
	delete makefileCreator;
}

void Conductor::createTestMain() {
	TestMainMaker testMainMaker;
	testMainMaker.setOutputter(new FileDAO());
	testMainMaker.createFiles();
}
