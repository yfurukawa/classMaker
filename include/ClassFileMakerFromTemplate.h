/*
 * ClassFileMakerFromTemplate.h
 *
 *  Created on: 2015/08/02
 *      Author: vagrant
 */

#ifndef SRC_CLASSFILEMAKERFROMTEMPLATE_H_
#define SRC_CLASSFILEMAKERFROMTEMPLATE_H_

#include <string>
#include "IClassFileMaker.h"
#include "TemplateConverter.h"

class IOutputter;

class ClassFileMakerFromTemplate : public IClassFileMaker {
public:
	 //! コンストラクタ
	/*!
	 * \param name モジュール名
	 */
	ClassFileMakerFromTemplate(std::string name);
	//! デストラクタ
	virtual ~ClassFileMakerFromTemplate();
	//! コンストラクタ引数で渡されたクラスのヘッダ及びソースファイルを生成する
	virtual void createFiles();
	//! コンストラクタ引数で渡されたモジュール名を返す
	/*!
	 * \return コンストラクタ引数で渡されたモジュール名
	 */
	virtual const std::string getName() const;
	//! ソースコードのファイル名を返す
	/*!
	 * \return ソースファイル名
	 */
	virtual const std::string getClassName() const;
	//! コンパイルで生成されるオブジェクトファイル名を返す
	/*!
	 * \return オブジェクトファイル名
	 */
	virtual const std::string getObjectName() const;
	//! コンテンツを出力するオブジェクトを設定する
	virtual void setOutputter(IOutputter* outputter);

protected:
	const std::string name_; //!< コンストラクタ引数で渡されたクラス名
	const std::string classFilename_; //!< ソースファイル名
	const std::string headerName_; //!< ヘッダファイル名
	const std::string objectName_; //!< オブジェクトファイル名（*.o）
	std::string headerSkeleton_; //!< ヘッダファイルのスケルトンコンテンツ
	std::string cppSkeleton_; //!< ソースファイルのスケルトンコンテンツ
	IOutputter* outputter_; //!< 出力用オブジェクト

	//! デフォルトコンストラクタ
	ClassFileMakerFromTemplate();


private:
	//! ヘッダファイルのコンテンツを作成する
	virtual void createHeaderFile();
	//! ソースファイルのコンテンツを作成する
	virtual void createImplementsFile();
	//! 出力用オブジェクトを保持しているかどうか返す
	/*!
	 * \return出力用オブジェクトの有無　（true：保持　false:未保持）
	 */
	bool isOutputterSet();
	//! テンプレートのタブを変換するコンバータ
	TemplateConverter* converter;
};

#endif /* SRC_CLASSFILEMAKERFROMTEMPLATE_H_ */
