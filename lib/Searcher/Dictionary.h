#ifndef CYRINX_SEARCHER_DICTIONARY_H
#define CYRINX_SEARCHER_DICTIONARY_H

#include <vector>

namespace cyrinx {

class Dictionary {

  std::vector<string> words;

public:
  Dictionary(std::string filename);

  std::vector<string> getWords() { return words; }
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_DICTIONARY_H