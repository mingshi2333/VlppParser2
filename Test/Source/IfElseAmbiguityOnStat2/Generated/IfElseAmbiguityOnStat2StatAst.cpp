/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:StatAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#include "IfElseAmbiguityOnStat2StatAst.h"

namespace ifelseambiguityonstat2
{
/***********************************************************************
Visitor Pattern Implementation
***********************************************************************/

	void StatToResolve::Accept(Stat::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void DoStat::Accept(Stat::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void IfStat::Accept(Stat::IVisitor* visitor)
	{
		visitor->Visit(this);
	}

	void BlockStat::Accept(Stat::IVisitor* visitor)
	{
		visitor->Visit(this);
	}
}
namespace vl::reflection::description
{
#ifndef VCZH_DEBUG_NO_REFLECTION

	IMPL_TYPE_INFO_RENAME(ifelseambiguityonstat2::Stat, ifelseambiguityonstat2::Stat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguityonstat2::Stat::IVisitor, ifelseambiguityonstat2::Stat::IVisitor)
	IMPL_TYPE_INFO_RENAME(ifelseambiguityonstat2::StatToResolve, ifelseambiguityonstat2::StatToResolve)
	IMPL_TYPE_INFO_RENAME(ifelseambiguityonstat2::DoStat, ifelseambiguityonstat2::DoStat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguityonstat2::IfStat, ifelseambiguityonstat2::IfStat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguityonstat2::BlockStat, ifelseambiguityonstat2::BlockStat)
	IMPL_TYPE_INFO_RENAME(ifelseambiguityonstat2::Module, ifelseambiguityonstat2::Module)

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA

	BEGIN_CLASS_MEMBER(ifelseambiguityonstat2::Stat)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

	END_CLASS_MEMBER(ifelseambiguityonstat2::Stat)

	BEGIN_CLASS_MEMBER(ifelseambiguityonstat2::StatToResolve)
		CLASS_MEMBER_BASE(ifelseambiguityonstat2::Stat)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguityonstat2::StatToResolve>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(candidates)
	END_CLASS_MEMBER(ifelseambiguityonstat2::StatToResolve)

	BEGIN_CLASS_MEMBER(ifelseambiguityonstat2::DoStat)
		CLASS_MEMBER_BASE(ifelseambiguityonstat2::Stat)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguityonstat2::DoStat>(), NO_PARAMETER)

	END_CLASS_MEMBER(ifelseambiguityonstat2::DoStat)

	BEGIN_CLASS_MEMBER(ifelseambiguityonstat2::IfStat)
		CLASS_MEMBER_BASE(ifelseambiguityonstat2::Stat)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguityonstat2::IfStat>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(thenBranch)
		CLASS_MEMBER_FIELD(elseBranch)
	END_CLASS_MEMBER(ifelseambiguityonstat2::IfStat)

	BEGIN_CLASS_MEMBER(ifelseambiguityonstat2::BlockStat)
		CLASS_MEMBER_BASE(ifelseambiguityonstat2::Stat)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguityonstat2::BlockStat>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(stats)
	END_CLASS_MEMBER(ifelseambiguityonstat2::BlockStat)

	BEGIN_CLASS_MEMBER(ifelseambiguityonstat2::Module)
		CLASS_MEMBER_BASE(vl::glr::ParsingAstBase)

		CLASS_MEMBER_CONSTRUCTOR(vl::Ptr<ifelseambiguityonstat2::Module>(), NO_PARAMETER)

		CLASS_MEMBER_FIELD(stat)
	END_CLASS_MEMBER(ifelseambiguityonstat2::Module)

	BEGIN_INTERFACE_MEMBER(ifelseambiguityonstat2::Stat::IVisitor)
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguityonstat2::Stat::IVisitor::*)(ifelseambiguityonstat2::StatToResolve* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguityonstat2::Stat::IVisitor::*)(ifelseambiguityonstat2::DoStat* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguityonstat2::Stat::IVisitor::*)(ifelseambiguityonstat2::IfStat* node))
		CLASS_MEMBER_METHOD_OVERLOAD(Visit, {L"node"}, void(ifelseambiguityonstat2::Stat::IVisitor::*)(ifelseambiguityonstat2::BlockStat* node))
	END_INTERFACE_MEMBER(ifelseambiguityonstat2::Stat)

#endif

#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
	class IfElseAmbiguityOnStat2StatAstTypeLoader : public vl::Object, public ITypeLoader
	{
	public:
		void Load(ITypeManager* manager)
		{
			ADD_TYPE_INFO(ifelseambiguityonstat2::Stat)
			ADD_TYPE_INFO(ifelseambiguityonstat2::Stat::IVisitor)
			ADD_TYPE_INFO(ifelseambiguityonstat2::StatToResolve)
			ADD_TYPE_INFO(ifelseambiguityonstat2::DoStat)
			ADD_TYPE_INFO(ifelseambiguityonstat2::IfStat)
			ADD_TYPE_INFO(ifelseambiguityonstat2::BlockStat)
			ADD_TYPE_INFO(ifelseambiguityonstat2::Module)
		}

		void Unload(ITypeManager* manager)
		{
		}
	};
#endif
#endif

	bool IfElseAmbiguityOnStat2StatAstLoadTypes()
	{
#ifdef VCZH_DESCRIPTABLEOBJECT_WITH_METADATA
		if (auto manager = GetGlobalTypeManager())
		{
			auto loader = Ptr(new IfElseAmbiguityOnStat2StatAstTypeLoader);
			return manager->AddTypeLoader(loader);
		}
#endif
		return false;
	}
}
