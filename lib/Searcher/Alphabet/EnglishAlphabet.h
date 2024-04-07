#ifndef CYRINX_SEARCHER_ALPHABET_ENGLISH_ALPHABET_H
#define CYRINX_SEARCHER_ALPHABET_ENGLISH_ALPHABET_H

#include "Alphabet/SimpleAlphabet.h"

namespace cyrinx {

class EnglishAlphabet : public SimpleAlphabet {
public:
  EnglishAlphabet() : SimpleAlphabet('a', 'z') {}
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_ALPHABET_ENGLISH_ALPHABET_H