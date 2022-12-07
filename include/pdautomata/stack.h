#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_STACK_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_STACK_H_

#include <cstddef>
#include <ranges>
#include <stack>
#include <vector>

#include "pdautomata/symbol.h"

namespace cc {

class Stack {
 public:
  Stack(const Symbol& initial_symbol);

  inline void Pop() { symbols_stack_.pop(); }
  inline Symbol Top() { return symbols_stack_.top(); }

  void Push(const std::vector<Symbol>& new_symbols);

  inline bool IsEmpty() const { return symbols_stack_.empty(); }

 private:
  std::stack<Symbol> symbols_stack_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_STACK_H_
