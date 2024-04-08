#include "cyrinx/Typo/TypoVisitor.h"

#include <string>

#include "cyrinx/Text/IdentifierFilter.h"
#include "cyrinx/Text/Splitter.h"

using namespace clang;
using namespace cyrinx;
using namespace llvm;

bool TypoVisitor::VisitNamedDecl(NamedDecl *decl) {
  IdentifierInfo *idInfo = decl.getIdentifier();
  if (!idInfo) {
    return true;
  }
  string name = decl->getQualifiedNameAsString();
  IdentifierFilter &filter = context.getIdentifierFilter();
  bool valid = filter.isValidIdentifier(name);
  Splitter &splitter = context.getSplitter();
  string basename = splitter.getIdentifierName();
  auto &words = splitter.splitIdentifier(basename);
  outs() << "Identifier: " << name << ' ' << (valid) ? "valid" : "invalid" << '\n';
  for (auto &w : words) {
    outs() << w << '\n'
  }
  return true;
}