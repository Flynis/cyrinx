#include "cyrinx/Text/IdentifierFilter.h"

#include "cyrinx/Text/Support.h"

using namespace cyrinx;
using namespace std;

IdentifierFilter::IdentifierFilter(istream &input) {
  for(const string &s : namespaces) {
    string_view view(s.data(), s.length());
    namespacesViews.insert(view);
  }
  string nspace;
  while (input >> nspace) {
    namespaces.insert(nspace);
    string_view view(nspace.data(), nspace.length());
    namespacesViews.insert(view);
  }
}

bool IdentifierFilter::isValidQualifiedName(string &name) {
  int i = name.length() - 1;
  while (i >= 0 && name[i] != ':') {
    i--;
  }
  bool hasNameSpace = (i >= 0 && name[i] == ':');
  if (!hasNameSpace) {
    return isValidName(name); 
  }
  i -= 2;
  size_t len = 0;
  while (i >= 0) {
    if (name[i] == ':') {
      string_view view(name.data() + i + 1, len);
      if (!isValidNamespace(view)) {
        return false;
      }
      len = 0;
      i -= 2;
      continue;
    }
    len++;
    i--;
  }
  if (len > 0) {
    string_view view(name.data(), len);
    if (!isValidNamespace(view)) {
      return false;
    }
  }
  return true;
}

bool IdentifierFilter::isValidGlobalTag(string &tag) {
  if (tag[0] == '_' || StrStartsWith(tag, stdguard)) {
    return false;
  }
  if (StrContainsChar(tag, ':')) {
    return isValidQualifiedName(tag);
  } else {
    return !SetContainsKey(tags, tag);
  }
}

bool IdentifierFilter::isValidFunctionName(string &name) {
  if (StrStartsWith(name, stdguard)) {
    return false;
  }
  if (StrContainsChar(name, ':')) {
    return isValidQualifiedName(name);
  } else {
    return !SetContainsKey(functions, name);
  }
}

bool IdentifierFilter::isValidName(string &name) {
  return !StrStartsWith(name, stdguard) && !SetContainsKey(namespaces, name);
}

bool IdentifierFilter::isValidNamespace(string_view &name) {
  return !StrStartsWith(name, stdguard) && !SetContainsKey(namespacesViews, name);
}
