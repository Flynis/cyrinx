#ifndef CYRINX_TEXT_SUPPORT_H
#define CYRINX_TEXT_SUPPORT_H

#include <string>
#include <unordered_set>

namespace cyrinx {

template <typename Key>
bool SetContainsKey(const std::unordered_set<Key> set, const Key key) {
  return set.find(key) != set.end();
}

bool StrStartsWith(const std::string &s, const std::string_view &prefix);

bool StrStartsWith(const std::string_view &s, const std::string_view &prefix);

bool StrContainsChar(const std::string &s, char ch);

} // namespace cyrinx

#endif // CYRINX_TEXT_SUPPORT_H