/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE2_LRIREQUIRED_TYPEOREXPR_AST_JSON_VISITOR
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE2_LRIREQUIRED_TYPEOREXPR_AST_JSON_VISITOR

#include "PrefixMerge2_LriRequiredTypeOrExpr.h"

namespace prefixmerge2_lrirequired::json_visitor
{
	/// <summary>A JSON visitor, overriding all abstract methods with AST to JSON serialization code.</summary>
	class TypeOrExprVisitor
		: public vl::glr::JsonVisitorBase
		, protected virtual TypeOrExpr::IVisitor
		, protected virtual QualifiedName::IVisitor
	{
	protected:
		virtual void PrintFields(CallExpr* node);
		virtual void PrintFields(ConstType* node);
		virtual void PrintFields(FunctionType* node);
		virtual void PrintFields(MemberName* node);
		virtual void PrintFields(MulExpr* node);
		virtual void PrintFields(Name* node);
		virtual void PrintFields(PointerType* node);
		virtual void PrintFields(QualifiedName* node);
		virtual void PrintFields(TypeOrExpr* node);
		virtual void PrintFields(TypeOrExprToResolve* node);

	protected:
		void Visit(TypeOrExprToResolve* node) override;
		void Visit(QualifiedName* node) override;
		void Visit(CallExpr* node) override;
		void Visit(MulExpr* node) override;
		void Visit(ConstType* node) override;
		void Visit(PointerType* node) override;
		void Visit(FunctionType* node) override;

		void Visit(Name* node) override;
		void Visit(MemberName* node) override;

	public:
		TypeOrExprVisitor(vl::stream::StreamWriter& _writer);

		void Print(TypeOrExpr* node);
	};
}
#endif