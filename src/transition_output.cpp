#include "pdautomata/transition_output.h"

namespace cc {

TransitionOutput::TransitionOutput(const State& state,
                                   const std::vector<Symbol>& symbols_to_stack)
    : state_{state}, stack_symbols_{symbols_to_stack} {}

}  // namespace cc
