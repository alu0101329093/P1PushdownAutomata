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
    std::vector<State> states{PDAutomata::GetStates(is)};
    automata.input_tape_symbols_ = PDAutomata::GetSymbols(is);
    // std::vector<Symbol> input_tape_symbol{};
    std::vector<Symbol> stack_symbol{PDAutomata::GetSymbols(is)};
    is >> automata.initial_state_;
    if (std::find(states.begin(), states.end(), automata.initial_state_) ==
        states.end())
      throw InputException{"State", automata.initial_state_.GetName()};
    is >> automata.initial_stack_symbol_;
    if (std::find(stack_symbol.begin(), stack_symbol.end(),
                  automata.initial_stack_symbol_) == stack_symbol.end())
      throw InputException{"Symbol",
                               {automata.initial_stack_symbol_.Get()}};
    is >> automata.transition_table_;

    return is;
  }

 private:
  static std::vector<State> GetStates(std::istream& is);
  static std::vector<Symbol> GetSymbols(std::istream& is);

  State initial_state_;
  std::vector<Symbol> input_tape_symbols_;
  Symbol initial_stack_symbol_;
  TransitionTable transition_table_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_PDAUTOMATA_H_
