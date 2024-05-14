#ifndef CYRINX_SEARCHER_DAMERAU_LEVENSTEIN_METRIC_H
#define CYRINX_SEARCHER_DAMERAU_LEVENSTEIN_METRIC_H

#include <vector>

#include "cyrinx/Searcher/Metric.h"

namespace cyrinx {

class DamerauLevensteinMetric : public Metric {

static constexpr size_t maxWordLength = 32;

std::vector<int> currentRow;

std::vector<int> previousRow;

std::vector<int> transpositionRow;

public:
  DamerauLevensteinMetric() 
    : currentRow(maxWordLength + 1), 
      previousRow(maxWordLength + 1), 
      transpositionRow(maxWordLength + 1) {}
  
  unsigned distance(std::string_view l, std::string_view r, int maxDistance) override;

};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_DAMERAU_LEVENSTEIN_METRIC_H