#ifndef CYRINX_TEXT_SPLITTER_H
#define CYRINX_TEXT_SPLITTER_H

#include <string>
#include <vector>

namespace cyrinx {

class Splitter {

std::vector<std::string_view> result;

public:
  Splitter() : result(1024) {}
  
  std::string getIdentifierName(std::string &qualifiedName);

  std::vector<std::string_view>& splitIdentifier(std::string &id);

  std::vector<std::string_view>& splitComment(std::string &comment);

private:
  void insert(char *s, std::size_t len);
};

} // namespace cyrinx

#endif // CYRINX_TEXT_SPLITTER_H