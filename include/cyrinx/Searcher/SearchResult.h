#ifndef CYRINX_SEARCHER_SEARCH_RESULT_H
#define CYRINX_SEARCHER_SEARCH_RESULT_H

#include <cstddef>
#include <unordered_set>

namespace cyrinx {

struct SearchResult {
  int dictionaryIndex;
  unsigned distance;
};

bool operator==(const SearchResult &l, const SearchResult &r);

} // namespace cyrinx

namespace std {
  template<> struct hash<cyrinx::SearchResult> {
    size_t operator()(const cyrinx::SearchResult& s) const noexcept {
      return hash<int>{}(s.dictionaryIndex);
    }
  };
}

#endif // CYRINX_SEARCHER_SEARCH_RESULT_H