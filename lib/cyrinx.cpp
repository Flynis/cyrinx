#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

using namespace clang::tooling;
using namespace llvm;
using namespace std;

static cl::OptionCategory CyrinxCategory("cyrinx options");
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);
static cl::extrahelp MoreHelp(
  "\tFor example, to run cyrinx on all files in a subtree of the\n"
  "\tsource tree, use:\n"
  "\n"
  "\t  find path/in/subtree -name '*.cpp'|xargs cyrinx\n"
  "\n"
); 
static cl::opt<string> DictionaryFilename(
  "d", 
  cl::desc("Specify dictionary filename"), 
  cl::value_desc("dictionary"),
  cl::init("dict.txt"),
  cl::cat(CyrinxCategory)
);

int main(int argc, const char **argv) {
  llvm::cl::SetVersionPrinter(
      [](llvm::raw_ostream &os) { os << "cyrinx version 1.0.0\n"; });
  auto expectedParser = 
      CommonOptionsParser::create(argc, argv, CyrinxCategory);
  if (!expectedParser) {
    errs() << expectedParser.takeError();
    return 1;
  }
  CommonOptionsParser &optionParser = expectedParser.get();
  ClangTool Tool(optionParser.getCompilations(),
                  optionParser.getSourcePathList());
  return 0;
}
