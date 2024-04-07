#ifndef CYRINX_SEARCHER_BITAP_SEARCHER_H
#define CYRINX_SEARCHER_BITAP_SEARCHER_H

#include "Searcher/Searcher.h"

namespace cyrinx {

class BitapSearcher : public Searcher {
public:
  BitapSearcher(Alphabet &alphabet, Dictionary &dictionary) 
    : Searcher(alphabet, dictionary) {}
  
  std::unordered_set<int>& search(std::string &word, int maxDistance) override;

  virtual ~Searcher() {}
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_BITAP_SEARCHER_H