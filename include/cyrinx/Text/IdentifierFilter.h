#ifndef CYRINX_TEXT_IDENTIFIER_FILTER_H
#define CYRINX_TEXT_IDENTIFIER_FILTER_H

#include <fstream>
#include <string>
#include <unordered_set>

namespace cyrinx {

class IdentifierFilter {

std::unordered_set<std::string> namespaces = { "std" };

std::unordered_set<std::string_view> namespacesViews;

std::unordered_set<std::string> tags = { 
  "tm",
  "lconv",
  "timespec",
  "sched_param",
  "timeval",
  "timex",
  "itimerspec",
  "sigevent",
  "pthread_attr_t",
  "random_data",
  "drand48_data",
  "obstack"
};

std::unordered_set<std::string> functions = { 
  "operator new",
  "operator new[]"
  "operator delete",
  "operator delete[]",
  "get_default_resource",
  "at_quick_exit"
};

public:
  static constexpr std::string_view stdguard = "__";

  IdentifierFilter(std::istream &input);
  
  bool isValidQualifiedName(std::string &name);

  bool isValidGlobalTag(std::string &tag);

  bool isValidFunctionName(std::string &name);

private:
  bool isValidName(std::string &name);
  bool isValidNamespace(std::string_view &name);
};

} // namespace cyrinx

#endif // CYRINX_TEXT_IDENTIFIER_FILTER_H