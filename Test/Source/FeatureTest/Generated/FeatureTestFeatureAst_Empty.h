/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:FeatureAst
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_PARSER2_UNITTEST_FEATURETEST_FEATUREAST_AST_EMPTY_VISITOR
#define VCZH_PARSER2_UNITTEST_FEATURETEST_FEATUREAST_AST_EMPTY_VISITOR

#include "FeatureTestFeatureAst.h"

namespace featuretest::empty_visitor
{
	/// <summary>An empty visitor, overriding all abstract methods with empty implementations.</summary>
	class FeatureVisitor : public vl::Object, public Feature::IVisitor
	{
	protected:
		// Dispatch (virtual) --------------------------------

	public:
		// Visitor Members -----------------------------------
		void Visit(FeatureToResolve* node) override;
		void Visit(OptionalFeature* node) override;
		void Visit(NestedOptionalFeature* node) override;
		void Visit(BranchedOptionalFeature* node) override;
		void Visit(PbaFeature* node) override;
		void Visit(Pwa1Feature* node) override;
		void Visit(PwlFeature* node) override;
		void Visit(ClFeature* node) override;
		void Visit(FaFeature* node) override;
	};

}
#endif