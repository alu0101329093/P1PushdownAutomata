#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_STATE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_STATE_H_

#include <istream>
#include <string>

namespace cc {

class State {
 public:
  // TODO: Eliminate default
  State(const std::string& name = "");

  inline const std::string& GetName() const { return name_; }
  inline void SetName(const std::string& name) { name_ = name; }

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

  friend std::istream& operator>>(std::istream& is, State& state) {
    std::string name{};
    is >> name;
    state.name_ = name;
    return is;
  }

 private:
  std::string name_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_STATE_H_
