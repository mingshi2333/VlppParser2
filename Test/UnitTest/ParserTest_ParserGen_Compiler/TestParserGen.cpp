#include "../../../Source/ParserGen_Generated/ParserGenTypeAst_Json.h"
#include "../../../Source/ParserGen_Generated/ParserGenRuleAst_Json.h"
#include "../../../Source/ParserGen_Generated/ParserGenTypeParser.h"
#include "../../../Source/ParserGen_Generated/ParserGenRuleParser.h"
#include "../../../Source/ParserGen_Printer/AstToCode.h"
#include "../../../Source/ParserGen/Compiler.h"
#include "../../../Source/Ast/AstCppGen.h"
#include "../../../Source/Lexer/LexerCppGen.h"
#include "../../../Source/Syntax/SyntaxCppGen.h"
#include "../../Source/LogParser.h"

using namespace vl::console;

extern WString GetTestParserInputPath(const WString& parserName);
extern FilePath GetOutputDir(const WString& parserName);
extern void WriteFilesIfChanged(FilePath outputDir, Dictionary<WString, WString>& files);

struct ParserDef
{
	WString parserName;
	WString astName;
	WString ruleName;
};

TEST_FILE
{
	TypeParser typeParser;
	RuleParser ruleParser;

	List<ParserDef> parsersToLoad;
	parsersToLoad.Add(ParserDef{ L"Calculator",					L"ExprAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"IfElseAmbiguity",			L"StatAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"IfElseAmbiguity2",			L"StatAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"IfElseAmbiguityOnStat",		L"StatAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"IfElseAmbiguityOnStat2",		L"StatAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"IfElsePriority",				L"StatAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"IfElseSwitch",				L"StatAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"IfElseManual",				L"StatAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"GenericAmbiguity",			L"ExprAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"FeatureTest",				L"FeatureAst",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"BinaryOp",					L"ExprAst",		L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge1_Lri",			L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge2_LriRequired",	L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge3_LriNested",		L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge4_LriMultiple",	L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge5_Pm",			L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge6_Pm2",			L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge7_PmSwitch",		L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge8_PmVariadic",	L"TypeOrExpr",	L"Module" });
	parsersToLoad.Add(ParserDef{ L"PrefixMerge9_PmLoop",		L"File",		L"Module" });

	for (auto&& [_parserName, _astName, _ruleName] : parsersToLoad)
	{
		auto parserName = _parserName;
		auto astName = _astName;
		auto ruleName = _ruleName;
		TEST_CATEGORY(L"Test ParserGen on " + parserName)
		{
			FilePath dirParser = GetTestParserInputPath(parserName);
			FilePath dirOutput = GetOutputDir(L"ParserGen");
			FilePath dirGenerated = dirParser / L"Generated";
			if (!Folder(dirGenerated).Exists())
			{
				Folder(dirGenerated).Create(true);
			}

			Ptr<GlrAstFile> astFile;
			Ptr<GlrSyntaxFile> syntaxFile, syntaxRewrittenExpected;

			TEST_CASE(L"Parse Ast.txt")
			{
				auto input = File(dirParser / L"Syntax/Ast.txt").ReadAllTextByBom();
				astFile = typeParser.ParseFile(input);
				auto actualJson = PrintAstJson<json_visitor::TypeAstVisitor>(astFile);
				File(dirOutput / (L"Ast[" + parserName + L"].txt")).WriteAllText(actualJson, true, BomEncoder::Utf8);
			});

			TEST_CASE(L"Parse Syntax.txt")
			{
				auto input = File(dirParser / L"Syntax/Syntax.txt").ReadAllTextByBom();
				syntaxFile = ruleParser.ParseFile(input);
				auto actualJson = PrintAstJson<json_visitor::RuleAstVisitor>(syntaxFile);
				File(dirOutput / (L"Syntax[" + parserName + L"].txt")).WriteAllText(actualJson, true, BomEncoder::Utf8);
			});

			WString formattedActual, formattedExpected;
			{
				File fileRewritten = dirParser / L"Syntax/SyntaxRewritten.txt";
				if (fileRewritten.Exists())
				{
					TEST_CASE(L"Parse SyntaxRewritten.txt")
					{
						auto input = fileRewritten.ReadAllTextByBom();
						syntaxRewrittenExpected = ruleParser.ParseFile(input);
						formattedExpected = GenerateToStream([&](TextWriter& writer) { SyntaxAstToCode(syntaxRewrittenExpected, writer); });
						File(dirOutput / (L"SyntaxRewrittenExpected[" + parserName + L"].txt")).WriteAllText(formattedExpected, true, BomEncoder::Utf8);
					});
				}
			}

			ParserSymbolManager global;
			AstSymbolManager astManager(global);
			LexerSymbolManager lexerManager(global);
			SyntaxSymbolManager syntaxManager(global);
			Executable executable;
			Metadata metadata;

			global.name = parserName;
			Fill(global.includes, L"../../../../Source/AstBase.h", L"../../../../Source/SyntaxBase.h");
			global.cppNss.Add(wlower(parserName));
			global.headerGuard = L"VCZH_PARSER2_UNITTEST_" + wupper(parserName);
			syntaxManager.name = ruleName + L"Parser";

			auto astDefFileGroup = astManager.CreateFileGroup(astName);
			astDefFileGroup->cppNss.Add(wlower(parserName));
			astDefFileGroup->refNss.Add(wlower(parserName));
			astDefFileGroup->classPrefix = L"";

			auto astDefFile = astDefFileGroup->CreateFile(astName);
			auto output = GenerateParserFileNames(global);
			GenerateAstFileNames(astManager, output);
			GenerateSyntaxFileNames(syntaxManager, output);

			Dictionary<WString, WString> files;
			TEST_CASE(L"CompilerAst")
			{
				CompileAst(astManager, astDefFile, astFile);
				TEST_ASSERT(global.Errors().Count() == 0);

				auto rewrittenAst = TypeSymbolToAst(astManager, true);
				auto formattedAst = GenerateToStream([&](TextWriter& writer) { TypeAstToCode(rewrittenAst, writer); });
				File(dirOutput / (L"AstRewrittenActual[" + parserName + L"].txt")).WriteAllText(formattedAst, true, BomEncoder::Utf8);

				WriteAstFiles(astManager, output, files);
			});

			TEST_CASE(L"CompilerLexer")
			{
				auto lexerInput = File(dirParser / L"Syntax/Lexer.txt").ReadAllTextByBom();
				CompileLexer(lexerManager, lexerInput);
				TEST_ASSERT(global.Errors().Count() == 0);
				WriteLexerFiles(lexerManager, output, files);
			});

			TEST_CASE(L"CompilerSyntax")
			{
				auto logSyntax = [&](vint phase)
				{
					LogSyntaxWithPath(
						syntaxManager,
						dirOutput / (L"NFA[" + parserName + L"][" + itow(phase) + L"].txt"),
						[&](vint32_t index) { auto type = output->classIds.Keys()[output->classIds.Values().IndexOf(index)]; return type->Name(); },
						[&](vint32_t index) { auto prop = output->fieldIds.Keys()[output->fieldIds.Values().IndexOf(index)]; return prop->Parent()->Name() + L"::" + prop->Name(); },
						[&](vint32_t index) { auto token = lexerManager.Tokens()[lexerManager.TokenOrder()[index]]; return token->displayText == L"" ? token->Name() : L"\"" + token->displayText + L"\""; }
						);
				};

				auto syntaxRewrittenActual = CompileSyntax(astManager, lexerManager, syntaxManager, output, syntaxFile);
				if (syntaxRewrittenActual)
				{
					formattedActual = GenerateToStream([&](TextWriter& writer) { SyntaxAstToCode(syntaxRewrittenActual, writer); });
					File(dirOutput / (L"SyntaxRewrittenActual[" + parserName + L"].txt")).WriteAllText(formattedActual, true, BomEncoder::Utf8);
				}

				TEST_ASSERT(global.Errors().Count() == 0);
				logSyntax(1);

				TEST_ASSERT((bool)syntaxRewrittenActual == (bool)syntaxRewrittenExpected);
				if (syntaxRewrittenExpected)
				{
					TEST_ASSERT(formattedActual == formattedExpected);
				}

				syntaxManager.BuildCompactNFA();
				TEST_ASSERT(global.Errors().Count() == 0);
				logSyntax(2);

				syntaxManager.BuildCrossReferencedNFA();
				TEST_ASSERT(global.Errors().Count() == 0);
				logSyntax(3);

				syntaxManager.BuildAutomaton(lexerManager.Tokens().Count(), executable, metadata);
				TEST_ASSERT(global.Errors().Count() == 0);

				LogAutomatonWithPath(
					dirOutput / (L"NFA[" + parserName + L"][Automaton].txt"),
					executable,
					metadata,
					[&](vint32_t index) { auto type = output->classIds.Keys()[output->classIds.Values().IndexOf(index)]; return type->Name(); },
					[&](vint32_t index) { auto prop = output->fieldIds.Keys()[output->fieldIds.Values().IndexOf(index)]; return prop->Parent()->Name() + L"::" + prop->Name(); },
					[&](vint32_t index) { auto token = lexerManager.Tokens()[lexerManager.TokenOrder()[index]]; return token->displayText == L"" ? token->Name() : L"\"" + token->displayText + L"\""; }
					);

				WriteSyntaxFiles(syntaxManager, executable, metadata, output, files);
			});

			if (global.Errors().Count() == 0)
			{
				WriteFilesIfChanged(dirGenerated, files);

				if (parserName == L"Calculator")
				{
#if defined VCZH_MSVC
					TEST_CATEGORY(L"Ensure Calculator Generated Files Identical")
					{
						// Compare Source/Calculator/Generated with Source/Calculator/Parser
						for (auto&& [_name, _content] : files)
						{
							auto name = _name;
							auto content = _content;
							TEST_CASE(name)
							{
								auto expected = File(FilePath(GetTestParserInputPath(parserName)) / L"Parser" / name).ReadAllTextByBom();
								TEST_ASSERT(content == expected);
							});
						}
					});
#elif defined VCZH_GCC
					Console::WriteLine(L"**** Skipped comparing C++ files in Linux ****");
#endif
				}
			}
		});
	}
}