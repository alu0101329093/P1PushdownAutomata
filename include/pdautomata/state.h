#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_STATE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_STATE_H_

#include <string>

namespace cc {

class State {
 public:
  State(const std::string& name);

  friend bool operator==(const State& first_state, const State& second_state) {
    return first_state.name_ == second_state.name_;
  }
  friend bool operator!=(const State& first_state, const State& second_state) {
    return first_state.name_ != second_state.name_;
  }
  friend bool operator<(const State& first_state, const State& second_state) {
    return first_state.name_ < second_state.name_;
  }
  friend bool operator>(const State& first_state, const State& second_state) {
    return first_state.name_ > second_state.name_;
  }

 private:
  std::string name_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_STATE_H_