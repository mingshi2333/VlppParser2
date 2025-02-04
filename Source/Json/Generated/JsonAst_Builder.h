/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Ast
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_BUILTIN_JSON_AST_AST_BUILDER
#define VCZH_PARSER2_BUILTIN_JSON_AST_AST_BUILDER

#include "JsonAst.h"

namespace vl::glr::json::builder
{
	class MakeArray : public vl::glr::ParsingAstBuilder<JsonArray>
	{
	public:
		MakeArray& items(const vl::Ptr<JsonNode>& value);
	};

	class MakeLiteral : public vl::glr::ParsingAstBuilder<JsonLiteral>
	{
	public:
		MakeLiteral& value(JsonLiteralValue value);
	};

	class MakeNumber : public vl::glr::ParsingAstBuilder<JsonNumber>
	{
	public:
		MakeNumber& content(const vl::WString& value);
	};

	class MakeObject : public vl::glr::ParsingAstBuilder<JsonObject>
	{
	public:
		MakeObject& fields(const vl::Ptr<JsonObjectField>& value);
	};

	class MakeObjectField : public vl::glr::ParsingAstBuilder<JsonObjectField>
	{
	public:
		MakeObjectField& name(const vl::WString& value);
		MakeObjectField& value(const vl::Ptr<JsonNode>& value);
	};

	class MakeString : public vl::glr::ParsingAstBuilder<JsonString>
	{
	public:
		MakeString& content(const vl::WString& value);
	};

}
#endif