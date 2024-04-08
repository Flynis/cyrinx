#ifndef CYRINX_TYPO_TYPO_CONTEXT_H
#define CYRINX_TYPO_TYPO_CONTEXT_H

#include <fstream>

#include "cyrinx/Alphabet/Alphabet.h"
#include "cyrinx/Searcher/Dictionary.h"
#include "cyrinx/Searcher/Searcher.h"
#include "cyrinx/Text/IdentifierFilter.h"
#include "cyrinx/Text/Splitter.h"

namespace cyrinx {

class TypoContext {

Alphabet *alphabet;

Dictionary dict;

Searcher *searcher;

IdentifierFilter filter;

Splitter splitter;

public:
  TypoContext(std::istream &dictStream, std::istream &namespacesStream);

  Searcher& getSearcher() { return *searcher; }

  IdentifierFilter& getIdentifierFilter() { return filter; }

  Splitter& getSplitter() {return splitter; }

  ~TypoContext();
};

} // namespace cyrinx

#endif // CYRINX_TYPO_TYPO_CONTEXT_H