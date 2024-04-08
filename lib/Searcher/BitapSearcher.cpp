#include "cyrinx/Searcher/BitapSearcher.h"

using namespace cyrinx;
using namespace std;

unordered_set<int>& BitapSearcher::search(string_view &word, int maxDistance) {
  this->maxDistance = maxDistance;
  indexes.clear();
  size_t len = word.length();
  endMask = 1 << len;
  for (size_t i = 0; i < len; i++) {
    wordMask[normalizeChar(word[i])] |= 1 << i;
  }
  vector<string>& dict = dictionary.getWords();
  for (size_t i = 0; i < dict.size(); i++) {
    string &w = dict[i]; 
    if(areClose(w.length(), len, maxDistance) && isSimilarWord(w)) {
      indexes.insert(i);
    }
  }
  return indexes;
}

int BitapSearcher::normalizeChar(char ch) {
  int val = alphabet.mapChar(ch);
  return (val < 0) ? alphabet.size() : val;
}

bool BitapSearcher::areClose(size_t len1, size_t len2, size_t eps) {
  return (len1 - len2 <= eps) || (len2 - len1 <= eps); 
}

bool BitapSearcher::isSimilarWord(string &word) {
  fill(tableRow.begin(), tableRow.end(), 1);
  for (size_t i = 0; i < word.length(); i++) {
    int charMask = wordMask[normalizeChar(word[i])];
    int oldTableCell = 0;
    int nextOldTableCell = 0;
    for (int d = 0; d <= maxDistance; d++) {
      int newSubstitutionTableCell = (oldTableCell | (tableRow[d] & charMask)) << 1;
      int newInsertionTableCell = oldTableCell | ((tableRow[d] & charMask) << 1);
      int newDeletionTableCell = (nextOldTableCell | (tableRow[d] & charMask)) << 1;
      int newTableCell = newSubstitutionTableCell | newInsertionTableCell | newDeletionTableCell | 1;
      oldTableCell = tableRow[d];
      tableRow[d] = newTableCell;
      nextOldTableCell = newTableCell;
    }
    if ((tableRow[maxDistance] & endMask) > 0) {
      return true;
    }
  }
  return false;
}