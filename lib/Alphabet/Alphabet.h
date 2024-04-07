#ifndef CYRINX_ALPHABET_ALPHABET_H
#define CYRINX_ALPHABET_ALPHABET_H

namespace cyrinx {

class Alphabet {
public:
  /**
   * Maps the character ch from the alphabet to an int 
   * in the range 0 to size() - 1.
   * @returns mapped char or -1 if ch is not from the alphabet.
  */
  virtual int mapChar(char ch) = 0;

  /**
   * Returns the size of the alphabet.
   * @returns the size of the alphabet.
  */
  virtual int size() = 0;

  virtual ~Alphabet() {}
};

} // namespace cyrinx

#endif // CYRINX_ALPHABET_ALPHABET_H