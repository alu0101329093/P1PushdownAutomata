#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_SYMBOL_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_SYMBOL_H_

namespace cc {

class Symbol {
 public:
  static const char kEmptySymbol = '.';

  Symbol(char symbol);

  inline char Get() const { return symbol_; }
  inline void Set(char new_symbol) { symbol_ = new_symbol; }

  inline bool IsEmpty() { return symbol_ == kEmptySymbol; }

  friend bool operator==(const Symbol& first_symbol,
                         const Symbol& second_symbol) {
    return first_symbol.symbol_ == second_symbol.symbol_ ||
           first_symbol == kEmptySymbol || second_symbol == kEmptySymbol;
  }
  friend bool operator!=(const Symbol& first_symbol,
                         const Symbol& second_symbol) {
    return first_symbol.symbol_ != second_symbol.symbol_ &&
           first_symbol != kEmptySymbol && second_symbol != kEmptySymbol;
  }

 private:
  char symbol_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_SYMBOL_H_