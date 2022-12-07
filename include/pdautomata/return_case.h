#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_RETURN_CASE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_RETURN_CASE_H_

#include <cstddef>

#include "pdautomata/stack.h"
#include "pdautomata/state.h"

namespace cc {

class ReturnCase {
 public:
  ReturnCase(const State& state, std::size_t input_tape_position,
             const Stack& stack);

  inline const State& GetState() const { return state_; }
  inline void SetState(const State& state) { state_ = state; }

  inline std::size_t GetInputTapePosition() { return input_tape_position_; }
  inline void SetInputTapePosition(std::size_t position) {
    input_tape_position_ = position;
  }

  inline const Stack& GetStack() const { return stack_; }
  inline void SetStack(const Stack& stack) { stack_ = stack; }

 private:
  State state_;
  std::size_t input_tape_position_;
  Stack stack_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_RETURN_CASE_H_
