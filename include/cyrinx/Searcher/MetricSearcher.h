#ifndef CYRINX_SEARCHER_METRIC_SEARCHER_H
#define CYRINX_SEARCHER_METRIC_SEARCHER_H

#include "cyrinx/Searcher/Searcher.h"
#include "cyrinx/Searcher/Metric.h"

namespace cyrinx {

class MetricSearcher : public Searcher {

Metric &metric;

public:
  MetricSearcher(Alphabet &alphabet, Dictionary &dictionary, Metric &metric) 
    : Searcher(alphabet, dictionary), metric(metric) {}
  
  std::unordered_set<SearchResult>& search(std::string_view &word, unsigned maxDistance) override;

};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_METRIC_SEARCHER_H