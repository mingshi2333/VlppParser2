/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:TypeOrExpr
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "PrefixMerge5_PmTypeOrExpr.h"

namespace prefixmerge5_pm
{
/***********************************************************************
Visitor Pattern Implementation
***********************************************************************/

	void TypeOrExprToResolve::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void QualifiedName::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void Name::Accept(QualifiedName::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void MemberName::Accept(QualifiedName::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void CallExpr::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void CtorExpr::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void MulExpr::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void ConstType::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void PointerType::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void FunctionType::Accept(TypeOrExpr::IVisitor* visitor)
	{
		visitor->Visit(this);
	}
}
namespace vl::reflection::description
{
#ifndef VCZH_DEBUG_NO_REFLECTION

	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::TypeOrExpr, prefixmerge5_pm::TypeOrExpr)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::TypeOrExpr::IVisitor, prefixmerge5_pm::TypeOrExpr::IVisitor)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::TypeOrExprToResolve, prefixmerge5_pm::TypeOrExprToResolve)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::QualifiedName, prefixmerge5_pm::QualifiedName)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::QualifiedName::IVisitor, prefixmerge5_pm::QualifiedName::IVisitor)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::Name, prefixmerge5_pm::Name)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::MemberName, prefixmerge5_pm::MemberName)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::CallExpr, prefixmerge5_pm::CallExpr)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::CtorExpr, prefixmerge5_pm::CtorExpr)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::MulExpr, prefixmerge5_pm::MulExpr)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::ConstType, prefixmerge5_pm::ConstType)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::PointerType, prefixmerge5_pm::PointerType)
	IMPL_TYPE_INFO_RENAME(prefixmerge5_pm::FunctionType, prefixmerge5_pm::FunctionType)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::TypeOrExpr)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

	END_CLASS_MEMBER(prefixmerge5_pm::TypeOrExpr)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::TypeOrExprToResolve)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::TypeOrExprToResolve>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(candidates)
	END_CLASS_MEMBER(prefixmerge5_pm::TypeOrExprToResolve)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::QualifiedName)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

	END_CLASS_MEMBER(prefixmerge5_pm::QualifiedName)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::Name)
		CLASS_MEMBER_BASE(prefixmerge5_pm::QualifiedName)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::Name>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(name)
	END_CLASS_MEMBER(prefixmerge5_pm::Name)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::MemberName)
		CLASS_MEMBER_BASE(prefixmerge5_pm::QualifiedName)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::MemberName>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(parent)
		CLASS_MEMBER_FIELD(member)
	END_CLASS_MEMBER(prefixmerge5_pm::MemberName)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::CallExpr)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::CallExpr>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(func)
		CLASS_MEMBER_FIELD(args)
	END_CLASS_MEMBER(prefixmerge5_pm::CallExpr)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::CtorExpr)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::CtorExpr>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(type)
		CLASS_MEMBER_FIELD(args)
	END_CLASS_MEMBER(prefixmerge5_pm::CtorExpr)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::MulExpr)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::MulExpr>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(first)
		CLASS_MEMBER_FIELD(second)
	END_CLASS_MEMBER(prefixmerge5_pm::MulExpr)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::ConstType)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::ConstType>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(type)
	END_CLASS_MEMBER(prefixmerge5_pm::ConstType)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::PointerType)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::PointerType>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(type)
	END_CLASS_MEMBER(prefixmerge5_pm::PointerType)

	BEGIN_CLASS_MEMBER(prefixmerge5_pm::FunctionType)
		CLASS_MEMBER_BASE(prefixmerge5_pm::TypeOrExpr)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<prefixmerge5_pm::FunctionType>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(returnType)
		CLASS_MEMBER_FIELD(args)
	END_CLASS_MEMBER(prefixmerge5_pm::FunctionType)

	BEGIN_INTERFACE_MEMBER(prefixmerge5_pm::TypeOrExpr::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::TypeOrExprToResolve* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::QualifiedName* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::CallExpr* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::CtorExpr* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::MulExpr* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::ConstType* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::PointerType* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::TypeOrExpr::IVisitor::*)(prefixmerge5_pm::FunctionType* node))
	END_INTERFACE_MEMBER(prefixmerge5_pm::TypeOrExpr)

	BEGIN_INTERFACE_MEMBER(prefixmerge5_pm::QualifiedName::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::QualifiedName::IVisitor::*)(prefixmerge5_pm::Name* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(prefixmerge5_pm::QualifiedName::IVisitor::*)(prefixmerge5_pm::MemberName* node))
	END_INTERFACE_MEMBER(prefixmerge5_pm::QualifiedName)

#endif

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	class PrefixMerge5_PmTypeOrExprTypeLoader : public vl::Object, public ITypeLoader
	{
	public:
		void Load(ITypeManager* manager)
		{
			ADD_TYPE_INFO(prefixmerge5_pm::TypeOrExpr)
			ADD_TYPE_INFO(prefixmerge5_pm::TypeOrExpr::IVisitor)
			ADD_TYPE_INFO(prefixmerge5_pm::TypeOrExprToResolve)
			ADD_TYPE_INFO(prefixmerge5_pm::QualifiedName)
			ADD_TYPE_INFO(prefixmerge5_pm::QualifiedName::IVisitor)
			ADD_TYPE_INFO(prefixmerge5_pm::Name)
			ADD_TYPE_INFO(prefixmerge5_pm::MemberName)
			ADD_TYPE_INFO(prefixmerge5_pm::CallExpr)
			ADD_TYPE_INFO(prefixmerge5_pm::CtorExpr)
			ADD_TYPE_INFO(prefixmerge5_pm::MulExpr)
			ADD_TYPE_INFO(prefixmerge5_pm::ConstType)
			ADD_TYPE_INFO(prefixmerge5_pm::PointerType)
			ADD_TYPE_INFO(prefixmerge5_pm::FunctionType)
		}

		void Unload(ITypeManager* manager)
		{
		}
	};
#endif
#endif

	bool PrefixMerge5_PmTypeOrExprLoadTypes()
	{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		if (auto manager = GetGlobalTypeManager())
		{
			auto loader = Ptr(new PrefixMerge5_PmTypeOrExprTypeLoader);
			return manager->AddTypeLoader(loader);
		}
#endif
		return false;
	}
}
