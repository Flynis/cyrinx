#include "cyrinx/Text/IdentifierFilter.h"

using namespace cyrinx;
using namespace std;

IdentifierFilter::IdentifierFilter(istream &input) {
  string nspace;
  while (input >> nspace) {
    insertStr(nspace, namespaces, namespacesViews);
  }
  insertStr(string("std"), namespaces, namespacesViews);
  for (const string &nspace : namespaces) {
    insertStr(nspace, identifiers, identifiersViews);
  }
}

bool IdentifierFilter::isValidIdentifier(string &id) {
  bool hasNameSpace = false;
  int i = id.length() - 1;
  while (i >= 0 && isalpha(id[i])) {
    if (id[i] == ':') {
      hasNameSpace = true;
      break;
    }
    i--;
  }
  if (!hasNameSpace) {
    return !containedIn(id, identifiers); // id[0] == '_' || 
  }
  i -= 2;
  size_t len = 0;
  while(i >= 0) {
    if (id[i] == ':') {
      string_view view(id.data() + i + 1, len);
      if (containedIn(view, namespacesViews)) {
        return false;
      }
      len = 0;
      i -= 2;
      continue;
    }
    len++;
    i--;
  }
  if(len != 0) {
    string_view view(id.data(), len);
    if (containedIn(view, namespacesViews)) {
      return false;
    }
  }
  return true;
}

void IdentifierFilter::insertStr(string &s, 
                                unordered_set<string> &strings, 
                                unordered_set<string_view> &views)
{
  strings.insert(s);
  string_view view(s.data(), s.length());
  views.insert(view);
}