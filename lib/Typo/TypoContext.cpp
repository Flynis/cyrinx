#include "cyrinx/Typo/TypoContext.h"

#include "cyrinx/Alphabet/EnglishAlphabet.h"
#include "cyrinx/Searcher/BitapSearcher.h"

using namespace cyrinx;
using namespace std;

TypoContext::TypoContext(istream &dictStream, istream &namespacesStream) 
  : alphabet(new EnglishAlphabet()), 
    dict(dictStream),
    searcher(new BitapSearcher(*alphabet, dict)),
    filter(namespacesStream) {}

TypoContext::~TypoContext() {
  delete searcher;
  delete alphabet;
}