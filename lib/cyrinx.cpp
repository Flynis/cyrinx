#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#include "cyrinx/OptionParser.h"
#include "cyrinx/Typo/TypoAction.h"
#include "cyrinx/Typo/TypoContext.h"

#include <fstream>

using namespace clang;
using namespace clang::tooling;
using namespace cyrinx;
using namespace llvm;
using namespace std;

static cl::OptionCategory CyrinxCategory("cyrinx options");
static cl::extrahelp CommonHelp(OptionParser::HelpMessage);
static cl::opt<string> DictionaryPath(
  "d", 
  cl::desc("Specify dictionary filename"), 
  cl::value_desc("dictionary"),
  cl::init("dict.txt"),
  cl::cat(CyrinxCategory)
);
static cl::opt<string> NamespacesPath(
  "n", 
  cl::desc("Specify file with excluded namespaces"), 
  cl::value_desc("filename"),
  cl::init(""),
  cl::cat(CyrinxCategory)
);

class TypoFrontendActionFactory : public FrontendActionFactory {
TypoContext &context;
public:
  TypoFrontendActionFactory(TypoContext &context) : context(context) {}

  unique_ptr<FrontendAction> create() override {
    return make_unique<TypoAction>(context);
  }
};

int main(int argc, const char **argv) {
  llvm::cl::SetVersionPrinter(
      [](llvm::raw_ostream &os) { os << "cyrinx version 1.0.0\n"; });

  auto expectedParser = 
      OptionParser::create(argc, argv, CyrinxCategory);
  if (!expectedParser) {
    errs() << expectedParser.takeError();
    return 1;
  }
  OptionParser &optionParser = expectedParser.get();
  ClangTool Tool(optionParser.getCompilations(),
                  optionParser.getSourcePathList());
  Tool.appendArgumentsAdjuster(
        getInsertArgumentAdjuster("-fparse-all-comments", ArgumentInsertPosition::BEGIN));

  ifstream dictStream(DictionaryPath);
  if(dictStream.fail()) {
    errs() << "Dicitonary not found\nTry -d <dictionary> option\n"; 
    return 0;
  }
  ifstream namespacesStream(NamespacesPath);
  if(!NamespacesPath.empty() && namespacesStream.fail()) {
    errs() << "File with namespaces not found\nTry -n <filename> option\n"; 
    return 0;
  }
  TypoContext context(dictStream, namespacesStream);

  TypoFrontendActionFactory factory(context);
  return Tool.run(&factory);
}
