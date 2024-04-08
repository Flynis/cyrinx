#ifndef CYRINX_TEXT_IDENTIFIER_FILTER_H
#define CYRINX_TEXT_IDENTIFIER_FILTER_H

#include <fstream>
#include <string>
#include <unordered_set>

namespace cyrinx {

class IdentifierFilter {

std::unordered_set<std::string> namespaces;

std::unordered_set<std::string> identifiers;

std::unordered_set<std::string_view> namespacesViews;

std::unordered_set<std::string_view> identifiersViews;

public:
  IdentifierFilter(std::istream &input);
  
  bool isValidIdentifier(std::string &id);
  
private:
  void insertStr(std::string &s, 
                std::unordered_set<std::string> &strings, 
                std::unordered_set<std::string_view> &views);

  template <typename Key>
  bool containedIn(Key key, std::unordered_set<Key> set) {
    return uset.find(key) != set.end();
  }
};

} // namespace cyrinx

#endif // CYRINX_TEXT_IDENTIFIER_FILTER_H