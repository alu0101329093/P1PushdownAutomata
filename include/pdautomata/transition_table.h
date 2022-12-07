#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_TABLE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_TABLE_H_

#include <map>
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

  const std::vector<TransitionOutput>& GetTransition(
      const State& state, const Symbol& input_tape_symbol,
      const Symbol& stack_symbol);

  void SetTransition(const State& from_state, const Symbol& input_tape_symbol,
                     const Symbol& stack_symbol, const State& to_state,
                     const std::vector<Symbol>& symbols_to_stack);

 private:
  std::map<TransitionInput, SymbolTransition> symbol_transition_map_;
  std::map<TransitionInput, std::vector<TransitionOutput>>
      epsilon_transition_map_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_TABLE_H_
