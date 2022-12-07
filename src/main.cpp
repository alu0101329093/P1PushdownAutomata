#include "main.h"

int main(int argc, char* argv[]) {
  std::ifstream input_file{"./examples/Apv.txt"};
  // std::ifstream input_file{"./examples/Apv-2.txt"};
  // std::ifstream input_file{"./examples/Apv-3.txt"};
  cc::PDAutomata automata;
  std::stringstream input{EliminateComments(input_file)};
  input >> automata;
  std::cout << "Readed automata" << std::endl;
  std::cout << "aabb: " << (automata.Execute("aabb") ? "Success" : "Fail")
            << std::endl;
  std::cout << "aab: " << (automata.Execute("aab") ? "Success" : "Fail")
            << std::endl;
  std::cout << "aabab: " << (automata.Execute("aab") ? "Success" : "Fail")
            << std::endl;
  std::cout << "bbaa: " << (automata.Execute("aab") ? "Success" : "Fail")
            << std::endl;
  std::cout << ": " << (automata.Execute("") ? "Success" : "Fail") << std::endl;
  // std::cout << "0011: " << (automata.Execute("0011") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "001: " << (automata.Execute("001") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "011: " << (automata.Execute("001") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "00111: " << (automata.Execute("001") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "1100: " << (automata.Execute("1100") ? "Success" : "Fail")
  //           << std::endl;

  return EXIT_SUCCESS;
}

std::string EliminateComments(std::ifstream& file) {
  std::string no_comments_file{};
  std::string line;
  while (std::getline(file, line)) {
    if (line[0] == '#') continue;
    no_comments_file += line + "\n";
  }

  return no_comments_file;
}
