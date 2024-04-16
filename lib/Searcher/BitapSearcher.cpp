#include "cyrinx/Searcher/BitapSearcher.h"

#include <iostream>

using namespace cyrinx;
using namespace std;

unordered_set<int>& BitapSearcher::search(string_view &word, unsigned maxDistance) {
  this->maxDistance = maxDistance;
  indexes.clear();
  size_t len = word.length();
  endMask = 1 << len;
  fill(wordMask.begin(), wordMask.end(), 0);
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

unsigned BitapSearcher::normalizeChar(char ch) {
  int val = alphabet.mapChar(ch);
  return (val < 0) ? alphabet.size() : val;
}

bool BitapSearcher::areClose(size_t len1, size_t len2, size_t eps) {
  return (len1 - len2 <= eps) || (len2 - len1 <= eps); 
}

bool BitapSearcher::isSimilarWord(string &word) {
  fill(tableRow.begin(), tableRow.end(), 1);
  for (size_t i = 0; i < word.length(); i++) {
    unsigned normalized = normalizeChar(word[i]);
    unsigned charMask = wordMask[normalized];
    //printf("%c norm=%u mask=%u\n", word[i], normalized, charMask);
    unsigned oldTableCell = 0;
    unsigned nextOldTableCell = 0;
    for (unsigned d = 0; d <= maxDistance; d++) {
      unsigned newSubstitutionTableCell = (oldTableCell | (tableRow[d] & charMask)) << 1;
      unsigned newInsertionTableCell = oldTableCell | ((tableRow[d] & charMask) << 1);
      unsigned newDeletionTableCell = (nextOldTableCell | (tableRow[d] & charMask)) << 1;
      //printf("%u %u %u\n", newSubstitutionTableCell, newInsertionTableCell, newDeletionTableCell);
      unsigned newTableCell = newSubstitutionTableCell | newInsertionTableCell | newDeletionTableCell | 1;
      oldTableCell = tableRow[d];
      tableRow[d] = newTableCell;
      nextOldTableCell = newTableCell;
    }
  }
  //printf("row=%0*b\n", 10, tableRow[maxDistance]);
  if ((tableRow[maxDistance] & endMask) > 0) {
    return true;
  }
  return false;
}