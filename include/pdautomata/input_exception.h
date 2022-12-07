#ifndef P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_EXCEPTION_H_
#define P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_EXCEPTION_H_

#include <exception>
#include <string>

namespace cc {

class InputException : public std::exception {
 public:
  InputException(const std::string& type, const std::string& name);
  const char* what() const noexcept override;

 private:
  std::string text_;
};

}  // namespace cc

#endif  // P1PUSHDOWNAUTOMATA_PDAUTOMATA_INPUT_EXCEPTION_H_
