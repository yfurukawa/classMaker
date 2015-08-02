/*
 * Conductor.h
 *
 *  Created on: 2015/08/02
 *      Author: vagrant
 */

#ifndef SRC_CONDUCTOR_H_
#define SRC_CONDUCTOR_H_

class CommandLineArgumentsParser;
class FileMakerList;

class Conductor {
public:
	//! コンストラクタ
	Conductor();
	//! デストラクタ
	virtual ~Conductor();
	//! 実効の開始点
	/*!
	 * \param argc コマンドライン引数の数
	 * \param argv[] コマンドライン引数の文字列
	 */
	int run(int argc, char* argv[]);

private:
	void prepareSourceDirectory();
	void createMakefile(CommandLineArgumentsParser& parser, FileMakerList& list);
	void createTestMain();
};

#endif /* SRC_CONDUCTOR_H_ */
