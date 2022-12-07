#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_OUTPUT_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_OUTPUT_H_

#include <vector>

#include "pdautomata/state.h"
#include "pdautomata/symbol.h"

namespace cc {

class TransitionOutput {
 public:
  TransitionOutput(const State& state,
                   const std::vector<Symbol>& stack_symbols);

  inline const State& GetState() const { return state_; }
  inline void SetState(const State& state) { state_ = state; }

  inline const std::vector<Symbol>& GetStackSymbols() const {
    return stack_symbols_;
  }
  inline void SetStackSymbols(const std::vector<Symbol>& stack_symbols) {
    stack_symbols_ = stack_symbols;
  }

 private:
  State state_;
  std::vector<Symbol> stack_symbols_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_OUTPUT_H_
