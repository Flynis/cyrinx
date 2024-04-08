#ifndef CYRINX_SEARCHER_BITAP_SEARCHER_H
#define CYRINX_SEARCHER_BITAP_SEARCHER_H

#include <vector>

#include "cyrinx/Searcher/Searcher.h"

namespace cyrinx {

class BitapSearcher : public Searcher {

std::vector<int> tableRow;

std::vector<int> wordMask;

int endMask;

int maxDistance;

public:
  BitapSearcher(Alphabet &alphabet, Dictionary &dictionary) 
    : Searcher(alphabet, dictionary), tableRow(32), wordMask(alphabet.size() + 1) {}
  
  std::unordered_set<int>& search(std::string_view &word, int maxDistance) override;
  
private:
  int normalizeChar(char ch);

  bool areClose(size_t len1, size_t len2, size_t eps);
  
  bool isSimilarWord(std::string &word);
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_BITAP_SEARCHER_H