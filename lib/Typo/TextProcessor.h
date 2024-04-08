#ifndef CYRINX_TYPO_TEXT_PROCESSOR_H
#define CYRINX_TYPO_TEXT_PROCESSOR_H

#include <unordered_set>
#include <vector>

namespace cyrinx {

class TextProcessor {

std::unordered_set<std::string_view> exclNamespacesViews;

std::vector<std::string_view> result;

public:
  TextProcessor(std::unordered_set<std::string_view>& exclNamespacesViews);
  
  std::vector<std::string_view>& processName(std::string name);
};

} // namespace cyrinx

#endif // CYRINX_TYPO_TEXT_PROCESSOR_H