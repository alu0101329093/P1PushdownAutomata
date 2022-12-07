#include "pdautomata/pdautomata.h"

#include "pdautomata.h"

namespace cc {

bool PDAutomata::Execute(const std::string& input) const {
  State state{initial_state_};
  InputTape input_tape{input};
  Stack stack{initial_stack_symbol_};
  std::stack<ReturnCase> return_cases{};
  while (!(stack.IsEmpty() && return_cases.empty())) {
    if (stack.IsEmpty()) {
      ReturnCase return_case{return_cases.top()};
      return_cases.pop();
      stack = return_case.GetStack();
      state.SetName(return_case.GetState().GetName());
      input_tape.SetPosition(return_case.GetInputTapePosition());
    }
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

    if (input_tape.IsEmpty()) {
      if (stack.IsEmpty()) {
        return true;
      }
      if (!return_cases.empty()) {
        ReturnCase return_case{return_cases.top()};
        return_cases.pop();
        stack = return_case.GetStack();
        state.SetName(return_case.GetState().GetName());
        input_tape.SetPosition(return_case.GetInputTapePosition());
        if (input_tape.IsEmpty() && stack.IsEmpty()) return true;
      } else {
        return false;
      }
    } else {
      Symbol input_symbol{input_tape.Pop()};
      std::optional<TransitionOutput> transition{
          transition_table_.GetTransition(state, input_symbol, stack_symbol)};
      if (transition) {
        state.SetName(transition->GetState().GetName());
        stack.Pop();
        stack.Push(transition->GetStackSymbols());
      } else if (!return_cases.empty()) {
        ReturnCase return_case{return_cases.top()};
        return_cases.pop();
        stack = return_case.GetStack();
        state.SetName(return_case.GetState().GetName());
        input_tape.SetPosition(return_case.GetInputTapePosition());
      }
      if (input_tape.IsEmpty() && stack.IsEmpty()) return true;
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

TransitionTable PDAutomata::GetTransitionTable(std::istream& is) {
  TransitionTable table{};
  std::string line;
  std::istringstream input{};
  State from_state;
  Symbol input_tape_symbol;
  Symbol stack_symbol;
  State to_state;
  Symbol symbol_to_stack;
  std::vector<Symbol> symbols_to_stack{};
  while (std::getline(is, line)) {
    if (line.length() == 0) continue;
    std::stringstream input{line};
    input >> from_state;
    if (std::find(states_.begin(), states_.end(), from_state) == states_.end())
      throw InputException{"State", from_state.GetName()};
    input >> input_tape_symbol;
    if (!input_tape_symbol.IsEmpty() &&
        std::find(input_tape_symbols_.begin(), input_tape_symbols_.end(),
                  input_tape_symbol) == input_tape_symbols_.end())
      throw InputException{"Symbol", {input_tape_symbol.Get()}};
    input >> stack_symbol;
    if (std::find(stack_symbols_.begin(), stack_symbols_.end(), stack_symbol) ==
        stack_symbols_.end())
      throw InputException{"Symbol", {stack_symbol.Get()}};
    TransitionInput transition_input{from_state, stack_symbol};
    input >> to_state;
    if (std::find(states_.begin(), states_.end(), to_state) == states_.end())
      throw InputException{"State", to_state.GetName()};
    symbols_to_stack.clear();
    while (input >> symbol_to_stack) {
      symbols_to_stack.push_back(symbol_to_stack);
    }
    TransitionOutput transition_output{to_state, symbols_to_stack};
    table.SetTransition(from_state, input_tape_symbol, stack_symbol, to_state,
                        symbols_to_stack);
  }
  return table;
}
}  // namespace cc
