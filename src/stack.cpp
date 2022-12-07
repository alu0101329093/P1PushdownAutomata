#include "pdautomata/stack.h"

namespace cc {

Stack::Stack(const Symbol& initial_symbol) : symbols_stack_{{initial_symbol}} {}

Symbol Stack::Get() {
  Symbol symbol = symbols_stack_.top();
  symbols_stack_.pop();
  return symbol;
}

void Stack::Push(const std::vector<Symbol>& new_symbols) {
  for (std::size_t i = new_symbols.size(); i > 0; --i) {
    symbols_stack_.push(new_symbols[i - 1]);
  }
}

}  // namespace cc
