#include "pdautomata/pdautomata.h"

namespace cc {

bool PDAutomata::Execute(const std::string& input) const {
  State state{initial_state_};
  InputTape input_tape{input};
  Stack stack{initial_stack_symbol_};
  std::stack<ReturnCase> return_cases{};
  while (!(stack.IsEmpty() && return_cases.empty())) {
    Symbol stack_symbol{stack.Top()};
    std::vector<TransitionOutput> epsilon_transitions{
        transition_table_.GetEpsilonTransitions(state, stack_symbol)};
    for (auto transition : epsilon_transitions) {
      Stack return_stack{stack};
      return_stack.Pop();
      return_stack.Push(transition.GetStackSymbols());
      ReturnCase return_case{transition.GetState(), input_tape.GetPosition(),
                             return_stack};
      return_cases.push(return_case);
    }
    if (input_tape.IsEmpty() && !stack.IsEmpty() && !return_cases.empty()) {
      ReturnCase return_case{return_cases.top()};
      return_cases.pop();
      stack = return_case.GetStack();
      state.SetName(return_case.GetState().GetName());
      input_tape.SetPosition(return_case.GetInputTapePosition());
    } else {
      Symbol input_symbol{input_tape.Pop()};
      std::optional<TransitionOutput> transition{
          transition_table_.GetTransition(state, input_symbol, stack_symbol)};
      if (transition) {
        state.SetName(transition->GetState().GetName());
        stack.Pop();
        stack.Push(transition->GetStackSymbols());
      }
      if (stack.IsEmpty() && input_tape.IsEmpty()) return true;
    }
  }

  return false;
}

std::vector<State> PDAutomata::GetStates(std::istream& is) {
  std::string line;
  std::getline(is, line);
  std::stringstream input{line};
  State state;
  std::vector<State> states{};
  while (input >> state) {
    states.push_back(state);
  }

  return states;
}

std::vector<Symbol> PDAutomata::GetSymbols(std::istream& is) {
  std::string line;
  std::getline(is, line);
  std::stringstream input{line};
  Symbol symbol;
  std::vector<Symbol> symbols{};
  while (input >> symbol) {
    symbols.push_back(symbol);
  }

  return symbols;
}

}  // namespace cc
