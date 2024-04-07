#ifndef CYRINX_TYPO_TYPO_CONSUMER_H
#define CYRINX_TYPO_TYPO_CONSUMER_H

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"

#include "TypoVisitor.h"

namespace cyrinx {

class TypoConsumer : public clang::ASTConsumer {

TypoVisitor visitor;

public:
  explicit TypoConsumer(clang::ASTContext &context)
    : visitor(context) { }

  void HandleTranslationUnit(clang::ASTContext &context) override {
    visitor.TraverseDecl(context.getTranslationUnitDecl());
  }
};

} // namespace cyrinx

#endif // CYRINX_TYPO_TYPO_CONSUMER_H