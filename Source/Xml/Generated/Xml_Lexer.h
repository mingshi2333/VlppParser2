/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Xml
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_BUILTIN_XML_LEXER
#define VCZH_PARSER2_BUILTIN_XML_LEXER

#include "../../AstBase.h"
#include "../../SyntaxBase.h"

namespace vl::glr::xml
{
	enum class XmlTokens : vl::vint32_t
	{
		INSTRUCTION_OPEN = 0,
		INSTRUCTION_CLOSE = 1,
		COMPLEX_ELEMENT_OPEN = 2,
		SINGLE_ELEMENT_CLOSE = 3,
		ELEMENT_OPEN = 4,
		ELEMENT_CLOSE = 5,
		EQUAL = 6,
		NAME = 7,
		ATTVALUE = 8,
		COMMENT = 9,
		CDATA = 10,
		TEXT = 11,
		SPACE = 12,
	};

	constexpr vl::vint XmlTokenCount = 13;
	extern bool XmlTokenDeleter(vl::vint token);
	extern const wchar_t* XmlTokenId(XmlTokens token);
	extern const wchar_t* XmlTokenDisplayText(XmlTokens token);
	extern const wchar_t* XmlTokenRegex(XmlTokens token);
	extern void XmlLexerData(vl::stream::IStream& outputStream);
}
#endif