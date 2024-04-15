#include "cyrinx/Text/Support.h"

using namespace std;

bool cyrinx::StrStartsWith(const string &s, const string_view &prefix) {
  size_t len = 0;
  for(size_t i = 0; i < s.length() && i < prefix.length(); i++) {
    if(prefix[i] != s[i]) {
      return false;
    }
    len++;
  }
  return len == prefix.length();
}

bool cyrinx::StrStartsWith(const string_view &s, const string_view &prefix) {
  size_t len = 0;
  for(size_t i = 0; i < s.length() && i < prefix.length(); i++) {
    if(prefix[i] != s[i]) {
      return false;
    }
    len++;
  }
  return len == prefix.length();
}

bool cyrinx::StrContainsChar(const string &s, char ch) {
  return s.find_last_of(ch) != string::npos;
}
