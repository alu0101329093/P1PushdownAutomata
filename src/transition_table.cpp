#include "pdautomata/transition_table.h"

namespace cc {

TransitionTable::TransitionTable()
    : symbol_transition_map_{}, epsilon_transition_map_{} {}

std::optional<TransitionOutput> TransitionTable::GetTransition(
    const State& state, const Symbol& input_tape_symbol,
    const Symbol& stack_symbol) const {
  TransitionInput input{state, stack_symbol};
  if (!input_tape_symbol.IsEmpty() && symbol_transition_map_.count(input) &&
      symbol_transition_map_.at(input).count(input_tape_symbol))
    return {symbol_transition_map_.at(input).at(input_tape_symbol)};

  return std::nullopt;
}

std::vector<TransitionOutput> TransitionTable::GetEpsilonTransitions(
    const State& state, const Symbol& stack_symbol) const {
  TransitionInput input{state, stack_symbol};
  if (epsilon_transition_map_.count(input))
    return epsilon_transition_map_.at(input);

  return {};
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
