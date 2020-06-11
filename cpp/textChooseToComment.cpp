#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::cout;

int main(int argc, char* argv[]) {
  std::fstream input("plikiTekstowe/input.cpp", std::fstream::in);
  std::fstream output("plikiTekstowe/output.cpp", std::fstream::out);

  if (!input) {
    std::cerr << "Error: no input file\n";
    return 1;
  }
  if (!output) {
    std::cerr << "Error: could not create output file\n";
    return 1;
  }

  std::vector<std::string> text{};
  std::string line{};
  int lineNumber{1};
  while (std::getline(input, line)) {
    cout << std::setw(10) << std::left << lineNumber << line << "\n";
    text.emplace_back(line);
    lineNumber++;
  }
  cout << std::endl;
  int chosenLine{};
  while (true) {
    cout << "Which line should be commented?: \n";
    std::cin >> chosenLine;
    if (std::cin && chosenLine > 0 && chosenLine <= text.size()) {
      text.at(chosenLine - 1) = "// " + text.at(chosenLine - 1);
      cout << "Line " << chosenLine << " commented\n\n";
    } else if (chosenLine == 0)
      break;
    else
      cout << "Line number should be from range 1:" << text.size() - 1
           << " or 0 to exit\n";
  }

  for (const auto& t : text) {
    output << t << "\n";
  }
  input.close();
  output.close();
}