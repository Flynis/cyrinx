#include "cyrinx/Searcher/SearchResult.h"

bool cyrinx::operator==(const SearchResult &l, const SearchResult &r) {
  return l.dictionaryIndex == r.dictionaryIndex && l.distance == r.distance;
}
