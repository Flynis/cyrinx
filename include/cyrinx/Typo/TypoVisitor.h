#ifndef CYRINX_TYPO_TYPO_VISITOR_H
#define CYRINX_TYPO_TYPO_VISITOR_H

#include <string>

#include "clang/AST/AST.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/RecursiveASTVisitor.h"

#include "cyrinx/Typo/TypoContext.h"

namespace cyrinx {

class TypoVisitor : public clang::RecursiveASTVisitor<TypoVisitor> {

TypoContext &context;

clang::ASTContext &astContext;

public:
  explicit TypoVisitor(clang::ASTContext &astContext, TypoContext &context)
    : context(context), astContext(astContext) {}

  virtual bool VisitVarDecl(clang::VarDecl *decl);

  virtual bool VisitFunctionDecl(clang::FunctionDecl *decl);

  virtual bool VisitTagDecl(clang::TagDecl *decl);

  virtual bool VisitNamespaceDecl(clang::NamespaceDecl *decl);

private:
  void processName(std::string &name);
  void processDeclContext(clang::DeclContext *declContext);
};

} // namespace cyrinx

#endif // CYRINX_TYPO_TYPO_VISITOR_H