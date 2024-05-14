#include "cyrinx/Typo/TypoAction.h"

#include "cyrinx/Typo/TypoConsumer.h"

using namespace clang;
using namespace cyrinx;
using namespace llvm;

TypoAction::ConsumerPtr TypoAction::CreateASTConsumer(
    CompilerInstance &compiler, 
    StringRef in) 
{
  return std::make_unique<TypoConsumer>(compiler.getASTContext(), context);
}

bool TypoAction::BeginSourceFileAction(CompilerInstance &compiler) {
  ASTFrontendAction::BeginSourceFileAction(compiler);
  //outs() << "Processing file '" << getCurrentFile() << "' ...\n";
  return true;
}

void TypoAction::EndSourceFileAction() {
  ASTFrontendAction::EndSourceFileAction();
  //outs() << "Finished processing file ...\n";
}