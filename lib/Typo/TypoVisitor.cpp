#include "cyrinx/Typo/TypoVisitor.h"

#include <string>

#include "cyrinx/Text/IdentifierFilter.h"
#include "cyrinx/Text/Splitter.h"

using namespace clang;
using namespace cyrinx;
using namespace llvm;
using namespace std;

bool TypoVisitor::VisitNamedDecl(NamedDecl *decl) {
  IdentifierInfo *idInfo = decl->getIdentifier();
  if (decl->isInStdNamespace() || !idInfo) {
    return true;
  }
  return true;
  DeclContext *ctx = decl->getDeclContext();
  IdentifierFilter &filter = context.getIdentifierFilter();
  while(!ctx->isFileContext()) {
    if(ctx->isNamespace()) {
      NamespaceDecl *spaceDecl = cast<NamespaceDecl>(ctx);
      string spaceName = spaceDecl->getNameAsString();
      outs() << "Space " << spaceName << '\n';
      if(!filter.isValidIdentifier(spaceName)) {
        return true;
      }
    }
    ctx = ctx->getParent();
  }
  string name = decl->getQualifiedNameAsString();
  if(name[0] == '_') {
    decl->dump(outs());
  }
  return processIdentifier(name);
}

bool TypoVisitor::VisitFunctionDecl(FunctionDecl *decl) {
  IdentifierInfo *idInfo = decl->getIdentifier();
  if (!idInfo) {
    return true;
  }
  return true;
  string name = decl->getQualifiedNameAsString();
  outs() << "Function\n" << processIdentifier(name);
  if (processIdentifier(name)) {
    outs() << "valid func\n";
    for (auto iter = decl->param_begin(); iter != decl->param_end(); iter++) {
      ParmVarDecl *parmDecl = *iter;
      IdentifierInfo *parmInfo = parmDecl->getIdentifier();
      if (parmInfo) {
        string parmName = parmDecl->getNameAsString();
        outs() << processIdentifier(parmName);
      }
    }
  }
  return true;
}

bool TypoVisitor::VisitVarDecl(VarDecl *decl) {
  IdentifierInfo *idInfo = decl->getIdentifier();
  if (!idInfo) {
    return true;
  }
  return true;
  string name = decl->getQualifiedNameAsString();
  if (!isa<ParmVarDecl>(decl)) {
    outs() << "Var\n" << processIdentifier(name);
  }
  return true;
}

bool TypoVisitor::processIdentifier(string &id) {
  IdentifierFilter &filter = context.getIdentifierFilter();
  // if (!filter.isValidIdentifier(id)) {
  //   return true;
  // }
  Splitter &splitter = context.getSplitter();
  string basename = splitter.getIdentifierName(id);
  auto &words = splitter.splitIdentifier(basename);
  outs() << "Identifier: " << id << ' ' << basename << '\n';
  Searcher &searcher = context.getSearcher();
  auto &dict = context.getDictionary().getWords();
  const int maxDistance = 2;
  for (auto &w : words) {
    outs() << w << '\n';
    if(w.length() >= maxDistance) {
      auto &variants = searcher.search(w, maxDistance);
      // outs() << "variants\n";
      // for(auto &variant : variants) {
      //   outs() << dict[variant] << ' ';
      // }
    }
  }
  outs() << '\n';
  return true;
}