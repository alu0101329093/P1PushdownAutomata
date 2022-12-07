#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_PDAUTOMATA_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_PDAUTOMATA_H_

#include <cstddef>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

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
    std::vector<Symbol> input_tape_symbol{PDAutomata::GetSymbols(is)};
    std::vector<Symbol> stack_symbol{PDAutomata::GetSymbols(is)};
    is >> automata.initial_state_;
    is >> automata.initial_stack_symbol_;
    is >> automata.transition_table_;

    return is;
  }

 private:
  static std::vector<State> GetStates(std::istream& is);
  static std::vector<Symbol> GetSymbols(std::istream& is);

  State initial_state_;
  Symbol initial_stack_symbol_;
  TransitionTable transition_table_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_PDAUTOMATA_H_
