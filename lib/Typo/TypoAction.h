#ifndef CYRINX_TYPO_TYPO_ACTION_H
#define CYRINX_TYPO_TYPO_ACTION_H

#include <memory>

#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"

namespace cyrinx {

class TypoAction : public clang::ASTFrontendAction {
public:
  using ConsumerPtr = std::unique_ptr<clang::ASTConsumer>;

  ConsumerPtr CreateASTConsumer(clang::CompilerInstance &compiler,
                                       llvm::StringRef in) override;

  bool BeginSourceFileAction(clang::CompilerInstance& compiler) override;

  void EndSourceFileAction() override;
};

} // namespace cyrinx

#endif // CYRINX_TYPO_TYPO_ACTION_H