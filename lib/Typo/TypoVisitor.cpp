#include "TypoVisitor.h"

#include <string>

bool cyrinx::TypoVisitor::VisitNamedDecl(clang::NamedDecl *decl) {
  if(decl->isInStdNamespace()) {
    return true;
  }
  std::string name = decl->getQualifiedNameAsString();
  if (!name.empty()) {
    llvm::outs() << name << '\n';
  }
  return true;
}