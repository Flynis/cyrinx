#ifndef CYRINX_SEARCHER_DICTIONARY_H
#define CYRINX_SEARCHER_DICTIONARY_H

#include <fstream>
#include <string>
#include <vector>

namespace cyrinx {

class Dictionary {

std::vector<std::string> words;

public:
  Dictionary(std::istream &input);

  std::vector<std::string>& getWords() { return words; }
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_DICTIONARY_H