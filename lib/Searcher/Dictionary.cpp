#include "Searcher/Dictionary.h"

#include <fstream>

using namespace std;

cyrinx::Dictionary::Dictionary(string filename) {
  ifstream in(filename);
  string word;
  while(in >> word) {
    words.push_back(word);
  }
}
