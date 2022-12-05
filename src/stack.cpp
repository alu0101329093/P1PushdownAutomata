#include "stack.h"

namespace cc {

Stack::Stack(const Symbol& initial_symbol) : symbols_stack_{{initial_symbol}} {}

Symbol Stack::Get() {
  Symbol symbol = symbols_stack_.top();
  symbols_stack_.pop();
  return symbol;
}

void Stack::Push(const std::vector<Symbol>& new_symbols) {
  for (auto symbol : new_symbols | std::views::reverse) {
    symbols_stack_.push(symbol);
  }
}

}  // namespace cc
