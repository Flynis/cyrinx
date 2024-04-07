#ifndef CYRINX_SEARCHER_ALPHABET_SIMPLE_ALPHABET_H
#define CYRINX_SEARCHER_ALPHABET_SIMPLE_ALPHABET_H

#include "Alphabet/Alphabet.h"

namespace cyrinx {

class SimpleAlphabet : public Alphabet {

  char firstChar;

  char lastChar;

public:
  SimpleAlphabet(char firstChar, char lastChar) {
    this->firstChar = firstChar;
    this->lastChar = lastChar;
  }

  int mapChar(char ch) override {
    if (ch < firstChar || ch > lastChar) return -1;
    return ch - firstChar;
  }

  int size() override {
    return lastChar - firstChar + 1;
  }
};

} // namespace cyrinx

#endif // CYRINX_ALPHABET_SIMPLE_ALPHABET_H