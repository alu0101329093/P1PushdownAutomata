#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_

#include <cstddef>
#include <string>
#include <vector>

#include "pdautomata/symbol.h"

namespace cc {

class InputTape {
 public:
  InputTape(std::string input_string);

  inline const Symbol& Pop() const { return symbols_tape_[position_++]; }

  inline std::size_t GetPosition() const { return position_; }
  inline void SetPosition(std::size_t position) { position_ = position; }

  inline bool IsEmpty() const { return symbols_tape_.size() == 0; }

 private:
  std::vector<Symbol> symbols_tape_;
  std::size_t position_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_