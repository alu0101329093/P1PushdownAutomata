#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_PDAUTOMATA_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_PDAUTOMATA_H_

#include <algorithm>
#include <cstddef>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

#include "pdautomata/input_exception.h"
#include "pdautomata/input_tape.h"
#include "pdautomata/return_case.h"
#include "pdautomata/stack.h"
#include "pdautomata/state.h"
#include "pdautomata/symbol.h"
#include "pdautomata/transition_table.h"

namespace cc {

class PDAutomata {
 public:
  bool Execute(const std::string& input) const;

  friend std::istream& operator>>(std::istream& is, PDAutomata& automata) {
    automata.states_ = PDAutomata::GetStates(is);
    automata.input_tape_symbols_ = PDAutomata::GetSymbols(is);
    automata.stack_symbols_ = PDAutomata::GetSymbols(is);
    is >> automata.initial_state_;
    if (std::find(automata.states_.begin(), automata.states_.end(),
                  automata.initial_state_) == automata.states_.end())
      throw InputException{"State", automata.initial_state_.GetName()};
    is >> automata.initial_stack_symbol_;
    if (std::find(
            automata.stack_symbols_.begin(), automata.stack_symbols_.end(),
            automata.initial_stack_symbol_) == automata.stack_symbols_.end())
      throw InputException{"Symbol", {automata.initial_stack_symbol_.Get()}};
    automata.transition_table_ = automata.GetTransitionTable(is);

    return is;
  }

 private:
  static std::vector<State> GetStates(std::istream& is);
  static std::vector<Symbol> GetSymbols(std::istream& is);
  TransitionTable GetTransitionTable(std::istream& is);

  std::vector<State> states_;
  std::vector<Symbol> input_tape_symbols_;
  std::vector<Symbol> stack_symbols_;
  State initial_state_;
  Symbol initial_stack_symbol_;
  TransitionTable transition_table_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_PDAUTOMATA_H_
