#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_

#include <queue>
#include <string>

#include "pdautomata/symbol.h"

namespace cc {

class InputTape {
 public:
  InputTape(std::string input_string);

  inline void Pop() { symbols_tape_.pop(); }
  inline const Symbol& Front() const { return symbols_tape_.front(); }

  inline bool IsEmpty() const { return symbols_tape_.size() == 0; }

 private:
  std::queue<Symbol> symbols_tape_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_TAPE_H_