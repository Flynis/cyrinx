#include "cyrinx/Typo/TypoVisitor.h"

#include <string>

#include <clang/Tooling/Core/Diagnostic.h>

#include "cyrinx/Text/IdentifierFilter.h"
#include "cyrinx/Text/Splitter.h"
#include "cyrinx/Text/Support.h"

using namespace clang;
using namespace clang::tooling;
using namespace cyrinx;
using namespace llvm;
using namespace std;

bool TypoVisitor::VisitFunctionDecl(FunctionDecl *decl) {
  if (!decl->getIdentifier() || decl->isExternC()) {
    // skip
    return true;
  }
  IdentifierFilter &filter = context.getIdentifierFilter();
  string name = decl->getQualifiedNameAsString();
  if (filter.isValidFunctionName(name)) {
    //outs() << "Function " << name << " valid\n";
    processName(name, decl);
    processDeclContext(decl);
  }
  return true;
}

bool TypoVisitor::VisitTagDecl(TagDecl *decl) { 
  if(isa<ClassTemplateSpecializationDecl>(decl) || !decl->getIdentifier()) {
    // skip
    return true;
  }
  string name = decl->getQualifiedNameAsString();
  IdentifierFilter &filter = context.getIdentifierFilter();
  if (filter.isValidGlobalTag(name)) {
    //outs() << "Tag " << name << " valid\n";
    processName(name, decl);
    processDeclContext(decl);
  }
  return true; 
}

bool TypoVisitor::VisitNamespaceDecl(NamespaceDecl *decl) {
  if(!decl->getIdentifier()) {
    // skip
    return true;
  }
  string name = decl->getQualifiedNameAsString();
  IdentifierFilter &filter = context.getIdentifierFilter();
  if (filter.isValidQualifiedName(name)) {
    //outs() << "Namespace " << name << " valid\n";
    processName(name, decl);
    processDeclContext(decl);
  }
  return true;
}

bool TypoVisitor::VisitVarDecl(VarDecl *decl) {
  if(!decl->isFileVarDecl() || decl->isExternC()) {
    // skip
    return true;
  }
  string name = decl->getQualifiedNameAsString();
  IdentifierFilter &filter = context.getIdentifierFilter();
  if (filter.isValidQualifiedName(name)) {
    //outs() << "Var " << name << " valid\n";
    processName(name, decl);
  }
  return true;
}

void TypoVisitor::processName(std::string &name, NamedDecl *decl) {
  Splitter &splitter = context.getSplitter();
  string basename = splitter.getIdentifierName(name);
  if(StrStartsWith(basename, IdentifierFilter::stdguard)) {
    return;
  }
  auto &words = splitter.splitIdentifier(basename);
  //outs() << "Identifier: " << name << ' ' << basename << '\n';
  StrToLower(basename);
  Searcher &searcher = context.getSearcher();
  //auto &dict = context.getDictionary().getWords();
  const unsigned maxDistance = 2;
  for (auto &w : words) {
    if(w.length() > maxDistance) {
      auto &variants = searcher.search(w, maxDistance);
      bool isEqual = false;
      for(auto &variant : variants) {
        if(variant.distance == 0) {
          isEqual = true;
          break;
        }
      }
      if(!isEqual) {
        // outs() << w << '\n';
        // outs() << "dict variants\n";
        // for(auto &variant : variants) {
        //   outs() << dict[variant.dictionaryIndex] << ' ';
        // }
        // outs() << '\n';
        SourceLocation loc = decl->getLocation();
        
        loc.dump(astContext.getSourceManager());
        //string message = "Typo in word '" + w + "'";
        //DiagnosticMessage msg(StringRef(message), astContext.getSourceManager(), decl->getLocation());
        outs() << "\t\tTypo in word '" << w << "'\n";
      }
    }
  }
}

void TypoVisitor::processDeclContext(DeclContext *declContext) {
  for (auto iter = declContext->decls_begin(); iter != declContext->decls_end(); iter++) {
    Decl *decl = *iter;
    NamedDecl *namedDecl = dyn_cast<NamedDecl>(decl);
    if(!namedDecl) {
      continue;
    }
    IdentifierInfo *idInfo = namedDecl->getIdentifier();
    if (idInfo) {
      string name = namedDecl->getNameAsString();
      processName(name, namedDecl);
    }
  }
}
