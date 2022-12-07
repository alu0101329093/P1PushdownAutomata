#include "pdautomata/stack.h"

namespace cc {

Stack::Stack(const Symbol& initial_symbol) : symbols_stack_{{initial_symbol}} {}

void Stack::Push(const std::vector<Symbol>& new_symbols) {
  for (std::size_t i = new_symbols.size(); i > 0; --i) {
    if (!new_symbols[i - 1].IsEmpty()) symbols_stack_.push(new_symbols[i - 1]);
  }
}

}  // namespace cc
