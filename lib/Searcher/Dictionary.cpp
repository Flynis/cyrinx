#include "cyrinx/Searcher/Dictionary.h"

using namespace cyrinx;
using namespace std;

Dictionary::Dictionary(istream &input) {
  string word;
  while (input >> word) {
    words.push_back(word);
  }
}
