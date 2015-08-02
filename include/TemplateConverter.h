/**
 * TemplateConverter.h<br>
 *
 *  Created on: 2015/08/01
 *      Author: vagrant
 */

#ifndef SRC_TEMPLATECONVERTER_H_
#define SRC_TEMPLATECONVERTER_H_

#include <string>

class TemplateConverter {
public:
	//! コンストラクタ
	/*!
	 * \param className 変換するクラス名
	 */
	explicit TemplateConverter(std::string className);
	//! デストラクタ
	virtual ~TemplateConverter();
	//! 与えられた文字列の中のタグを変換する
	/*!
	 * \param targetString 変換対象の文字列
	 * \return 変換後の文字列
	 */
	std::string convert(const std::string targetString);

private:
	TemplateConverter();
	std::string className_; //!< 変換するクラス名
};

#endif /* SRC_TEMPLATECONVERTER_H_ */
