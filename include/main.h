#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "pdautomata/input_exception.h"
#include "pdautomata/pdautomata.h"

int main(int argc, char* argv[]);

int ProtectedMain(int argc, char* argv[]);

std::string EliminateComments(std::ifstream& file);
