#include "cyrinx/Text/Splitter.h"

using namespace cyrinx;
using namespace std;

string Splitter::getIdentifierName(string &qualifiedName) {
  size_t pos = qualifiedName.find_last_of(':');
  if (pos == string::npos) {
    return string(qualifiedName);
  } else {
    size_t len = qualifiedName.length() - 1 - pos;
    return string(qualifiedName.data() + pos + 1, len);
  }
}

vector<string_view>& Splitter::splitIdentifier(string &id) {
  result.clear();
  bool isPrevUpper = false;
  size_t len = 0;
  for (size_t i = 0; i < id.length(); i++) {
    if (id[i] == '_') {
      if(len > 0) {
        insert(id.data() + i - len, len);
        len = 0;
      }
      isPrevUpper = false;
    } else if (isupper(id[i])) {
      if (!isPrevUpper && len > 0) {
        insert(id.data() + i - len, len);
        len = 1;
      } else {
        len++;
      }
      isPrevUpper = true;
    } else {
      if (isPrevUpper && len > 1) {
        insert(id.data() + i - len, len - 1);
        len = 2;
      } else {
        len++;
      }
      isPrevUpper = false;
    }
  }
  if (len > 0) {
    insert(id.data() + id.length() - len, len);
  }
  return result;
}

vector<string_view> &Splitter::splitComment(string &comment) {
  result.clear();
  // TODO
  return result;
}

void Splitter::insert(char *s, size_t len) {
  string_view view(s, len);
  result.push_back(view);
}
