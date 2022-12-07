#include "main.h"

int main(int argc, char* argv[]) {
  try {
    return ProtectedMain(argc, argv);
  } catch (const cc::InputException& error) {
    std::cerr << argv[0] << ": " << error.what() << "\n";
    return 1;
  } catch (...) {
    std::cerr << argv[0] << ": Unknown error\n";
    return 99;
  }
}

int ProtectedMain(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << ": Insufficient params.\n";
    std::cout << "Example: " << argv[0] << " file.txt";
    return EXIT_SUCCESS;
  }

  // std::ifstream input_file{"./examples/Apv.txt"};
  std::ifstream input_file{argv[1]};
  // std::ifstream input_file{"./examples/Apv-3.txt"};
  cc::PDAutomata automata;
  std::stringstream input{EliminateComments(input_file)};
  input >> automata;
  std::cout << "Input string to evaluate: ";
  std::string input_string;
  std::cin >> input_string;
  std::cout << input_string << ": "
            << (automata.Execute(input_string) ? "Success" : "Fail")
            << std::endl;
  // // std::cout << "aab: " << (automata.Execute("aab") ? "Success" : "Fail")
  // //           << std::endl;
  // // std::cout << "aabab: " << (automata.Execute("aab") ? "Success" : "Fail")
  // //           << std::endl;
  // // std::cout << "bbaa: " << (automata.Execute("aab") ? "Success" : "Fail")
  // //           << std::endl;
  // // std::cout << ": " << (automata.Execute("") ? "Success" : "Fail") <<
  // // std::endl;
  // std::cout << "0110: " << (automata.Execute("0110") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "001: " << (automata.Execute("001") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "011: " << (automata.Execute("001") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "1111: " << (automata.Execute("1111") ? "Success" : "Fail")
  //           << std::endl;
  // std::cout << "1001: " << (automata.Execute("1001") ? "Success" : "Fail")
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
