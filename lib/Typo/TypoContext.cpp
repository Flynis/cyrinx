#include "TypoContext.h"

#include <fstream>

using namespace std;
using namespace cyrinx;

TypoContext::TypoContext(
      string &dictPath,
      string &excludedNamespacesPath) 
  : dict(dictPath);
{
  ifstream in(excludedNamespacesPath);
  string nspace;
  while (in >> nspace) {
    exclNamespaces.insert(nspace);
    string_view view(nspace.data(), nspace.length());
    exclNamespacesViews.insert(view);
  }
}
