#ifndef CYRINX_TYPO_TYPO_CONTEXT_H
#define CYRINX_TYPO_TYPO_CONTEXT_H

#include <string>
#include <unordered_set>

#include "Searcher/Alphabet/Alphabet.h"
#include "Searcher/Dictionary.h"

namespace cyrinx {

class TypoContext {

std::unordered_set<std::string> exclNamespaces;

std::unordered_set<std::string_view> exclNamespacesViews;

Alphabet alphabet;

Dictionary dict;

public:
  TypoContext(std::string &dictPath, std::string &exclNamespacesPath);

  std::unordered_set<std::string>& getExcludedNamespaces() const 
  { return exclNamespaces; }

  std::unordered_set<std::string_view>& getExcludedNamespacesViews() const 
  { return exclNamespacesViews; }

  Alphabet& getAlphabet() const { return alphabet; }

  Dictionary& getDictionary() const {return dict; }
};

} // namespace cyrinx

#endif // CYRINX_TYPO_TYPO_CONTEXT_H