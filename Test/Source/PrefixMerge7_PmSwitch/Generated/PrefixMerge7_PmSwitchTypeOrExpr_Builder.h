/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST_BUILDER
#define VCZH_PARSER2_UNITTEST_PREFIXMERGE7_PMSWITCH_TYPEOREXPR_AST_BUILDER

#include "PrefixMerge7_PmSwitchTypeOrExpr.h"

namespace prefixmerge7_pmswitch::builder
{
	class MakeCallExpr : public vl::glr::ParsingAstBuilder<CallExpr>
	{
	public:
		MakeCallExpr& args(const vl::Ptr<TypeOrExpr>& value);
		MakeCallExpr& func(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeCommaExpr : public vl::glr::ParsingAstBuilder<CommaExpr>
	{
	public:
		MakeCommaExpr& first(const vl::Ptr<TypeOrExpr>& value);
		MakeCommaExpr& second(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeConstType : public vl::glr::ParsingAstBuilder<ConstType>
	{
	public:
		MakeConstType& type(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeCtorExpr : public vl::glr::ParsingAstBuilder<CtorExpr>
	{
	public:
		MakeCtorExpr& args(const vl::Ptr<TypeOrExpr>& value);
		MakeCtorExpr& type(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeFunctionType : public vl::glr::ParsingAstBuilder<FunctionType>
	{
	public:
		MakeFunctionType& args(const vl::Ptr<TypeOrExpr>& value);
		MakeFunctionType& returnType(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeGenericMemberName : public vl::glr::ParsingAstBuilder<GenericMemberName>
	{
	public:
		MakeGenericMemberName& member(const vl::WString& value);
		MakeGenericMemberName& parent(const vl::Ptr<QualifiedName>& value);
		MakeGenericMemberName& args(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeGenericName : public vl::glr::ParsingAstBuilder<GenericName>
	{
	public:
		MakeGenericName& name(const vl::WString& value);
		MakeGenericName& args(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeGenericQualifiedName : public vl::glr::ParsingAstBuilder<GenericQualifiedName>
	{
	public:
		MakeGenericQualifiedName& args(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeGtExpr : public vl::glr::ParsingAstBuilder<GtExpr>
	{
	public:
		MakeGtExpr& first(const vl::Ptr<TypeOrExpr>& value);
		MakeGtExpr& second(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeLtExpr : public vl::glr::ParsingAstBuilder<LtExpr>
	{
	public:
		MakeLtExpr& first(const vl::Ptr<TypeOrExpr>& value);
		MakeLtExpr& second(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeMemberName : public vl::glr::ParsingAstBuilder<MemberName>
	{
	public:
		MakeMemberName& member(const vl::WString& value);
		MakeMemberName& parent(const vl::Ptr<QualifiedName>& value);
	};

	class MakeMulExpr : public vl::glr::ParsingAstBuilder<MulExpr>
	{
	public:
		MakeMulExpr& first(const vl::Ptr<TypeOrExpr>& value);
		MakeMulExpr& second(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeName : public vl::glr::ParsingAstBuilder<Name>
	{
	public:
		MakeName& name(const vl::WString& value);
	};

	class MakePointerType : public vl::glr::ParsingAstBuilder<PointerType>
	{
	public:
		MakePointerType& type(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeThrowExpr : public vl::glr::ParsingAstBuilder<ThrowExpr>
	{
	public:
		MakeThrowExpr& arg(const vl::Ptr<TypeOrExpr>& value);
	};

	class MakeTypeOrExprToResolve : public vl::glr::ParsingAstBuilder<TypeOrExprToResolve>
	{
	public:
		MakeTypeOrExprToResolve& candidates(const vl::Ptr<TypeOrExpr>& value);
	};

}
#endif