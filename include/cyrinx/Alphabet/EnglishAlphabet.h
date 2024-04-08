#ifndef CYRINX_ALPHABET_ENGLISH_ALPHABET_H
#define CYRINX_ALPHABET_ENGLISH_ALPHABET_H

#include "cyrinx/Alphabet/SimpleAlphabet.h"

namespace cyrinx {

class EnglishAlphabet : public SimpleAlphabet {
public:
  EnglishAlphabet() : SimpleAlphabet('a', 'z') {}
};

} // namespace cyrinx

#endif // CYRINX_ALPHABET_ENGLISH_ALPHABET_H