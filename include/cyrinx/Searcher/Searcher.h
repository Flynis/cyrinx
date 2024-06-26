#ifndef CYRINX_SEARCHER_SEARCHER_H
#define CYRINX_SEARCHER_SEARCHER_H

#include <string>
#include <unordered_set>

#include "cyrinx/Alphabet/Alphabet.h"
#include "cyrinx/Searcher/Dictionary.h"
#include "cyrinx/Searcher/SearchResult.h"

namespace cyrinx {

class Searcher {
protected:
Alphabet &alphabet;

Dictionary &dictionary;

std::unordered_set<SearchResult> indexes;

public:
  Searcher(Alphabet &alphabet, Dictionary &dictionary) 
    : alphabet(alphabet), dictionary(dictionary) {}

  /**
   * Searches for a given word in the dictionary taking into account 
   * maxDistance misspells.
   * @returns set of word indexes in the dictionary.
  */
  virtual std::unordered_set<SearchResult>& search(std::string_view &word, 
                                                    unsigned maxDistance) = 0;

  virtual ~Searcher() {}
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_SEARCHER_H