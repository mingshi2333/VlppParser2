/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Ast
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_BUILTIN_XML_AST_AST_JSON_VISITOR
#define VCZH_PARSER2_BUILTIN_XML_AST_AST_JSON_VISITOR

#include "XmlAst.h"

namespace vl::glr::xml::json_visitor
{
	/// <summary>A JSON visitor, overriding all abstract methods with AST to JSON serialization code.</summary>
	class AstVisitor
		: public vl::glr::JsonVisitorBase
		, protected virtual XmlNode::IVisitor
	{
	protected:
		virtual void PrintFields(XmlAttribute* node);
		virtual void PrintFields(XmlCData* node);
		virtual void PrintFields(XmlComment* node);
		virtual void PrintFields(XmlDocument* node);
		virtual void PrintFields(XmlElement* node);
		virtual void PrintFields(XmlInstruction* node);
		virtual void PrintFields(XmlNode* node);
		virtual void PrintFields(XmlText* node);

	protected:
		void Visit(XmlText* node) override;
		void Visit(XmlCData* node) override;
		void Visit(XmlComment* node) override;
		void Visit(XmlElement* node) override;
		void Visit(XmlInstruction* node) override;
		void Visit(XmlDocument* node) override;

	public:
		AstVisitor(vl::stream::StreamWriter& _writer);

		void Print(XmlNode* node);
		void Print(XmlAttribute* node);
	};
}
#endif