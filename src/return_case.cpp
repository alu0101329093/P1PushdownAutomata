#include "pdautomata/return_case.h"

namespace cc {

ReturnCase::ReturnCase(const State& state, std::size_t input_tape_position,
                       const Stack& stack)
    : state_{state}, input_tape_position_{input_tape_position}, stack_{stack} {}

}  // namespace cc
