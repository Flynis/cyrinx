#ifndef CYRINX_ALPHABET_ENGLISH_ALPHABET_H
#define CYRINX_ALPHABET_ENGLISH_ALPHABET_H

#include "Alphabet/SimpleAlphabet.h"

namespace cyrinx {

class EnglishAlphabet : public SimpleAlphabet {
public:
  EnglishAlphabet() : SimpleAlphabet('a', 'z') {}

  virtual ~EnglishAlphabet() {}
};

} // namespace cyrinx

#endif // CYRINX_ALPHABET_ENGLISH_ALPHABET_H