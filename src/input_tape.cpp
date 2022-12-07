#include "pdautomata/input_tape.h"

namespace cc {

InputTape::InputTape(std::string input_string) : symbols_tape_{}, position_{} {
  for (auto symbol : input_string) {
    if (symbol != ' ') {
      symbols_tape_.push_back(Symbol{symbol});
    }
  }
}

}  // namespace cc
