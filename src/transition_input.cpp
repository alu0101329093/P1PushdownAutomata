#include "pdautomata/transition_input.h"

namespace cc {

TransitionInput::TransitionInput(const State& state, const Symbol& stack_symbol)
    : state_{state}, stack_symbol_{stack_symbol} {}

}  // namespace cc
