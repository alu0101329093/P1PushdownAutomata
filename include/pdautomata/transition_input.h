#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_INPUT_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_INPUT_H_

#include "pdautomata/state.h"
#include "pdautomata/symbol.h"

namespace cc {

class TransitionInput {
 public:
  TransitionInput(const State& state, const Symbol& stack_symbol);

  friend bool operator==(const TransitionInput& first_input,
                         const TransitionInput& second_input) {
    return first_input.state_ == second_input.state_ &&
           first_input.stack_symbol_ == second_input.stack_symbol_;
  }
  friend bool operator!=(const TransitionInput& first_input,
                         const TransitionInput& second_input) {
    return first_input.state_ != second_input.state_ ||
           first_input.stack_symbol_ != second_input.stack_symbol_;
  }
  friend bool operator<(const TransitionInput& first_input,
                        const TransitionInput& second_input) {
    return first_input.state_ < second_input.state_ ||
           (first_input.state_ == second_input.state_ &&
            first_input.stack_symbol_ < second_input.stack_symbol_);
  }

 private:
  State state_;
  Symbol stack_symbol_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_TRANSITION_INPUT_H_
