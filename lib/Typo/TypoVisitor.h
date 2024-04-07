#ifndef CYRINX_TYPO_TYPO_VISITOR_H
#define CYRINX_TYPO_TYPO_VISITOR_H

#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/RecursiveASTVisitor.h"

namespace cyrinx {

class TypoVisitor : public clang::RecursiveASTVisitor<TypoVisitor> {

clang::ASTContext &context;

public:
  explicit TypoVisitor(clang::ASTContext &context)
    : context(context) {}

  virtual bool VisitNamedDecl(clang::NamedDecl *decl);
};

} // namespace cyrinx

#endif // CYRINX_TYPO_TYPO_VISITOR_H