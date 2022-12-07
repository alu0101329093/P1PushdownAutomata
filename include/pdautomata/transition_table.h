#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_TABLE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_TABLE_H_

#include <istream>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "pdautomata/state.h"
#include "pdautomata/symbol.h"
#include "pdautomata/transition_input.h"
#include "pdautomata/transition_output.h"

namespace cc {

class TransitionTable {
 public:
  TransitionTable();
  using SymbolTransition = std::map<Symbol, TransitionOutput>;

  std::optional<TransitionOutput> GetTransition(
      const State& state, const Symbol& input_tape_symbol,
      const Symbol& stack_symbol) const;
  std::vector<TransitionOutput> GetEpsilonTransitions(
      const State& state, const Symbol& stack_symbol) const;

  void SetTransition(const State& from_state, const Symbol& input_tape_symbol,
                     const Symbol& stack_symbol, const State& to_state,
                     const std::vector<Symbol>& symbols_to_stack);

  friend std::istream& operator>>(std::istream& is, TransitionTable& table) {
    std::string line;
    std::istringstream input{};
    State from_state;
    Symbol input_tape_symbol;
    Symbol stack_symbol;
    State to_state;
    Symbol symbol_to_stack;
    std::vector<Symbol> symbols_to_stack{};
    while (std::getline(is, line)) {
      if (line.length() == 0) continue;
      // input.clear();
      // input.ignore();
      // input.str(line);
      std::stringstream input{line};
      input >> from_state;
      input >> input_tape_symbol;
      input >> stack_symbol;
      TransitionInput transition_input{from_state, stack_symbol};
      input >> to_state;
      symbols_to_stack.clear();
      while (input >> symbol_to_stack) {
        symbols_to_stack.push_back(symbol_to_stack);
      }
      TransitionOutput transition_output{to_state, symbols_to_stack};
      if (input_tape_symbol.IsEmpty()) {
        table.epsilon_transition_map_[transition_input].push_back(
            transition_output);
      } else {
        table.symbol_transition_map_[transition_input][input_tape_symbol] =
            transition_output;
      }
    }

    return is;
  }

 private:
  std::map<TransitionInput, SymbolTransition> symbol_transition_map_;
  std::map<TransitionInput, std::vector<TransitionOutput>>
      epsilon_transition_map_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_TABLE_H_
