#include "cyrinx/Typo/TypoContext.h"

#include "cyrinx/Alphabet/EnglishAlphabet.h"
#include "cyrinx/Searcher/DamerauLevensteinMetric.h"
#include "cyrinx/Searcher/MetricSearcher.h"

using namespace cyrinx;
using namespace std;

TypoContext::TypoContext(istream &dictStream, istream &namespacesStream) 
  : alphabet(new EnglishAlphabet()), 
    dict(dictStream),
    metric(new DamerauLevensteinMetric()),
    searcher(new MetricSearcher(*alphabet, dict, *metric)),
    filter(namespacesStream) {}

TypoContext::~TypoContext() {
  delete searcher;
  delete metric;
  delete alphabet;
}