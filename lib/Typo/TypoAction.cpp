#include "TypoAction.h"

#include "TypoConsumer.h"

using namespace cyrinx;

TypoAction::ConsumerPtr TypoAction::CreateASTConsumer(
    clang::CompilerInstance &compiler, 
    llvm::StringRef in) 
{
  return std::make_unique<TypoConsumer>(compiler.getASTContext());
}

bool TypoAction::BeginSourceFileAction(clang::CompilerInstance &compiler) {
  ASTFrontendAction::BeginSourceFileAction(compiler);
  llvm::outs() << "Processing file '" << getCurrentFile() << "' ...\n";
  return true;
}

void TypoAction::EndSourceFileAction() {
  ASTFrontendAction::EndSourceFileAction();
  llvm::outs() << "Finished processing file ...\n";
}