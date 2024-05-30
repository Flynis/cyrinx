#include "cyrinx/Searcher/DamerauLevensteinMetric.h"

using namespace cyrinx;
using namespace std;

unsigned DamerauLevensteinMetric::distance(string_view l, string_view r, int maxDistance) {
  int llen = l.length();
  int rlen = r.length();

  if (llen == 0) {
    return rlen;
  } else if (rlen == 0) {
    return llen;
  }

  if (llen > rlen) {
    string_view tmp = l;
    l = r;
    r = tmp;
    llen = rlen;
    rlen = r.length();
  }

  if (maxDistance < 0) {
    maxDistance = rlen;
  }
  if (rlen - llen > maxDistance) {
    return maxDistance + 1;
  }

  for(size_t i = 0; i < currentRow.size(); i++) {
    currentRow[i] = 0;
    previousRow[i] = 0;
    transpositionRow[i] = 0;
  }

  for (int i = 0; i <= llen; i++) {
    previousRow[i] = i;
  }

  char lastSecondCh = 0;
  for (int i = 1; i <= rlen; i++) {
    char secondCh = r[i - 1];
    currentRow[0] = i;
    // Вычисляем только диагональную полосу шириной 2 * (max + 1)
    int from = max(i - maxDistance - 1, 1);
    int to = min(i + maxDistance + 1, llen);

    char lastFirstCh = 0;
    for (int j = from; j <= to; j++) {
      char firstCh = l[j - 1];

      // Вычисляем минимальную цену перехода в текущее состояние из предыдущих среди удаления, вставки и
      // замены соответственно.
      int cost = (firstCh == secondCh) ? 0 : 1;
      int value = min(min(currentRow[j - 1] + 1, previousRow[j] + 1), previousRow[j - 1] + cost);

      // Если вдруг была транспозиция, надо также учесть и её стоимость.
      if (firstCh == lastSecondCh && secondCh == lastFirstCh) {
        value = min(value, transpositionRow[j - 2] + cost);
      }

      currentRow[j] = value;
      lastFirstCh = firstCh;
    }
    lastSecondCh = secondCh;

    vector<int> tempRow = move(transpositionRow);
    transpositionRow = move(previousRow);
    previousRow = move(currentRow);
    currentRow = move(tempRow);
  }
  return (unsigned)previousRow[llen];
}
