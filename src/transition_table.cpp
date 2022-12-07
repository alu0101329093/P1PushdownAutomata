#include "pdautomata/transition_table.h"

#include <string>

#include "transition_table.h"

namespace cc {

TransitionTable::TransitionTable()
    : symbol_transition_map_{}, epsilon_transition_map_{} {}

// TODO: Check error with reference
const std::vector<TransitionOutput>& TransitionTable::GetTransition(
    const State& state, const Symbol& input_tape_symbol,
    const Symbol& stack_symbol) {
  TransitionInput input{state, stack_symbol};
  std::vector<TransitionOutput> output{epsilon_transition_map_[input]};
  if (!input_tape_symbol.IsEmpty() &&
      symbol_transition_map_[input].count(input_tape_symbol)) {
    output.insert(output.begin(),
                  symbol_transition_map_[input][input_tape_symbol]);
  }

  return output;
}

void TransitionTable::SetTransition(
    const State& from_state, const Symbol& input_tape_symbol,
    const Symbol& stack_symbol, const State& to_state,
    const std::vector<Symbol>& symbols_to_stack) {
  TransitionInput input{from_state, stack_symbol};
  TransitionOutput output{to_state, symbols_to_stack};
  if (input_tape_symbol.IsEmpty()) {
    epsilon_transition_map_[input].push_back(output);
  } else {
    symbol_transition_map_[input][input_tape_symbol] = output;
  }
}
}  // namespace cc
