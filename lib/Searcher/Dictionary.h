#ifndef CYRINX_SEARCHER_DICTIONARY_H
#define CYRINX_SEARCHER_DICTIONARY_H

#include <string>
#include <vector>

namespace cyrinx {

class Dictionary {

  std::vector<std::string> words;

public:
  Dictionary(std::string &filename);

  std::vector<std::string>& getWords() { return words; }
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_DICTIONARY_H