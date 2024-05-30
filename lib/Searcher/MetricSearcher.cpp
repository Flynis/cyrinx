#include "cyrinx/Searcher/MetricSearcher.h"

#include <iostream>

using namespace cyrinx;
using namespace std;

unordered_set<SearchResult>& MetricSearcher::search(string_view &word, unsigned maxDistance) {
  indexes.clear();
  vector<string>& dict = dictionary.getWords();
  for (size_t i = 0; i < dict.size(); i++) {
    string_view w(dict[i].c_str(), dict[i].length()); 
    unsigned d = metric.distance(word, w, maxDistance);
    if (d <= maxDistance) {
      indexes.insert({(int)i, d});
    }
  }
  return indexes;
}