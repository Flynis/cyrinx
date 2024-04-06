#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

using namespace clang::tooling;
using namespace llvm;

static cl::OptionCategory CyrinxCategory("cyrinx options");

static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);
static cl::extrahelp MoreHelp("\nMore help text...\n"); // TODO

int main(int argc, const char **argv) {
  outs() << "IM ALIVE\n";
  auto expectedParser = 
      CommonOptionsParser::create(argc, argv, CyrinxCategory);
  if (!expectedParser) {
    errs() << expectedParser.takeError();
    return 1;
  }
  CommonOptionsParser &optionParser = expectedParser.get();
  ClangTool Tool(optionParser.getCompilations(),
                  optionParser.getSourcePathList());

  outs() << "OKAY\n";
  return 0;
}
