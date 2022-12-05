#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_

#include <ranges>
#include <stack>
#include <vector>

#include "pdautomata/symbol.h"

namespace cc {

class Stack {
 public:
  Stack(const Symbol& initial_symbol);

  Symbol Get();
  void Push(const std::vector<Symbol>& new_symbols);

 private:
  std::stack<Symbol> symbols_stack_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_