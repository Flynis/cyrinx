#ifndef CYRINX_SEARCHER_METRIC_H
#define CYRINX_SEARCHER_METRIC_H

#include <string>

namespace cyrinx {

class Metric {
public:

  virtual unsigned distance(std::string_view l, std::string_view r, int maxDistance) = 0;
  
  virtual ~Metric() {}
  
};

} // namespace cyrinx

#endif // CYRINX_SEARCHER_METRIC_H