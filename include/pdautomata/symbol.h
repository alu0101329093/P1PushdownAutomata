#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_SYMBOL_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_SYMBOL_H_

namespace cc {

class Symbol {
 public:
  static const char kEmptySymbol = '.';

  Symbol(char symbol);

  inline char GetSymbol() const { return symbol_; }
  inline void SetSymbol(char new_symbol) { symbol_ = new_symbol; }

  inline bool IsEmpty() { return symbol_ == kEmptySymbol; }

 private:
  char symbol_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_SYMBOL_H_